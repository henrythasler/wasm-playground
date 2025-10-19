#include "instructions.hpp"
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
  serializeUint32LE(0x910003FD);

  // Allocate stack
  initialStackSize = uint16_t(((initialStackSize >> 4) + 1) << 4);
  serializeUint32LE(encode_sub_immediate(SP, SP, initialStackSize, false, size2_t::SIZE_64BIT));

  // save parameters to stack
  uint16_t stackPosition = initialStackSize;
  for (auto parameter : parameters) {
    switch (parameter) {
    case webassembly_t::VAL_TYPES_I32:
      serializeUint32LE(encode_str_immediate(W0, SP, stackPosition, size4_t::SIZE_32BIT));
      stackPosition -= 4;
      break;
    case webassembly_t::VAL_TYPES_I64:
      serializeUint32LE(encode_str_immediate(W0, SP, stackPosition, size4_t::SIZE_64BIT));
      stackPosition -= 8;
      break;
    default:
      asserte(false, "WasmFunction::compile(): unsupported parameter type (val_types_t)");
    }

    /**
     *  store the
     *  str     x0, [sp, 24]
     *           |        L Stack pointer offset
     *        register
     *  0xf9000fe0
     *  11 111001000 00000000011 11111 00000
     *                             |     L source register (Rt, 0=x0)
     *                             L base register (Rn)
     *
     *  str     x1, [sp, 16]
     *  11 111 001000 00000000010 11111 00001
     *
     */
  }

  // FIXME: create local variables on stack

  // Business logic
  if (func->expr().size() > 0) {
  }

  // deallocate stack memory (add sp, sp, #initialStackSize)
  serializeUint32LE(encode_add_immediate(SP, SP, initialStackSize, false, size2_t::SIZE_64BIT));

  // Epilogue: destroy stack frame (ldp fp, lr, [sp], #16)
  serializeUint32LE(0xA8C17BFD);

  // return (RET)
  serializeUint32LE(0xD65F03C0);

  return bytecode.size();
}
} // namespace tiny