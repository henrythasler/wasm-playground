#include "assembler.hpp"

namespace assembler {
arm64::reg_size_t map_valtype_to_regsize(const webassembly_t::val_types_t type) {
  switch (type) {
  case webassembly_t::VAL_TYPES_I32:
    return arm64::reg_size_t::SIZE_32BIT;
  case webassembly_t::VAL_TYPES_I64:
    return arm64::reg_size_t::SIZE_64BIT;
  default:
    asserte(false, "Unsupported value type for register size mapping");
    return arm64::reg_size_t::SIZE_32BIT; // To suppress compiler warning
  }
}

std::vector<uint32_t> assembleExpression(std::istringstream &stream, Locals &locals, RegisterPool &registerPool, std::vector<arm64::reg_t> &stack) {
  std::vector<uint32_t> machinecode;
  char wasmSymbol;
  while (stream.get(wasmSymbol)) {
    switch (wasmSymbol) {
    case 0x20:
      /**
       * local.get localidx:u32
       * allocates one register
       */
      {
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream));
        auto registerSize = assembler::map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_ldr_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        break;
      }
    case 0x21:
      /**
       * local.set localidx:u32
       */
      {
        auto reg = stack.back();
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream));
        auto registerSize = assembler::map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        // remove register from stack and mark it as free
        stack.pop_back();
        registerPool.freeRegister(reg);
        break;
      }
    case 0x22:
      /**
       * local.tee localidx:u32
       */
      {
        auto reg = stack.back();
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream));
        auto registerSize = assembler::map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        break;
      }
    case 0x6A:
    case 0x7c:
      /**
       * (i32|i64).add
       */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for add");

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        if (wasmSymbol == 0x6A) {
          machinecode.push_back(arm64::encode_add_register(reg1, reg1, reg2, 0, arm64::reg_shift_t::SHIFT_LSL, arm64::reg_size_t::SIZE_32BIT));
        } else {
          machinecode.push_back(arm64::encode_add_register(reg1, reg1, reg2, 0, arm64::reg_shift_t::SHIFT_LSL, arm64::reg_size_t::SIZE_64BIT));
        }

        stack.pop_back();
        registerPool.freeRegister(reg2);
        break;
      }
    case 0x6B:
    case 0x7D:
      /**
       * (i32|i64).sub
       */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for sub");

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        if (wasmSymbol == 0x6B) {
          machinecode.push_back(arm64::encode_sub_register(reg1, reg1, reg2, 0, arm64::reg_shift_t::SHIFT_LSL, arm64::reg_size_t::SIZE_32BIT));
        } else {
          machinecode.push_back(arm64::encode_sub_register(reg1, reg1, reg2, 0, arm64::reg_shift_t::SHIFT_LSL, arm64::reg_size_t::SIZE_64BIT));
        }

        stack.pop_back();
        registerPool.freeRegister(reg2);
        break;
      }
    case 0x6C:
    case 0x7E:
      /**
       * (i32|i64).mul
       */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for mul");

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        if (wasmSymbol == 0x6C) {
          machinecode.push_back(arm64::encode_mul_register(reg1, reg1, reg2, arm64::reg_size_t::SIZE_32BIT));
        } else {
          machinecode.push_back(arm64::encode_mul_register(reg1, reg1, reg2, arm64::reg_size_t::SIZE_64BIT));
        }

        stack.pop_back();
        registerPool.freeRegister(reg2);
        break;
      }
    case 0x41:
    case 0x42:
      /**
       * i32.const n:i32
       * i64.const n:i64
       */
      {
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);
        auto constValue = decoder::LEB128Decoder::decodeSigned(stream); // n
        auto registerSize = (wasmSymbol == 0x41) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;

        for (uint8_t i = 0; i < 4; i++) {
          uint16_t chunk = uint16_t((constValue >> (i << 4)) & 0xFFFF);
          if (i == 0) {
            machinecode.push_back(arm64::encode_mov_immediate(reg, chunk, 0, registerSize));
          } else if (chunk != 0) {
            machinecode.push_back(arm64::encode_movk(reg, chunk, i << 4, registerSize));
          }
        }
        break;
      }
    case 0x0b:
      /**
       * ret
       */
      return machinecode;
    default:
      // asserte(false, "unsupported instruction: " + std::to_string(int32_t(wasmSymbol)));
      std::cout << "unsupported instruction: 0x" << std::hex << std::setw(2) << std::setfill('0') << int32_t(wasmSymbol) << " " << std::endl;
      break;
    }
  }
  return machinecode;
}
} // namespace assembler