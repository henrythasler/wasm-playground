#include "module.hpp"

namespace tiny {
/**
 * As we are cross-compiling to arm64 the byteorder is litte endian anyways.
 */
void WasmFunction::serializeUint32LE(uint32_t value) {
  bytecode.push_back(uint8_t(value & 0xFF));
  bytecode.push_back(uint8_t((value >> 8) & 0xFF));
  bytecode.push_back(uint8_t((value >> 16) & 0xFF));
  bytecode.push_back(uint8_t((value >> 24) & 0xFF));
}

std::string WasmFunction::joinValTypes(const std::vector<webassembly_t::val_types_t> &valTypes) {
  std::string resultString;
  int32_t idx = 0;

  if (valTypes.size() == 0) {
    return "void";
  }

  for (auto valType : valTypes) {
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
    if (idx > 0) {
      resultString += ", ";
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
  Locals locals;

  /**
   * calculate the
   */
  auto valtypes = *funcType->parameters()->valtype();
  for (auto valtype : valtypes) {
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

  valtypes = *funcType->results()->valtype();
  for (auto valtype : valtypes) {
    results.push_back(valtype);
  }

  /**
   * reserve additional space for locals
   */
  for (auto &local : *func->locals()) {
    switch (local->valtype()) {
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
  }

  bytecode.clear();

  // Prologue: create a new stack frame (stp fp, lr, [sp, #-16]!)
  serializeUint32LE(0xA9BF7BFD);
  // mov fp, sp
  serializeUint32LE(arm64::encode_mov_sp(arm64::FP, arm64::SP, arm64::size2_t::SIZE_64BIT));

  // Allocate stack
  initialStackSize = uint16_t(((initialStackSize + (AARCH64_STACK_ALIGNMENT - 1)) / AARCH64_STACK_ALIGNMENT) * AARCH64_STACK_ALIGNMENT);
  serializeUint32LE(arm64::encode_sub_immediate(arm64::SP, arm64::SP, initialStackSize, false, arm64::size2_t::SIZE_64BIT));

  // save parameters to stack
  uint16_t stackPosition = initialStackSize;
  uint8_t paramRegister = 0;
  for (auto parameter : parameters) {
    std::cout << stackPosition << " ";
    asserte(paramRegister < 8, "too many parameters to fit into registers; use stack");
    switch (parameter) {
    case webassembly_t::VAL_TYPES_I32:
      serializeUint32LE(arm64::encode_str_immediate(arm64::reg_t(paramRegister++), arm64::SP, stackPosition, arm64::size4_t::SIZE_32BIT));
      locals.append(stackPosition);
      stackPosition -= AARCH64_INT32_SIZE;
      break;
    case webassembly_t::VAL_TYPES_I64:
      serializeUint32LE(arm64::encode_str_immediate(arm64::reg_t(paramRegister++), arm64::SP, stackPosition, arm64::size4_t::SIZE_64BIT));
      locals.append(stackPosition);
      stackPosition -= AARCH64_INT64_SIZE;
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
    }
  }

  // FIXME: create local variables on stack
  for (auto &local : *func->locals()) {
    // std::cout << stackPosition << " ";
    switch (local->valtype()) {
    case webassembly_t::VAL_TYPES_I32:
      serializeUint32LE(arm64::encode_str_immediate(arm64::reg_t::WZR, arm64::SP, stackPosition, arm64::size4_t::SIZE_32BIT));
      locals.append(stackPosition);
      stackPosition -= AARCH64_INT32_SIZE;
      break;
    case webassembly_t::VAL_TYPES_I64:
      serializeUint32LE(arm64::encode_str_immediate(arm64::reg_t::WZR, arm64::SP, stackPosition, arm64::size4_t::SIZE_64BIT));
      locals.append(stackPosition);
      stackPosition -= AARCH64_INT64_SIZE;
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
      break;
    }
  }

  std::cout << std::endl;

  // Business logic
  if (func->expr().size() > 0) {
    std::istringstream stream(func->expr());
    char byte;
    while (stream.get(byte)) {
      switch (byte) {
      case 0x20:
        stream.get(byte);
        // std::cout << locals.get(byte) << " ";
        // std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        serializeUint32LE(arm64::encode_ldr_offset(arm64::reg_t::X0, arm64::SP, uint16_t(locals.get(byte)), arm64::size2_t::SIZE_64BIT));
        break;
      default:
        break;
      }
    }
  }

  // deallocate stack memory (add sp, sp, #initialStackSize)
  serializeUint32LE(arm64::encode_add_immediate(arm64::SP, arm64::SP, initialStackSize, false, arm64::size2_t::SIZE_64BIT));

  // Epilogue: destroy stack frame (ldp fp, lr, [sp], #16)
  serializeUint32LE(0xA8C17BFD);

  // return (RET)
  serializeUint32LE(arm64::encode_ret());

  return bytecode.size();
}
} // namespace tiny