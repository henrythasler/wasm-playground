#include "function.hpp"

namespace tiny {

std::string WasmFunction::joinValTypes(const std::vector<webassembly_t::val_types_t> &valTypes) {
  std::string resultString;
  int32_t idx = 0;

  if (valTypes.size() == 0) {
    return "void";
  }

  for (auto valType : valTypes) {
    if (idx > 0) {
      resultString += ", ";
    }
    switch (valType) {
    case webassembly_t::VAL_TYPES_I32:
      resultString += "i32";
      break;
    case webassembly_t::VAL_TYPES_I64:
      resultString += "i64";
      break;
    case webassembly_t::VAL_TYPES_F32:
      resultString += "f32";
      break;
    case webassembly_t::VAL_TYPES_F64:
      resultString += "f64";
      break;
    default:
      break;
    }
    idx++;
  }
  return resultString;
}

size_t WasmFunction::compile(const webassembly_t::func_t *func, const std::unique_ptr<webassembly_t::functype_t> &funcType) {
  /**
   * this values stores the size required on the stack to store all parameters and locals
   */
  uint16_t initialStackSize = 0;
  assembler::Locals locals;
  assembler::RegisterPool registerPool;
  std::vector<arm64::reg_t> registerStack;

  /**
   * calculate the
   */
  auto parameterTypes = *funcType->parameters()->valtype();
  for (auto valtype : parameterTypes) {
    switch (valtype) {
    case webassembly_t::VAL_TYPES_I32:
      initialStackSize += 4;
      break;
    case webassembly_t::VAL_TYPES_I64:
      initialStackSize += 8;
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
      break;
    }
    parameters.push_back(valtype);
  }

  auto resultTypes = *funcType->results()->valtype();
  for (auto valtype : resultTypes) {
    results.push_back(valtype);
  }

  /**
   * reserve additional space for locals
   */
  for (auto &local : *func->locals()) {
    switch (local->valtype()) {
    case webassembly_t::VAL_TYPES_I32:
      initialStackSize += uint16_t(4 * local->num_valtype()->value());
      break;
    case webassembly_t::VAL_TYPES_I64:
      initialStackSize += uint16_t(8 * local->num_valtype()->value());
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
      break;
    }
  }

  machinecode.clear();

  // Prologue: create a new stack frame (stp fp, lr, [sp, #-16]!)
  machinecode.push_back(0xA9BF7BFD);
  // mov fp, sp
  machinecode.push_back(arm64::encode_mov_sp(arm64::FP, arm64::SP, arm64::reg_size_t::SIZE_64BIT));

  // Allocate stack
  if (initialStackSize > 0) {
    initialStackSize = uint16_t(((initialStackSize + (AARCH64_STACK_ALIGNMENT - 1)) / AARCH64_STACK_ALIGNMENT) * AARCH64_STACK_ALIGNMENT);
    machinecode.push_back(arm64::encode_sub_immediate(arm64::SP, arm64::SP, initialStackSize, false, arm64::reg_size_t::SIZE_64BIT));
  }

  // save parameters to stack
  uint16_t stackPosition = initialStackSize;
  uint8_t paramRegister = 0;
  for (auto parameter : parameters) {
    // std::cout << "parameter stackPosition " << stackPosition << " ";
    asserte(paramRegister < 8, "too many parameters to fit into registers; use stack");
    switch (parameter) {
    case webassembly_t::VAL_TYPES_I32:
      machinecode.push_back(
          arm64::encode_str_unsigned_offset(arm64::reg_t(paramRegister++), arm64::SP, stackPosition, arm64::reg_size_t::SIZE_32BIT));
      locals.append(stackPosition, parameter);
      stackPosition -= AARCH64_INT32_SIZE;
      break;
    case webassembly_t::VAL_TYPES_I64:
      machinecode.push_back(
          arm64::encode_str_unsigned_offset(arm64::reg_t(paramRegister++), arm64::SP, stackPosition, arm64::reg_size_t::SIZE_64BIT));
      locals.append(stackPosition, parameter);
      stackPosition -= AARCH64_INT64_SIZE;
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
    }
  }

  for (auto &local : *func->locals()) {
    // std::cout << "local stackPosition " << stackPosition << " ";
    switch (local->valtype()) {
    case webassembly_t::VAL_TYPES_I32:
      for (auto i = 0; i < local->num_valtype()->value(); i++) {
        machinecode.push_back(arm64::encode_str_unsigned_offset(arm64::reg_t::WZR, arm64::SP, stackPosition, arm64::reg_size_t::SIZE_32BIT));
        locals.append(stackPosition, local->valtype());
        stackPosition -= AARCH64_INT32_SIZE;
      }
      break;
    case webassembly_t::VAL_TYPES_I64:
      for (auto i = 0; i < local->num_valtype()->value(); i++) {
        machinecode.push_back(arm64::encode_str_unsigned_offset(arm64::reg_t::WZR, arm64::SP, stackPosition, arm64::reg_size_t::SIZE_64BIT));
        locals.append(stackPosition, local->valtype());
        stackPosition -= AARCH64_INT64_SIZE;
      }
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
      break;
    }
  }

  // Business logic
  if (func->expr().size() > 0) {
    std::istringstream exprStream(func->expr());
    auto expr = assembler::assembleExpression(exprStream, locals, registerPool, registerStack);
    machinecode.insert(machinecode.end(), expr.begin(), expr.end());
  }

  if (results.size() > 0) {
    auto sourceReg = registerStack.back();
    switch (results.back()) {
    case webassembly_t::val_types_t::VAL_TYPES_I32: {
      machinecode.push_back(arm64::encode_mov_register(arm64::W0, sourceReg, arm64::reg_size_t::SIZE_32BIT));
      break;
    }
    case webassembly_t::val_types_t::VAL_TYPES_I64: {
      machinecode.push_back(arm64::encode_mov_register(arm64::X0, sourceReg, arm64::reg_size_t::SIZE_64BIT));
      break;
    }
    default:
      asserte(false, "function result: unsupported type");
      break;
    }
  }

  // deallocate stack memory (add sp, sp, #initialStackSize)
  if (initialStackSize > 0) {
    machinecode.push_back(arm64::encode_add_immediate(arm64::SP, arm64::SP, initialStackSize, false, arm64::reg_size_t::SIZE_64BIT));
  }

  // Epilogue: destroy stack frame (ldp fp, lr, [sp], #16)
  machinecode.push_back(0xA8C17BFD);

  // return (RET)
  machinecode.push_back(arm64::encode_ret());

  return machinecode.size();
}
} // namespace tiny