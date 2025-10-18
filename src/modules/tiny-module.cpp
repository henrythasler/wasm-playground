#include "tiny-module.hpp"

namespace tiny {
/**
 * As we are cross-compiling to arm64 the byteorder is litte endian anyways.
 */
void WasmFunction::serializeUint32(uint32_t value) {
  bytecode.push_back(uint8_t((value >> 24) & 0xFF));
  bytecode.push_back(uint8_t((value >> 16) & 0xFF));
  bytecode.push_back(uint8_t((value >> 8) & 0xFF));
  bytecode.push_back(uint8_t(value & 0xFF));
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
  auto valtypes = *funcType->parameters()->valtype();
  for (auto valtype : valtypes) {
    parameters.push_back(valtype);
  }

  valtypes = *funcType->results()->valtype();
  for (auto valtype : valtypes) {
    results.push_back(valtype);
  }

  bytecode.clear();

  // Prologue: create a new stack frame
  serializeUint32(0xFD7BBFA9);
  serializeUint32(0xFD030091);

  // Allocate 64 bytes on stack
  // FIXME: allocate based on parameters and locals
  serializeUint32(0xFF0301D1);

  // FIXME: save parameters to stack
  int32_t param_idx = 0;
  for (auto parameter : parameters) {
  }

  // FIXME: create local variables on stack

  // Business logic
  if (func->expr().size() > 0) {
  }

  // deallocate stack memory
  serializeUint32(0xFF030191);

  // Epilogue: destroy stack frame
  serializeUint32(0xFD7BC1A8);

  // return
  serializeUint32(0xC0035FD6);

  return bytecode.size();
}
} // namespace tiny