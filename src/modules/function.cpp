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
  // stack size allocated for this function; value may change during compilation
  uint32_t stackSize = 0;
  // set of local variables
  assembler::Variables variables;
  // available registers to hold wasmStack values; can be extended with spilling to memory
  assembler::RegisterPool registerPool;
  // WebAssembly stack; currently only registers are used to hold values
  std::vector<arm64::reg_t> wasmStack;
  // this keeps track of the current position in the stack frame relative to fp
  uint32_t stackPosition = 0;

  // evaluate parameters to determine initial stack size
  auto parameterTypes = *funcType->parameters()->valtype();
  for (auto valtype : parameterTypes) {
    stackSize += assembler::mapWasmValTypeToArm64Size(valtype);
    parameters.push_back(valtype);
  }

  // copy result types into new vector for easier access later
  auto resultTypes = *funcType->results()->valtype();
  for (auto valtype : resultTypes) {
    results.push_back(valtype);
  }

  // reserve additional space for local variables on the stack
  for (auto &local : *func->locals()) {
    locals[local->valtype()] = uint32_t(local->num_valtype()->value());
    stackSize += assembler::mapWasmValTypeToArm64Size(local->valtype()) * uint32_t(local->num_valtype()->value());
  }

  machinecode.clear();

  // Prologue: create a new stack frame (stp fp, lr, [sp, #-16]!)
  machinecode.push_back(0xA9BF7BFD);
  // mov fp, sp
  machinecode.push_back(arm64::encode_mov_sp(arm64::FP, arm64::SP, arm64::reg_size_t::SIZE_64BIT));

  // Allocate stack
  if (stackSize > 0) {
    stackSize = ((stackSize + (AARCH64_STACK_ALIGNMENT - 1)) / AARCH64_STACK_ALIGNMENT) * AARCH64_STACK_ALIGNMENT;
    asserte(stackSize % AARCH64_STACK_ALIGNMENT == 0, "stack size not aligned properly");
    asserte(stackSize < 65536, "stack size too large to encode in a single instruction");
    machinecode.push_back(arm64::encode_sub_immediate(arm64::SP, arm64::SP, uint16_t(stackSize), false, arm64::reg_size_t::SIZE_64BIT));
  }

  // arm64 stack is full descending; that means we start allocating from the top (higher addresses) and grow downwards (lower addresses)
  stackPosition = stackSize;

  // save parameters to stack
  if (parameters.size() > 0) {
    // all parameters are the first n locals
    auto paramBlock = assembler::saveParametersToStack(parameters, stackPosition, variables);
    machinecode.insert(machinecode.end(), paramBlock.begin(), paramBlock.end());
  }

  // initialize locals on stack
  if (locals.size() > 0) {
    auto localBlock = assembler::initLocals(locals, stackPosition, variables);
    machinecode.insert(machinecode.end(), localBlock.begin(), localBlock.end());
  }

  // Business logic
  if (func->expr().size() > 0) {
    auto exprStr = func->expr();
    std::vector<uint8_t> expr(exprStr.begin(), exprStr.end());
    auto it = expr.cbegin();
    auto block = assembler::assembleExpression(it, expr.end(), variables, registerPool, wasmStack);
    machinecode.insert(machinecode.end(), block.begin(), block.end());
  }

  if (results.size() > 0) {
    auto resultBlock = assembler::loadResult(results, wasmStack);
    machinecode.insert(machinecode.end(), resultBlock.begin(), resultBlock.end());
  }

  // deallocate stack memory (add sp, sp, #stackSize)
  if (stackSize > 0) {
    machinecode.push_back(arm64::encode_add_immediate(arm64::SP, arm64::SP, uint16_t(stackSize), false, arm64::reg_size_t::SIZE_64BIT));
  }

  // Epilogue: destroy stack frame (ldp fp, lr, [sp], #16)
  machinecode.push_back(0xA8C17BFD);

  // return (RET)
  machinecode.push_back(arm64::encode_ret());

  return machinecode.size();
}
} // namespace tiny