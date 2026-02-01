#include "assembler.hpp"

jmp_buf g_jmpbuf;

uint64_t executableMemoryAddress = 0;
uint64_t *executableMemoryAddressPtr = &executableMemoryAddress;

uint64_t globalsMemoryAddress = 0;
uint64_t *globalsMemoryAddressPtr = &globalsMemoryAddress;

uint64_t linearMemoryAddress = 0;
uint64_t *linearMemoryAddressPtr = &linearMemoryAddress;

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
  asserte(wasmStack.size() > 0, "Wasm stack underflow when loading result");
  auto registerSize = map_valtype_to_regsize(results.back());
  auto sourceReg = wasmStack.back();
  auto targetReg = (registerSize == arm64::reg_size_t::SIZE_32BIT) ? arm64::reg_t::W0 : arm64::reg_t::X0;
  machinecode.push_back(arm64::encode_mov_register(targetReg, sourceReg, registerSize));
}

uint32_t createPreamble(uint32_t stackSize, std::vector<uint32_t> &machinecode) {
  // Prologue: create a new stack frame (stp fp, lr, [sp, #-16]!)
  machinecode.push_back(arm64::encode_stp(arm64::FP, arm64::LR, arm64::SP, -16, arm64::addressing_mode_t::PRE_INDEX, arm64::reg_size_t::SIZE_64BIT));
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
  machinecode.push_back(arm64::encode_ldp(arm64::FP, arm64::LR, arm64::SP, 16, arm64::addressing_mode_t::POST_INDEX, arm64::reg_size_t::SIZE_64BIT));
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
 * Create a trap handler that can handle multiple trap codes. For each trap code, a jump sequence is created that loads the trap code into register X0
 * and branches to the actual trap handler.
 * After loading the address of the actual trap handler, a branch register instruction is used to jump to the
 * handler.
 * @param trapCodes A vector of trap codes to be handled.
 * @param machinecode A reference to the vector where the generated machine code will be appended.
 * @return A map of trap codes to their respective offsets in the machine code.
 */
std::map<wasm::trap_code_t, int32_t> createTrapHandler(const std::vector<wasm::trap_code_t> trapCodes, std::vector<uint32_t> &machinecode) {
  std::map<wasm::trap_code_t, int32_t> trapcodeOffsets;

  auto trapHandlerAddress = reinterpret_cast<uintptr_t>(&wasmTrapHandler);

  int32_t idx = 1;
  for (auto trapcode : trapCodes) {
    // record offset of this trapcode handler
    trapcodeOffsets[trapcode] = int32_t(machinecode.size() << 2);
    // load trap code into X0 and branch to actual trap handler
    machinecode.push_back(arm64::encode_mov_immediate(arm64::X0, uint16_t(trapcode), 0, arm64::reg_size_t::SIZE_64BIT));
    machinecode.push_back(arm64::encode_branch(((int32_t(trapCodes.size()) - idx) * 2 + 1) << 2));
    idx++;
  }

  // prepare branch to actual trap handler; load its address into X9 and branch to it
  machinecode.push_back(arm64::encode_mov_immediate(arm64::X9, uint16_t(trapHandlerAddress & 0xFFFF), 0, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_movk(arm64::X9, uint16_t((trapHandlerAddress >> (1 << 4)) & 0xFFFF), 1 << 4, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_movk(arm64::X9, uint16_t((trapHandlerAddress >> (2 << 4)) & 0xFFFF), 2 << 4, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_movk(arm64::X9, uint16_t((trapHandlerAddress >> (3 << 4)) & 0xFFFF), 3 << 4, arm64::reg_size_t::SIZE_64BIT));
  machinecode.push_back(arm64::encode_branch_register(arm64::X9));

  return trapcodeOffsets;
}

inline int32_t getTraphandlerOffset(wasm::trap_code_t trapCode, const std::map<wasm::trap_code_t, int32_t> &trapHandler,
                                    const std::vector<uint32_t> &machinecode) {
  asserte(trapHandler.find(trapCode) != trapHandler.end(),
          "getTraphandlerOffset(): trap code '" + std::to_string(static_cast<int>(trapCode)) + "' not found in trap handler map: ");
  return trapHandler.at(trapCode) - int32_t(machinecode.size() << 2);
}

/** save caller registers */
void saveRegisters(RegisterPool &registerPool, std::vector<uint32_t> &machinecode) {
  auto registers = registerPool.getRegisterNames();
  auto numRegisters = registers.size();
  asserte(numRegisters % 2 == 0, "saveRegisters(): number of saved registers must be even");

  uint32_t offset = numRegisters * AARCH64_INT64_SIZE;
  machinecode.push_back(arm64::encode_sub_immediate(arm64::SP, arm64::SP, offset, false, arm64::reg_size_t::SIZE_64BIT));

  for (int32_t i = 0; i < int32_t(numRegisters); i += 2) {
    offset -= AARCH64_INT64_SIZE * 2;
    auto reg1 = registers.at(i);
    auto reg2 = registers.at(i + 1);
    machinecode.push_back(arm64::encode_stp(reg1, reg2, arm64::SP, offset, arm64::addressing_mode_t::SIGNED_OFFSET, arm64::reg_size_t::SIZE_64BIT));
  }
}

void restoreRegisters(RegisterPool &registerPool, std::vector<uint32_t> &machinecode) {
  auto registers = registerPool.getRegisterNames();
  auto numRegisters = registers.size();
  asserte(numRegisters % 2 == 0, "restoreRegisters(): number of saved registers must be even");

  uint32_t offset = numRegisters * AARCH64_INT64_SIZE;

  for (int32_t i = 0; i < int32_t(numRegisters); i += 2) {
    offset -= AARCH64_INT64_SIZE * 2;
    auto reg1 = registers.at(i);
    auto reg2 = registers.at(i + 1);
    machinecode.push_back(arm64::encode_ldp(reg1, reg2, arm64::SP, offset, arm64::addressing_mode_t::SIGNED_OFFSET, arm64::reg_size_t::SIZE_64BIT));
  }
  machinecode.push_back(arm64::encode_add_immediate(arm64::SP, arm64::SP, numRegisters * AARCH64_INT64_SIZE, false, arm64::reg_size_t::SIZE_64BIT));
}

/**
 * Assemble a WebAssembly expression (aka bytecode) into ARM64 machine code.
 */
void assembleExpression(std::vector<uint8_t>::const_iterator &stream, std::vector<uint8_t>::const_iterator streamEnd, Variables &locals,
                        RegisterPool &registerPool, std::vector<ControlBlock> &controlStack, std::vector<arm64::reg_t> &stack,
                        const std::map<wasm::trap_code_t, int32_t> &trapHandler, std::vector<FunctionCallPatchLocation> &functionCallPatchLocations,
                        std::vector<LoadAddressPatchLocation> &loadAddressPatches, webassembly_t::type_section_t *type_section,
                        webassembly_t::function_section_t *function_section, std::unique_ptr<assembler::Globals> &globals,
                        std::unique_ptr<assembler::FunctionTable> &functionTable, std::vector<uint32_t> &machinecode) {
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
        asserte(stack.size() >= 1, "insufficient operands on stack for local.set");
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
        asserte(stack.size() >= 1, "insufficient operands on stack for tee");
        auto reg = stack.back();
        auto idx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto registerSize = map_valtype_to_regsize(locals.getType(idx));
        machinecode.push_back(arm64::encode_str_unsigned_offset(reg, arm64::SP, uint16_t(locals.get(idx)), registerSize));
        break;
      }
    case 0x23:
      /** global.get */
      {
        // do we even have a global section to work with?
        asserte(globals, "global section not initialized");

        // get the global index
        auto globalidx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto global = globals->entries.at(globalidx);

        auto registerSize =
            (global.valType == webassembly_t::val_types_t::VAL_TYPES_I32) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);

        // immutable globals are compiled as const
        if (!global.isMutable) {
          arm64::emit_mov_large_immediate(reg, uint64_t(global.value), registerSize, machinecode);
        } else {
          // encode address location to be loaded from global variable
          auto absoluteAddress = reinterpret_cast<std::uintptr_t>(globalsMemoryAddressPtr);
          arm64::emit_mov_large_immediate(reg, uint64_t(absoluteAddress), arm64::reg_size_t::SIZE_64BIT, machinecode);

          // load address of globals memory from pointer
          machinecode.push_back(
              arm64::encode_ldr_register(reg, reg, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL, 0, arm64::reg_size_t::SIZE_64BIT));

          // add globalidx offset to get the actual address of the global
          machinecode.push_back(arm64::encode_add_immediate(reg, reg, globalidx * sizeof(uint64_t), false, arm64::reg_size_t::SIZE_64BIT));

          // load actual global from memory location
          machinecode.push_back(
              arm64::encode_ldr_register(reg, reg, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL, 0, arm64::reg_size_t::SIZE_64BIT));
        }
        break;
      }
    case 0x24:
      /** global.set */
      {
        asserte(stack.size() >= 1, "insufficient operands on stack for global.set");

        // get the global index
        auto globalidx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto global = globals->entries.at(globalidx);
        asserte(global.isMutable, "global.set: global variable at index " + std::to_string(globalidx) + " is not mutable");

        auto addressRegister = registerPool.allocateRegister();
        auto valueRegister = stack.back();

        // encode address location to be loaded from global variable
        auto absoluteAddress = reinterpret_cast<std::uintptr_t>(globalsMemoryAddressPtr);
        arm64::emit_mov_large_immediate(addressRegister, uint64_t(absoluteAddress), arm64::reg_size_t::SIZE_64BIT, machinecode);

        // load address of globals memory from pointer
        machinecode.push_back(arm64::encode_ldr_register(addressRegister, addressRegister, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL,
                                                         0, arm64::reg_size_t::SIZE_64BIT));

        // add globalidx offset to get the actual address of the global
        machinecode.push_back(
            arm64::encode_add_immediate(addressRegister, addressRegister, globalidx * sizeof(uint64_t), false, arm64::reg_size_t::SIZE_64BIT));

        // store value in address
        machinecode.push_back(arm64::encode_str_register(valueRegister, addressRegister, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL, 0,
                                                         arm64::reg_size_t::SIZE_64BIT));

        registerPool.freeRegister(addressRegister);
        registerPool.freeRegister(valueRegister);
        stack.pop_back();

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
        arm64::emit_mov_large_immediate(reg, uint64_t(constValue), registerSize, machinecode);
        break;
      }
    case 0x1A:
      /** drop - discard top-most value from the stack */
      {
        asserte(stack.size() >= 1, "insufficient operands on stack for drop");
        registerPool.freeRegister(stack.back());
        stack.pop_back();
        break;
      }
    case 0x45: // i32.eqz
    case 0x50: // i64.eqz
      /** Return 1 if i is zero, 0 otherwise */
      {
        asserte(stack.size() >= 1, "insufficient operands on stack for eqz");
        auto registerSize = (*(stream - 1) == 0x45) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto reg = stack.back();

        machinecode.push_back(arm64::encode_cbz(reg, 3 * 4, registerSize));

        // // load 0
        machinecode.push_back(arm64::encode_mov_immediate(reg, 0, 0, arm64::reg_size_t::SIZE_32BIT));
        machinecode.push_back(arm64::encode_branch(2 * 4));
        // // load 1
        machinecode.push_back(arm64::encode_mov_immediate(reg, 1, 0, arm64::reg_size_t::SIZE_32BIT));
        break;
      }
    case 0x46: // i32.eq
    case 0x51: // i64.eq
      /** Return 1 if i1​ equals i2​, 0 otherwise. */
      {
        asserte(stack.size() >= 1, "insufficient operands on stack for eqz");
        auto registerSize = (*(stream - 1) == 0x46) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        machinecode.push_back(arm64::encode_cmp_shifted_register(reg1, reg2, arm64::reg_shift_t::SHIFT_LSL, 0, registerSize));
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::EQ, 3 * 4));

        // // load 0
        machinecode.push_back(arm64::encode_mov_immediate(reg1, 0, 0, arm64::reg_size_t::SIZE_32BIT));
        machinecode.push_back(arm64::encode_branch(2 * 4));
        // // load 1
        machinecode.push_back(arm64::encode_mov_immediate(reg1, 1, 0, arm64::reg_size_t::SIZE_32BIT));

        stack.pop_back();
        registerPool.freeRegister(reg2);
        break;
      }
    case 0x4A: // i32.gt_s
    case 0x4B: // i32.gt_u
    case 0x55: // i64.gt_s
    case 0x56: // i64.gt_u
      /** Return 1 if i1​ is greater than i2​, 0 otherwise. */
      {
        asserte(stack.size() >= 2, "insufficient operands on stack for gt");
        auto registerSize = ((*(stream - 1) == 0x4A) || (*(stream - 1) == 0x4B)) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto signedVariant =
            ((*(stream - 1) == 0x4A) || (*(stream - 1) == 0x55)) ? arm64::signed_variant_t::SIGNED : arm64::signed_variant_t::UNSIGNED;

        auto reg2 = stack.at(stack.size() - 1);
        auto reg1 = stack.at(stack.size() - 2);

        machinecode.push_back(arm64::encode_cmp_shifted_register(reg1, reg2, arm64::reg_shift_t::SHIFT_LSL, 0, registerSize));

        if (signedVariant == arm64::signed_variant_t::SIGNED) {
          machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::GT, 3 * 4));
        } else {
          machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::HI, 3 * 4));
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
    case 0x4C: // i32.le_s
    case 0x4D: // i32.le_u
    case 0x57: // i64.le_s
    case 0x58: // i64.le_u
    {
      asserte(stack.size() >= 2, "insufficient operands on stack for le_s");
      auto registerSize = ((*(stream - 1) == 0x4c) || (*(stream - 1) == 0x4d)) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
      auto signedVariant = ((*(stream - 1) == 0x4c) || (*(stream - 1) == 0x57)) ? arm64::signed_variant_t::SIGNED : arm64::signed_variant_t::UNSIGNED;

      auto reg2 = stack.at(stack.size() - 1);
      auto reg1 = stack.at(stack.size() - 2);

      machinecode.push_back(arm64::encode_cmp_shifted_register(reg1, reg2, arm64::reg_shift_t::SHIFT_LSL, 0, registerSize));

      if (signedVariant == arm64::signed_variant_t::SIGNED) {
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::LE, 3 * 4));
      } else {
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::LS, 3 * 4));
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
    case 0x68: // i32.ctz
    case 0x7A: // i64.ctz
      /** Return the count of trailing zero bits */
      {
        asserte(stack.size() >= 1, "insufficient operands on stack for ctz");
        auto registerSize = (*(stream - 1) == 0x68) ? arm64::reg_size_t::SIZE_32BIT : arm64::reg_size_t::SIZE_64BIT;
        auto reg = stack.back();
        arm64::emit_ctz(reg, reg, registerSize, machinecode);
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
    case 0x03:
      /** loop, followed by: blocktype (u8) either describing an empty result (0x40) or the type of the single result */
      {
        auto rawBlocktype = *stream++;
        auto blocktype = (rawBlocktype == 0x40) ? webassembly_t::val_types_t(0) : webassembly_t::val_types_t(rawBlocktype);
        controlStack.push_back(ControlBlock{ControlBlock::Type::LOOP, {{machinecode.size(), stack.size()}}, registerPool, stack, blocktype});
        break;
      }
    case 0x0c:
      /** br */
      {
        auto labelidx = size_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
        auto &controlBlock = controlStack.at(controlStack.size() - 1 - labelidx);

        if (controlBlock.resultType != webassembly_t::val_types_t(0)) {
          asserte(stack.size() >= 1, "insufficient operands on stack for br");
          if (controlBlock.resultRegister != arm64::reg_t::XZR) {
            // move result to correct register before branching
            machinecode.push_back(
                arm64::encode_mov_register(controlBlock.resultRegister, stack.back(), map_valtype_to_regsize(controlBlock.resultType)));
          } else {
            // set result register for the block
            controlBlock.resultRegister = stack.back();
          }
        }

        if (controlBlock.type == ControlBlock::LOOP) {
          int32_t offset = (int32_t(controlBlock.patchLocations.back().offset) - int32_t(machinecode.size()) + 1) << 2;
          machinecode.push_back(arm64::encode_branch(offset));
        } else if (controlBlock.type == ControlBlock::BLOCK) {
          controlBlock.patchLocations.push_back({machinecode.size(), stack.size()});
          machinecode.push_back(arm64::encode_cbz(arm64::reg_t::XZR,
                                                  getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode),
                                                  arm64::reg_size_t::SIZE_64BIT));
        }
        break;
      }
    case 0x0d:
      /** br_if */
      {
        asserte(stack.size() >= 1, "insufficient operands on stack for br_if");
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
        asserte(stack.size() >= 1, "insufficient operands on stack for if");
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
          case ControlBlock::LOOP: {
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
    case 0x10:
      /** call */
      {
        auto funcidx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));

        const auto &func = function_section->typeidx()->at(funcidx);
        const auto &funcType = type_section->functypes()->at(static_cast<size_t>(func->value()));
        auto parameterTypes = *funcType->parameters()->valtype();
        asserte(parameterTypes.size() <= 8, "function calls with more than 8 parameters are not supported");
        asserte(stack.size() >= parameterTypes.size(), "insufficient operands on stack for function call");

        // move parameters from stack in reverse order into argument registers
        auto targetRegisterNum = parameterTypes.size() - 1;
        for (auto valtype : parameterTypes) {
          auto registerSize = map_valtype_to_regsize(valtype);
          auto sourceReg = stack.back();
          machinecode.push_back(arm64::encode_mov_register(arm64::reg_t(targetRegisterNum), sourceReg, registerSize));
          targetRegisterNum--;

          stack.pop_back();
          registerPool.freeRegister(sourceReg);
        }

        saveRegisters(registerPool, machinecode);
        // emit placeholder for call instruction; needs to be patched later
        functionCallPatchLocations.push_back(FunctionCallPatchLocation{machinecode.size(), funcidx});
        // for now, just emit a branch link to the trap handler for address patch errors; will be patched later
        machinecode.push_back(
            arm64::encode_branch_link(getTraphandlerOffset(wasm::trap_code_t::AssemblerAddressPatchError, trapHandler, machinecode)));
        restoreRegisters(registerPool, machinecode);

        // get return value
        auto reg = registerPool.allocateRegister();
        stack.emplace_back(reg);
        machinecode.push_back(arm64::encode_mov_register(reg, arm64::X0, arm64::reg_size_t::SIZE_64BIT));

        break;
      }
    case 0x11:
      /** call_indirect */
      {
        // get the type index that is encoded with the call_indirect instruction
        auto typeidx = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));

        // skip reserved byte
        *stream++;

        // verify that we have a valid type index that is within bounds of the type section
        asserte(typeidx < type_section->functypes()->size(), "typeidx out of bounds in call_indirect");

        // get expected function type and signature from type section
        const auto &expectedFuncType = type_section->functypes()->at(static_cast<size_t>(typeidx));
        auto expectedParameterTypes = *expectedFuncType->parameters()->valtype();
        auto expectedResultType = expectedFuncType->results()->valtype();

        // check that we do not exceed the maximum number of supported parameters
        asserte(expectedParameterTypes.size() <= 8, "function calls with more than 8 parameters are not supported");

        // check that we do not have more than one return value
        asserte(expectedResultType->size() <= 1, "functions with more than one return value are not supported");

        // ensure that we have enough operands on the stack for the table index
        asserte(stack.size() >= 1, "insufficient operands on stack for call_indirect");
        // get table index from top of stack
        auto tableidx = stack.back();

        asserte(functionTable.get() != nullptr, "function table is not defined for call_indirect");
        // emit runtime check that the value in register 'tableidx' is smaller than the size of the table
        // use subs_immediate to substract (static) table size from 'tableidx' register
        // branch_cond over next instruction if result is >= 0; otherwise jump to trap handler from table index out of bounds
        machinecode.push_back(
            arm64::encode_cmp_immediate(tableidx, static_cast<uint32_t>(functionTable->entries.size()), false, arm64::reg_size_t::SIZE_64BIT));
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::GE,
                                                        getTraphandlerOffset(wasm::trap_code_t::TableOutOfBounds, trapHandler, machinecode)));

        // discard table index
        stack.pop_back();

        // allocate a register to hold the function index which we will load from the function table
        auto functionidxReg = registerPool.allocateRegister();

        // record location for load address patching
        loadAddressPatches.push_back(LoadAddressPatchLocation{machinecode.size(), DataSegmentType::FUNCTION_TABLE});

        // load [function index, type index] pair from function_table using the tableidx register as offset
        // lower 32bit = function index; upper 32bit = type index
        // FIXME: investigate if adrp/add using `0` as page/offset is the best way to encode this
        machinecode.push_back(arm64::encode_adrp(functionidxReg, 0));
        machinecode.push_back(arm64::encode_add_immediate(functionidxReg, functionidxReg, 0, false, arm64::reg_size_t::SIZE_64BIT));
        machinecode.push_back(arm64::encode_ldr_register(functionidxReg, functionidxReg, tableidx, arm64::index_extend_type_t::INDEX_LSL, 3,
                                                         arm64::reg_size_t::SIZE_64BIT));

        // runtime check that the function index is not uninitialized (0xffffffff)
        // CMN = Compare Negative → adds operand and sets flags; If w0 == 0xFFFFFFFF, then w0 + 1 == 0; Z flag is set on match
        machinecode.push_back(arm64::encode_cmn_immediate(functionidxReg, 1, false, arm64::reg_size_t::SIZE_64BIT));
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::EQ,
                                                        getTraphandlerOffset(wasm::trap_code_t::IndirectCallToNull, trapHandler, machinecode)));

        // runtime check that the type index from the function table matches the expected type index
        auto actualTypeIndexReg = registerPool.allocateRegister();
        // copy upper 32bit from functionidxReg into actualTypeIndexReg to extract type index
        machinecode.push_back(arm64::encode_lsr_immediate(actualTypeIndexReg, functionidxReg, 32, arm64::reg_size_t::SIZE_64BIT));
        // compare actual type index with expected type index
        machinecode.push_back(arm64::encode_cmp_immediate(actualTypeIndexReg, static_cast<uint32_t>(typeidx), false, arm64::reg_size_t::SIZE_32BIT));
        machinecode.push_back(arm64::encode_branch_cond(arm64::branch_condition_t::NE,
                                                        getTraphandlerOffset(wasm::trap_code_t::BadSignature, trapHandler, machinecode)));
        registerPool.freeRegister(actualTypeIndexReg);

        // free tableidx register
        registerPool.freeRegister(tableidx);

        // allocate a register to hold the base address of the executable memory
        auto baseAddressReg = registerPool.allocateRegister();

        // encode base address location to be loaded from global variable using mov/movk instructions
        auto absoluteAddress = reinterpret_cast<std::uintptr_t>(executableMemoryAddressPtr);
        arm64::emit_mov_large_immediate(baseAddressReg, uint64_t(absoluteAddress), arm64::reg_size_t::SIZE_64BIT, machinecode);

        // load base address of executable memory from pointer
        machinecode.push_back(arm64::encode_ldr_register(baseAddressReg, baseAddressReg, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL, 0,
                                                         arm64::reg_size_t::SIZE_64BIT));

        // clear upper 32bit from functionidxReg to remove typeidx and keep the offset before adding as offset to base address
        machinecode.push_back(arm64::encode_mov_register(functionidxReg, functionidxReg, arm64::reg_size_t::SIZE_32BIT));
        // add base address of executable memory to function index to get actual function address to call
        machinecode.push_back(arm64::encode_add_register(functionidxReg, baseAddressReg, functionidxReg, 0, arm64::reg_shift_t::SHIFT_LSL,
                                                         arm64::reg_size_t::SIZE_64BIT));
        registerPool.freeRegister(baseAddressReg);

        // std::cout << std::hex << "executableMemoryAddress: content=0x" << executableMemoryAddress << " location=0x" << executableMemoryAddressPtr
        //           << std::dec << std::endl;

        // move parameters into argument registers
        auto targetRegisterNum = expectedParameterTypes.size() - 1;
        for (auto valtype : expectedParameterTypes) {
          auto registerSize = map_valtype_to_regsize(valtype);
          auto sourceReg = stack.back();
          machinecode.push_back(arm64::encode_mov_register(arm64::reg_t(targetRegisterNum), sourceReg, registerSize));
          targetRegisterNum--;
          stack.pop_back();
          registerPool.freeRegister(sourceReg);
        }

        // branch to function via branch link register
        machinecode.push_back(arm64::encode_branch_link_register(functionidxReg));
        registerPool.freeRegister(functionidxReg);

        // push return value onto stack
        if (expectedResultType->size() > 0) {
          auto result = registerPool.allocateRegister();
          machinecode.push_back(arm64::encode_mov_register(result, arm64::X0, arm64::reg_size_t::SIZE_64BIT));
          stack.emplace_back(result);
        }
        break;
      }
    case 0x28: // i32.load
    case 0x29: // i64.load
    case 0x2C: // i32.load8_s
    case 0x2D: // i32.load8_u
    case 0x2E: // i32.load16_s
    case 0x2F: // i32.load16_u
    {
      auto registerSize = arm64::reg_size_t::SIZE_64BIT;
      auto signedVariant = arm64::signed_variant_t::UNSIGNED;

      if (*(stream - 1) == 0x2C) {
        registerSize = arm64::reg_size_t::SIZE_8BIT;
        signedVariant = arm64::signed_variant_t::SIGNED;
      } else if (*(stream - 1) == 0x2D) {
        registerSize = arm64::reg_size_t::SIZE_8BIT;
        signedVariant = arm64::signed_variant_t::UNSIGNED;
      } else if (*(stream - 1) == 0x2E) {
        registerSize = arm64::reg_size_t::SIZE_16BIT;
        signedVariant = arm64::signed_variant_t::SIGNED;
      } else if (*(stream - 1) == 0x2F) {
        registerSize = arm64::reg_size_t::SIZE_16BIT;
        signedVariant = arm64::signed_variant_t::UNSIGNED;
      } else if (*(stream - 1) == 0x28) {
        registerSize = arm64::reg_size_t::SIZE_32BIT;
        signedVariant = arm64::signed_variant_t::SIGNED;
      }

      // decode memarg immediate
      auto alignment = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));
      auto offset = uint32_t(decoder::LEB128Decoder::decodeUnsigned(stream, streamEnd));

      // ensure that we have enough operands on the stack for the index
      asserte(stack.size() >= 1, "insufficient operands on stack for load");

      // get address from the stack
      auto index = stack.back();
      auto result = registerPool.allocateRegister();

      // encode address location to be loaded from global variable
      auto absoluteAddress = reinterpret_cast<std::uintptr_t>(linearMemoryAddressPtr);
      arm64::emit_mov_large_immediate(result, uint64_t(absoluteAddress), arm64::reg_size_t::SIZE_64BIT, machinecode);

      // load address of linear memory from pointer
      machinecode.push_back(
          arm64::encode_ldr_register(result, result, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL, 0, arm64::reg_size_t::SIZE_64BIT));

      // optional: add offset immediate to base address
      if (offset > 0) {
        machinecode.push_back(arm64::encode_add_immediate(result, result, offset, false, arm64::reg_size_t::SIZE_64BIT));
      }

      // add index to address
      machinecode.push_back(arm64::encode_add_register(result, result, index, 0, arm64::reg_shift_t::SHIFT_LSL, arm64::reg_size_t::SIZE_64BIT));

      // load actual global from memory location
      machinecode.push_back(arm64::encode_ldr_register(result, result, arm64::reg_t::XZR, arm64::index_extend_type_t::INDEX_LSL, 0, registerSize));

      stack.pop_back();
      registerPool.freeRegister(index);
      stack.emplace_back(result);
      break;
    }
    case 0x00:
      /** unreachable */
      {
        machinecode.push_back(arm64::encode_branch(getTraphandlerOffset(wasm::trap_code_t::UnreachableCodeReached, trapHandler, machinecode)));
        break;
      }
    case 0x01:
      /** nop */
      {
        machinecode.push_back(arm64::encode_nop());
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