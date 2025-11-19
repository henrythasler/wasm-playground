#include "assembler.hpp"

jmp_buf g_jmpbuf;

extern "C" void wasmTrapHandler(int error_code) {
  longjmp(g_jmpbuf, error_code);
}

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
 * Encodes a trap handler that sets up the parameters and branches to the actual trap handler.
 * @return the offset in bytes of the first instruction of the trap handler in the machinecode vector.
 */
size_t encodeTrapHandler(uint64_t trapHandlerAddress, wasm::trap_code_t trapCode, std::vector<uint32_t> &machinecode) {
  size_t offset = machinecode.size() << 2;
  machinecode.push_back(arm64::encode_mov_immediate(arm64::X0, uint16_t(trapCode), 0, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_mov_immediate(arm64::X9, uint16_t(trapHandlerAddress & 0xFFFF), 0, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_movk(arm64::X9, uint16_t((trapHandlerAddress >> (1 << 4)) & 0xFFFF), 1 << 4, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_movk(arm64::X9, uint16_t((trapHandlerAddress >> (2 << 4)) & 0xFFFF), 2 << 4, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_movk(arm64::X9, uint16_t((trapHandlerAddress >> (3 << 4)) & 0xFFFF), 3 << 4, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_branch_register(arm64::X9));
  return offset;
}

std::map<wasm::trap_code_t, int32_t> createTrapHandler(const std::vector<wasm::trap_code_t> trapCodes, std::vector<uint32_t> &machinecode) {
  std::map<wasm::trap_code_t, int32_t> trapcodeOffsets;

  auto trapHandlerPosition = machinecode.size();

  // this instruction requires address patching after all handlers are emitted; for now, just jump to the next instruction
  machinecode.push_back(arm64::encode_branch(4));

  for (auto trapcode : trapCodes) {
    trapcodeOffsets[trapcode] = int32_t(encodeTrapHandler(reinterpret_cast<uint64_t>(&wasmTrapHandler), trapcode, machinecode));
  }

  // patch forward jump over all trap handlers
  machinecode[trapHandlerPosition] |= (uint32_t(machinecode.size() - trapHandlerPosition) & 0x3FFFFFF);
  return trapcodeOffsets;
}

inline int32_t getTraphandlerOffset(wasm::trap_code_t trapCode, const std::map<wasm::trap_code_t, int32_t> &trapHandler,
                                    const std::vector<uint32_t> &machinecode) {
  return trapHandler.at(trapCode) - int32_t(machinecode.size() << 2);
}

/**
 * Assemble a WebAssembly expression (aka bytecode) into ARM64 machine code.
 */
void assembleExpression(std::vector<uint8_t>::const_iterator &stream, std::vector<uint8_t>::const_iterator streamEnd, Variables &locals,
                        RegisterPool &registerPool, std::vector<ControlBlock> &controlStack, std::vector<arm64::reg_t> &stack,
                        const std::map<wasm::trap_code_t, int32_t> &trapHandler, std::vector<uint32_t> &machinecode) {
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
    case 0x6d:
    case 0x6e:
    case 0x7f:
    case 0x80:
      /** i32.div_s, i32.div_u, i64.div_s, i64.div_u */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for div");

        auto registerSize = ((*(stream - 1) == 0x6d) || (*(stream - 1) == 0xe6)) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto signedVariant =
            ((*(stream - 1) == 0x6d) || (*(stream - 1) == 0x7f)) ? arm64::signed_variant_t::SIGNED : arm64::signed_variant_t::UNSIGNED;

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        // check for division by zero and trap if so
        machinecode.push_back(arm64::encode_cbz(reg2, getTraphandlerOffset(wasm::trap_code_t::IntegerDivisionByZero, trapHandler, machinecode),
                                                registerSize)); // skip trap handler jump sequence if not zero

        // need to check for integer overflow (INT_MIN/-1)
        if (signedVariant == arm64::signed_variant_t::SIGNED) {
          // check if divisor is -1
          machinecode.push_back(arm64::encode_cmn_immediate(reg2, 1, false, registerSize));
          machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::NE, 4 << 2));

          // Yes! Now check if dividend is INT(32|64)_MIN
          auto tmp_reg = registerPool.allocateRegister();
          uint8_t shift = (registerSize == arm64::reg_size_t::SIZE_32BIT) ? 16 : 48;
          machinecode.push_back(arm64::encode_mov_immediate(tmp_reg, 0x8000, shift, registerSize));
          machinecode.push_back(arm64::encode_cmp_shifted_register(reg1, tmp_reg, arm64::reg_shift_t::SHIFT_LSL, 0, registerSize));
          machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::EQ,
                                                          getTraphandlerOffset(wasm::trap_code_t::IntegerOverflow, trapHandler, machinecode)));
          registerPool.freeRegister(tmp_reg);
        }

        // all checks passed; encode division instruction
        machinecode.push_back(arm64::encode_div_register(reg1, reg1, reg2, signedVariant, registerSize));

        stack.pop_back();
        registerPool.freeRegister(reg2);
        break;
      }
    case 0x41:
    case 0x42:
      /** (i32|i64).const n:(i32|i64) */
      {
        auto registerSize = (*(stream - 1) == 0x41) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto constValue = decoder::LEB128Decoder::decodeSigned(stream, streamEnd); // n
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);

        auto chunkLimit = (registerSize == arm64::reg_size_t::SIZE_32BIT) ? 2 : 4;
        for (uint8_t i = 0; i < chunkLimit; i++) {
          uint16_t chunk = uint16_t((constValue >> (i << 4)) & 0xFFFF);
          if (i == 0) {
            machinecode.push_back(arm64::encode_mov_immediate(reg, chunk, 0, registerSize));
          } else if (chunk != 0) {
            machinecode.push_back(arm64::encode_movk(reg, chunk, i << 4, registerSize));
          }
        }
        break;
      }
    case 0x1A:
      /** drop - discard top-most value from the stack */
      {
        registerPool.freeRegister(stack.back());
        stack.pop_back();
        break;
      }
    case 0x45:
    case 0x50:
      /** (i32|i64).eqz - Return 1 if i is zero, 0 otherwise*/
      {
        // FIXME: Implementation missing
        break;
      }
    case 0x4C:
    case 0x4D:
    case 0x57:
    case 0x58:
      /** (i32|i64).le_(u|s) */
      {
        // FIXME: Implementation missing
        break;
      }
    case 0x48: // i32.lt_s
    case 0x49: // i32.lt_u
    case 0x53: // i64.lt_s
    case 0x54: // i64.lt_u
    {
      asserte(stack.size() >= 2, "insufficient operands on stack for lt_s");
      auto registerSize = ((*(stream - 1) == 0x48) || (*(stream - 1) == 0x49)) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
      auto signedVariant = ((*(stream - 1) == 0x48) || (*(stream - 1) == 0x53)) ? arm64::signed_variant_t::SIGNED : arm64::signed_variant_t::UNSIGNED;

      auto reg2 = stack.at(stack.size() - 1);
      auto reg1 = stack.at(stack.size() - 2);

      machinecode.push_back(arm64::encode_cmp_shifted_register(reg1, reg2, arm64::reg_shift_t::SHIFT_LSL, 0, registerSize));

      if (signedVariant == arm64::signed_variant_t::SIGNED) {
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::LT, 3 * 4));
      } else {
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::LO, 3 * 4));
      }

      // // load 0
      machinecode.push_back(arm64::encode_mov_immediate(reg1, 0, 0, arm64::reg_size_t::SIZE_32BIT));
      machinecode.push_back(arm64::encode_branch(2 * 4));
      // // load 1
      machinecode.push_back(arm64::encode_mov_immediate(reg1, 1, 0, arm64::reg_size_t::SIZE_32BIT));

      stack.pop_back();
      registerPool.freeRegister(reg2);

      break;
    }
    case 0x68:
    case 0x7A:
      /** (i32|i64).ctz - Return the count of trailing zero bits */
      {
        auto registerSize = (*(stream - 1) == 0x68) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;

        auto reg1 = stack.back();
        // auto reg2 = registerPool.allocateRegister();

        arm64::emit_ctz(reg1, reg1, registerSize, machinecode);

        // stack.pop_back();
        // registerPool.freeRegister(reg1);
        // stack.emplace_back(reg2);

        break;
      }
    case 0x02:
      /** block, followed by: blocktype (u8) either describing an empty result (0x40) or the type of the single result */
      {
        auto rawBlocktype = *stream++;
        auto blocktype = (rawBlocktype == 0x40) ? webassembly_t::val_types_t(0) : webassembly_t::val_types_t(rawBlocktype);
        controlStack.push_back(ControlBlock{ControlBlock::Type::BLOCK, {}, registerPool, stack, blocktype});
        break;
      }
    case 0x0c:
      /** br */
      {
        auto labelidx = size_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto &controlBlock = controlStack.at(controlStack.size() - 1 - labelidx);

        if (controlBlock.resultType != webassembly_t::val_types_t(0)) {
          if (controlBlock.resultRegister != arm64::reg_t::XZR) {
            // move result to correct register before branching
            machinecode.push_back(
                arm64::encode_mov_register(controlBlock.resultRegister, stack.back(), map_valtype_to_regsize(controlBlock.resultType)));
          } else {
            // set result register for the block
            controlBlock.resultRegister = stack.back();
          }
        }

        controlBlock.patchLocations.push_back({machinecode.size(), stack.size()});
        machinecode.push_back(arm64::encode_cbz(arm64::reg_t::XZR,
                                                getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode),
                                                arm64::reg_size_t::SIZE_64BIT));
        break;
      }
    case 0x0d:
      /** br_if */
      {
        auto labelidx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));

        auto reg = stack.back();
        stack.pop_back();
        registerPool.freeRegister(reg);

        auto &controlBlock = controlStack.at(controlStack.size() - 1 - labelidx);

        if (controlBlock.resultType != webassembly_t::val_types_t(0)) {
          if (controlBlock.resultRegister != arm64::reg_t::XZR) {
            // move result to correct register before branching
            machinecode.push_back(
                arm64::encode_mov_register(controlBlock.resultRegister, stack.back(), map_valtype_to_regsize(controlBlock.resultType)));
          } else {
            // set result register for the block
            controlBlock.resultRegister = stack.back();
          }
        }

        controlBlock.patchLocations.push_back({machinecode.size(), stack.size()});
        machinecode.push_back(arm64::encode_cbnz(reg, getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode),
                                                 arm64::reg_size_t::SIZE_32BIT));
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

        // insert cbz to jump over if block if condition is false (zero)
        controlStack.push_back(ControlBlock{ControlBlock::Type::IF, {{machinecode.size(), stack.size()}}, registerPool, stack, blocktype});
        machinecode.push_back(arm64::encode_cbz(reg, getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode),
                                                arm64::reg_size_t::SIZE_32BIT));
        break;
      }
    case 0x05:
      /** else */
      {
        asserte(controlStack.size() > 1, "Control Stack is malformed");
        switch (controlStack.back().type) {
        case ControlBlock::IF: {
          for (auto idx : controlStack.back().patchLocations) {
            auto offset = (machinecode.size() - idx.offset + 1) << 2;
            // patch CBZ (Compare and branch on zero) instruction
            arm64::patch_cbz(machinecode[idx.offset], int32_t(offset));
          }

          // restore previous state
          registerPool = controlStack.back().registerPoolState;
          stack = controlStack.back().stackState;
          auto blocktype = controlStack.back().resultType;

          controlStack.push_back(ControlBlock{ControlBlock::Type::ELSE, {{machinecode.size(), stack.size()}}, registerPool, stack, blocktype});
          machinecode.push_back(arm64::encode_branch(getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode)));
          break;
        }
        default: {
          asserte(false, "ControlBlock.type undefined");
          break;
        }
        }
        break;
      }
    case 0x01:
      /** nop */
      {
        machinecode.push_back(arm64::encode_nop());
        break;
      }
    case 0x0f:
      /** return */
      {
        controlStack.front().patchLocations.push_back({machinecode.size(), stack.size()});
        machinecode.push_back(arm64::encode_cbz(arm64::reg_t::XZR,
                                                getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode),
                                                arm64::reg_size_t::SIZE_64BIT));
        break;
      }
    case 0x0b:
      /** end */
      {
        if (controlStack.size() > 0) {
          switch (controlStack.back().type) {
          case ControlBlock::IF: {
            for (auto idx : controlStack.back().patchLocations) {
              auto offset = (machinecode.size() - idx.offset) << 2;
              // patch CBZ (Compare and branch on zero) instruction
              arm64::patch_cbz(machinecode[idx.offset], int32_t(offset));
            }

            controlStack.pop_back();
            break;
          }
          case ControlBlock::ELSE: {
            for (auto idx : controlStack.back().patchLocations) {
              auto offset = (machinecode.size() - idx.offset) << 2;
              // patch B (branch) instruction
              arm64::patch_branch(machinecode[idx.offset], int32_t(offset));
            }

            controlStack.pop_back();
            // also pop IF element
            controlStack.pop_back();
            break;
          }
          case ControlBlock::FUNCTION:
          case ControlBlock::BLOCK: {
            if (controlStack.back().resultType != webassembly_t::val_types_t(0)) {
              if (controlStack.back().resultRegister != arm64::reg_t::XZR && controlStack.back().resultRegister != stack.back()) {
                // move result to correct register before branching
                auto srcReg = stack.back();
                registerPool.freeRegister(srcReg);
                machinecode.push_back(
                    arm64::encode_mov_register(controlStack.back().resultRegister, srcReg, map_valtype_to_regsize(controlStack.back().resultType)));
                stack.push_back(controlStack.back().resultRegister);
              }
            }

            for (auto idx : controlStack.back().patchLocations) {
              auto offset = (machinecode.size() - idx.offset) << 2;
              arm64::patch_cbz(machinecode[idx.offset], int32_t(offset));
            }

            if (stack.size() > controlStack.back().stackState.size() && controlStack.back().resultType != webassembly_t::val_types_t(0)) {
              auto reg = stack.back();
              stack = controlStack.back().stackState;
              registerPool = controlStack.back().registerPoolState;
              registerPool.lockRegister(reg);
              stack.push_back(reg);
            } else {
              stack = controlStack.back().stackState;
              registerPool = controlStack.back().registerPoolState;
            }

            controlStack.pop_back();
            break;
          }
          default: {
            asserte(false, "ControlBlock.type undefined");
            break;
          }
          }
        }
        break;
      }
    case 0x00:
      /** unreachable */
      {
        machinecode.push_back(arm64::encode_branch(getTraphandlerOffset(wasm::trap_code_t::UnreachableCodeReached, trapHandler, machinecode)));
        break;
      }
    default:
      std::stringstream message;
      message << std::hex << std::setw(2) << std::setfill('0') << int32_t(*(stream - 1));
      asserte(false, "unsupported instruction: 0x" + message.str());
      break;
    }
  }
}
} // namespace assembler