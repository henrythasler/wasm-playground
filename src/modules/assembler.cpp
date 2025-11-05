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

uint32_t mapWasmValTypeToArm64Size(webassembly_t::val_types_t valType) {
  switch (valType) {
  case webassembly_t::VAL_TYPES_I32:
    return AARCH64_INT32_SIZE;
  case webassembly_t::VAL_TYPES_I64:
    return AARCH64_INT64_SIZE;
  default:
    asserte(false, "WasmFunction::mapWasmValTypeToArm64Size(): unsupported val_types_t");
    return 0;
  }
}

uint32_t saveParametersToStack(const std::vector<webassembly_t::val_types_t> &parameters, uint32_t offset, assembler::Variables &variables,
                               std::vector<uint32_t> &machinecode) {
  uint8_t paramRegister = 0;
  for (auto parameter : parameters) {
    auto registerSize = map_valtype_to_regsize(parameter);

    machinecode.push_back(arm64::encode_str_unsigned_offset(arm64::reg_t(paramRegister), arm64::SP, uint16_t(offset), registerSize));
    variables.append(offset, parameter);
    offset -= mapWasmValTypeToArm64Size(parameter);

    paramRegister++;
  }
  return offset;
}

uint32_t initLocals(const std::map<webassembly_t::val_types_t, uint32_t> &locals, uint32_t offset, assembler::Variables &variables,
                    std::vector<uint32_t> &machinecode) {
  for (auto local : locals) {
    auto registerSize = map_valtype_to_regsize(local.first);
    for (uint32_t i = 0; i < local.second; i++) {
      auto sourceReg = (registerSize == arm64::reg_size_t::SIZE_32BIT) ? arm64::reg_t::WZR : arm64::reg_t::XZR;
      machinecode.push_back(arm64::encode_str_unsigned_offset(sourceReg, arm64::SP, uint16_t(offset), registerSize));
      variables.append(offset, local.first);
      offset -= mapWasmValTypeToArm64Size(local.first);
    }
  }
  return offset;
}

void loadResult(const std::vector<webassembly_t::val_types_t> &results, const std::vector<arm64::reg_t> &wasmStack,
                std::vector<uint32_t> &machinecode) {
  auto registerSize = map_valtype_to_regsize(results.back());
  auto sourceReg = wasmStack.back();
  auto targetReg = (registerSize == arm64::reg_size_t::SIZE_32BIT) ? arm64::reg_t::W0 : arm64::reg_t::X0;
  machinecode.push_back(arm64::encode_mov_register(targetReg, sourceReg, registerSize));
}

uint32_t createPreamble(uint32_t stackSize, std::vector<uint32_t> &machinecode) {
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
  return stackSize;
}

void createEpilogue(const uint32_t stackSize, std::vector<uint32_t> &machinecode) {
  if (stackSize > 0) {
    // deallocate stack memory (add sp, sp, #stackSize)
    machinecode.push_back(arm64::encode_add_immediate(arm64::SP, arm64::SP, uint16_t(stackSize), false, arm64::reg_size_t::SIZE_64BIT));
  }
  // Epilogue: destroy stack frame (ldp fp, lr, [sp], #16)
  machinecode.push_back(0xA8C17BFD);
  // return (RET)
  machinecode.push_back(arm64::encode_ret());
}

void printStack(const std::vector<arm64::reg_t> &stack) {
  std::cout << "Stack (top -> bottom): ";
  for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
    std::cout << (*it) << " ";
  }
  std::cout << std::endl;
}

/**
 * Assemble a WebAssembly expression (aka bytecode) into ARM64 machine code.
 */
std::vector<uint32_t> assembleExpression(std::vector<uint8_t>::const_iterator &stream, std::vector<uint8_t>::const_iterator streamEnd,
                                         Variables &locals, RegisterPool &registerPool, std::vector<arm64::reg_t> &stack) {
  std::vector<uint32_t> machinecode;
  while (stream != streamEnd) {
    switch (*stream++) {
    case 0x20:
      /** local.get localidx:u32 */
      {
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto registerSize = map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_ldr_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        break;
      }
    case 0x21:
      /** local.set localidx:u32 */
      {
        auto reg = stack.back();
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto registerSize = map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        // remove register from stack and mark it as free
        stack.pop_back();
        registerPool.freeRegister(reg);
        break;
      }
    case 0x22:
      /** local.tee localidx:u32 */
      {
        auto reg = stack.back();
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto registerSize = map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        break;
      }
    case 0x6A:
    case 0x7c:
      /** (i32|i64).add */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for add");

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        if (*(stream - 1) == 0x6A) {
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
      /** (i32|i64).sub */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for sub");

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        if (*(stream - 1) == 0x6B) {
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
      /** (i32|i64).mul */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for mul");

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        if (*(stream - 1) == 0x6C) {
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
      /** (i32|i64).const n:(i32|i64) */
      {
        auto registerSize = (*(stream - 1) == 0x41) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);
        auto constValue = decoder::LEB128Decoder::decodeSigned(stream, streamEnd); // n
        printStack(stack);

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
    case 0x48:
    case 0x53:
      /** (i32|i64).lt_s */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for lt_s");
        auto registerSize = (*(stream - 1) == 0x48) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        machinecode.push_back(arm64::encode_cmp_shifted_register(reg1, reg2, arm64::reg_shift_t::SHIFT_LSL, 0, registerSize));

        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::LT, 3 * 4));
        // // load 0
        machinecode.push_back(arm64::encode_mov_immediate(reg1, 0, 0, arm64::reg_size_t::SIZE_32BIT));
        machinecode.push_back(arm64::encode_branch(2 * 4));
        // // load 1
        machinecode.push_back(arm64::encode_mov_immediate(reg1, 1, 0, arm64::reg_size_t::SIZE_32BIT));

        stack.pop_back();
        registerPool.freeRegister(reg2);

        break;
      }
    case 0x04:
      /** if */
      {
        auto reg = stack.back();
        // remove register from stack and mark it as free; make sure to assemble the block so that this register is used before other blocks
        stack.pop_back();
        registerPool.freeRegister(reg);

        auto rawBlocktype = *stream++;
        auto blocktype = (rawBlocktype == 0x40) ? webassembly_t::val_types_t(0) : webassembly_t::val_types_t(rawBlocktype);

        // need an independent copy of the register pool for else branch
        RegisterPool elseRegisterPool(registerPool);
        // and a copy of the stack for the conditional block
        std::vector<arm64::reg_t> elseStack = stack;

        auto block = assembleExpression(stream, streamEnd, locals, registerPool, stack);

        std::vector<uint32_t> block2;
        if (*(stream - 1) == 0x05) {
          block2 = assembleExpression(stream, streamEnd, locals, elseRegisterPool, elseStack);
          // verify that stack sizes and registers match after else-block
          asserte(stack.size() == elseStack.size(), "stack size mismatch after else-block");
          if (stack.size() > 0 && elseStack.size() > 0) {
            asserte(stack.back() == elseStack.back(), "stack register mismatch after else-block");
          }
        }

        if (blocktype != 0) {
          // maybe do something here
        }

        // insert cbz to jump over if block if condition is false (zero)
        // include the size of the cbz instruction itself (4 bytes) and the jump instruction after the if block (4 bytes)
        machinecode.push_back(arm64::encode_cbz(reg, int32_t(block.size() + 2) << 2, arm64::reg_size_t::SIZE_32BIT));
        machinecode.insert(machinecode.end(), block.begin(), block.end());

        // handle else block if present
        if (block2.size() > 0) {
          // jump over else block after if block
          machinecode.push_back(arm64::encode_branch(int32_t(block2.size() + 1) << 2));
          // insert else block
          machinecode.insert(machinecode.end(), block2.begin(), block2.end());
        }

        break;
      }
    case 0x05:
      /** else */
      { return machinecode; }
    case 0x01:
      /** nop */
      {
        machinecode.push_back(arm64::encode_nop());
        break;
      }
    case 0x0f:
      /** return */
      { return machinecode; }
    case 0x0b:
      /** end */
      { return machinecode; }
    default:
      std::cout << "unsupported instruction: 0x" << std::hex << std::setw(2) << std::setfill('0') << int32_t(*(stream - 1)) << " " << std::endl;
      asserte(false, "unsupported instruction");
      break;
    }
  }
  return machinecode;
}
} // namespace assembler