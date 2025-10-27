#include "function.hpp"
#include "leb128.hpp"

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
  Locals locals;
  RegisterPool registerPool;
  std::vector<arm64::reg_t> registerStack;

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

  bytecode.clear();

  // Prologue: create a new stack frame (stp fp, lr, [sp, #-16]!)
  serializeUint32LE(0xA9BF7BFD);
  // mov fp, sp
  serializeUint32LE(arm64::encode_mov_sp(arm64::FP, arm64::SP, arm64::reg_size_t::SIZE_64BIT));

  // Allocate stack
  initialStackSize = uint16_t(((initialStackSize + (AARCH64_STACK_ALIGNMENT - 1)) / AARCH64_STACK_ALIGNMENT) * AARCH64_STACK_ALIGNMENT);
  serializeUint32LE(arm64::encode_sub_immediate(arm64::SP, arm64::SP, initialStackSize, false, arm64::reg_size_t::SIZE_64BIT));

  // save parameters to stack
  uint16_t stackPosition = initialStackSize;
  uint8_t paramRegister = 0;
  for (auto parameter : parameters) {
    // std::cout << "parameter stackPosition " << stackPosition << " ";
    asserte(paramRegister < 8, "too many parameters to fit into registers; use stack");
    switch (parameter) {
    case webassembly_t::VAL_TYPES_I32:
      serializeUint32LE(arm64::encode_str_unsigned_offset(arm64::reg_t(paramRegister++), arm64::SP, stackPosition, arm64::reg_size_t::SIZE_32BIT));
      locals.append(stackPosition, parameter);
      stackPosition -= AARCH64_INT32_SIZE;
      break;
    case webassembly_t::VAL_TYPES_I64:
      serializeUint32LE(arm64::encode_str_unsigned_offset(arm64::reg_t(paramRegister++), arm64::SP, stackPosition, arm64::reg_size_t::SIZE_64BIT));
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
        serializeUint32LE(arm64::encode_str_unsigned_offset(arm64::reg_t::WZR, arm64::SP, stackPosition, arm64::reg_size_t::SIZE_32BIT));
        locals.append(stackPosition, local->valtype());
        stackPosition -= AARCH64_INT32_SIZE;
      }
      break;
    case webassembly_t::VAL_TYPES_I64:
      for (auto i = 0; i < local->num_valtype()->value(); i++) {
        serializeUint32LE(arm64::encode_str_unsigned_offset(arm64::reg_t::WZR, arm64::SP, stackPosition, arm64::reg_size_t::SIZE_64BIT));
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
    std::istringstream stream(func->expr());
    char byte;
    while (stream.get(byte)) {
      switch (byte) {
      case 0x20:
        /**
         * local.get localidx:u32
         * allocates one register
         */
        {
          auto reg = registerPool.allocateRegister();
          registerStack.emplace_back(reg);
          auto idx = uint32_t(LEB128Decoder::decodeUnsigned(stream));

          switch (locals.getType(idx)) {
          case webassembly_t::VAL_TYPES_I32: {
            serializeUint32LE(arm64::encode_ldr_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), arm64::reg_size_t::SIZE_32BIT));
            break;
          }
          case webassembly_t::VAL_TYPES_I64: {
            serializeUint32LE(arm64::encode_ldr_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), arm64::reg_size_t::SIZE_64BIT));
            break;
          }
          default:
            break;
          }
          break;
        }
      case 0x21:
        /**
         * local.set localidx:u32
         */
        {
          auto reg = registerStack.back();
          auto idx = uint32_t(LEB128Decoder::decodeUnsigned(stream));

          switch (locals.getType(idx)) {
          case webassembly_t::VAL_TYPES_I32: {
            serializeUint32LE(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), arm64::reg_size_t::SIZE_32BIT));
            break;
          }
          case webassembly_t::VAL_TYPES_I64: {
            serializeUint32LE(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), arm64::reg_size_t::SIZE_64BIT));
            break;
          }
          default:
            break;
          }

          registerPool.freeRegister(reg);
          registerStack.pop_back();
          break;
        }
      case 0x41:
        /**
         * i32.const n:i32
         */
        {
          // FIXME: unify with i64.const and move to separate function
          auto reg = registerPool.allocateRegister();
          registerStack.emplace_back(reg);
          auto constValue = LEB128Decoder::decodeSigned(stream); // n

          // int32 has at most 2 16-bit chunks
          serializeUint32LE(arm64::encode_mov_immediate(reg, uint16_t(constValue & 0xFFFF), 0, arm64::reg_size_t::SIZE_32BIT));
          if ((constValue >> 16) & 0xFFFF) {
            serializeUint32LE(arm64::encode_movk(reg, uint16_t((constValue >> 16) & 0xFFFF), 16, arm64::reg_size_t::SIZE_32BIT));
          }
          break;
        }
      case 0x42:
        /**
         * i64.const n:i64
         */
        {
          auto reg = registerPool.allocateRegister();
          registerStack.emplace_back(reg);
          auto constValue = LEB128Decoder::decodeSigned(stream); // n

          // int64 has at most 4 16-bit chunks
          for (uint8_t i = 0; i < 4; i++) {
            uint16_t chunk = uint16_t((constValue >> (i << 4)) & 0xFFFF);
            if (i == 0) {
              serializeUint32LE(arm64::encode_mov_immediate(reg, chunk, 0, arm64::reg_size_t::SIZE_64BIT));
            } else if (chunk != 0) {
              serializeUint32LE(arm64::encode_movk(reg, chunk, i << 4, arm64::reg_size_t::SIZE_64BIT));
            }
          }
          break;
        }
      default:
        break;
      }
    }
  }

  // FIXME: move topmost stack element to X0 if there is a return value

  // deallocate stack memory (add sp, sp, #initialStackSize)
  serializeUint32LE(arm64::encode_add_immediate(arm64::SP, arm64::SP, initialStackSize, false, arm64::reg_size_t::SIZE_64BIT));

  // Epilogue: destroy stack frame (ldp fp, lr, [sp], #16)
  serializeUint32LE(0xA8C17BFD);

  // return (RET)
  serializeUint32LE(arm64::encode_ret());

  return bytecode.size();
}
} // namespace tiny