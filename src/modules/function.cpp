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

size_t WasmFunction::compile(const webassembly_t::func_t *func, const std::unique_ptr<webassembly_t::functype_t> &funcType,
                             webassembly_t::type_section_t *type_section, webassembly_t::function_section_t *function_section,
                             std::unique_ptr<assembler::Globals> &globals, const std::map<wasm::trap_code_t, int32_t> &trapHandler,
                             std::unique_ptr<assembler::FunctionTable> &functionTable, std::vector<uint32_t> &machinecode) {
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

  // control flow stack
  std::vector<assembler::ControlBlock> controlStack;

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

  machinecodeOffset = machinecode.size();

  // create aligned stack and preamble (stack frame)
  stackSize = assembler::createPreamble(stackSize, trapHandler, machinecode);

  // arm64 stack is full descending; that means we start allocating from the top (higher addresses) and grow downwards (lower addresses)
  stackPosition = stackSize;

  // save parameters to stack
  if (parameters.size() > 0) {
    // all parameters are the first n locals
    stackPosition = assembler::saveParametersToStack(parameters, stackPosition, variables, machinecode);
  }

  // initialize locals on stack
  if (locals.size() > 0) {
    stackPosition = assembler::initLocals(locals, stackPosition, variables, machinecode);
  }

  // Business logic
  if (func->expr().size() > 0) {
    auto exprStr = func->expr();
    std::vector<uint8_t> expr(exprStr.begin(), exprStr.end());
    auto it = expr.cbegin();
    auto result_type = (results.size() > 0) ? results.back() : webassembly_t::val_types_t(0);
    controlStack.push_back(assembler::ControlBlock{assembler::ControlBlock::Type::FUNCTION, {}, registerPool, wasmStack, result_type});
    assembler::assembleExpression(it, expr.end(), variables, registerPool, controlStack, wasmStack, trapHandler, functionCallPatches,
                                  loadAddressPatches, type_section, function_section, globals, functionTable, machinecode);
    asserte(controlStack.size() == 0, "control stack should be empty but has: " + std::to_string(controlStack.size()));
  }

  if (results.size() > 0) {
    assembler::loadResult(results, wasmStack, machinecode);
  }

  assembler::createEpilogue(stackSize, machinecode);

  machinecodeSize = machinecode.size() - machinecodeOffset;
  return machinecodeSize;
}
} // namespace tiny