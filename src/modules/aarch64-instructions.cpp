#include "aarch64-instructions.hpp"

namespace arm64 {

/**
 * This instruction loads a byte, halfword, word or doubleword from memory and writes it to a register using the unsigned offset addressing mode.
 * LDR rt, [rn], #imm12
 * LDRH rt, [rn], #imm12
 * LDRB rt, [rn], #imm12
 * @param rt destination register
 * @param rn base register
 * @param imm12 12-bit unsigned immediate offset
 * @param size 8-bit, 16-bit, 32-bit or 64-bit variant
 */
uint32_t encode_ldr_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_8BIT:
    instr = 0x39400000;
    imm12 = imm12 & 0xFFF; // 12-bit unsigned offset
    break;
  case reg_size_t::SIZE_16BIT:
    instr = 0x79400000;
    imm12 = (imm12 >> 1) & 0xFFF; // Scaled by 2
    break;
  case reg_size_t::SIZE_32BIT:
    instr = 0xB9400000;
    imm12 = (imm12 >> 2) & 0xFFF; // Scaled by 4
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xF9400000;
    imm12 = (imm12 >> 3) & 0xFFF; // Scaled by 8
    break;
  default:
    asserte(false, "encode_ldr_unsigned_offset(): invalid size value");
    break;
  }

  instr |= (imm12 & 0xFFF) << 10; // imm12 field
  instr |= (rn & 0x1F) << 5;      // Rn (base register)
  instr |= (rt & 0x1F);           // Rt (source register)

  return instr;
}

/**
 * This instruction stores a byte, halfword, word or a doubleword from a register to memory using the unsigned offset addressing mode.
 * STRH rt, [rn], #imm12
 * STRB rt, [rn], #imm12
 * STR rt, [rn], #imm12
 * @param rt source register
 * @param rn base register
 * @param imm12 12-bit unsigned immediate offset
 * @param size 8-bit, 16-bit, 32-bit or 64-bit variant
 */
uint32_t encode_str_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size) {
  uint32_t instr = 0;

  // Base opcode for STR unsigned offset
  switch (size) {
  case reg_size_t::SIZE_8BIT: // STRB
    instr = 0x39000000;
    imm12 = imm12 & 0xFFF; // 12-bit unsigned offset
    break;
  case reg_size_t::SIZE_16BIT: // STRH
    instr = 0x79000000;
    imm12 = (imm12 >> 1) & 0xFFF; // Scaled by 2
    break;
  case reg_size_t::SIZE_32BIT: // STR W
    instr = 0xB9000000;
    imm12 = (imm12 >> 2) & 0xFFF; // Scaled by 4
    break;
  case reg_size_t::SIZE_64BIT: // STR X
    instr = 0xF9000000;
    imm12 = (imm12 >> 3) & 0xFFF; // Scaled by 8
    break;
  default:
    asserte(false, "encode_str_unsigned_offset(): invalid size value");
    break;
  }
  instr |= (imm12 & 0xFFF) << 10; // imm12 field
  instr |= (rn & 0x1F) << 5;      // Rn (base register)
  instr |= (rt & 0x1F);           // Rt (source register)

  return instr;
}

/**
 * This instruction subtracts an optionally-shifted immediate value from a register value, and writes the result to the destination register.
 *
 * `SUB rd, rn, #imm12{, shift12}`
 * @param rd destination register
 * @param rn source register
 * @param imm12 12-bit immediate value
 * @param shift12 whether to left shift the immediate by 12 bits
 * @param size 32-bit or 64-bit variant
 */
uint32_t encode_sub_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x51000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xD1000000;
    break;
  default:
    asserte(false, "encode_sub_immediate(): invalid size value");
    break;
  }

  instr |= (shift12) ? 0x400000 : 0; // optional left shift (LSL #12)
  instr |= (imm12 & 0xFFF) << 10;    // imm12 field
  instr |= (rn & 0x1F) << 5;         // Rn (source register)
  instr |= (rd & 0x1F);              // Rd (desination register)

  return instr;
}

/**
 * This instruction subtracts an optionally-shifted immediate value from a register value, and writes the result to the destination register. It
 * updates the condition flags based on the result.
 *
 * `SUBS rd, rn|SP, #imm12{, shift12}`
 * @param rd destination register
 * @param rn source register
 * @param imm12 12-bit immediate value
 * @param shift12 whether to left shift the immediate by 12 bits
 * @param size 32-bit or 64-bit variant
 */
uint32_t encode_subs_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x71000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xf1000000;
    break;
  default:
    asserte(false, "encode_subs_immediate(): invalid size value");
    break;
  }

  instr |= (shift12) ? 0x400000 : 0; // optional left shift (LSL #12)
  instr |= (imm12 & 0xFFF) << 10;    // imm12 field
  instr |= (rn & 0x1F) << 5;         // Rn (source register)
  instr |= (rd & 0x1F);              // Rd (desination register)

  return instr;
}

/**
 * This instruction subtracts an optionally-shifted immediate value from a register value. It updates the condition flags based on the result, and
 * discards the result.
 *
 * `CMP rn|SP, #imm12{, shift12}`
 * @param rd destination register
 * @param rn source register
 * @param imm12 12-bit immediate value
 * @param shift12 whether to left shift the immediate by 12 bits
 * @param size 32-bit or 64-bit variant
 */
uint32_t encode_cmp_immediate(reg_t rn, uint16_t imm12, bool shift12, reg_size_t size) {
  return encode_subs_immediate((size == reg_size_t::SIZE_64BIT) ? XZR : WZR, rn, imm12, shift12, size);
}

/**
 * This instruction subtracts an optionally-shifted register value from a register value, and writes the result to the destination register.
 *
 * `SUB rd, rn, rm{, shift #imm6}`
 * @param rd destination register
 * @param rn first source register
 * @param rm second source register
 * @param imm6 shift amount in the range 0..63 (64-bit) or 0..31 (32-bit)
 * @param shift optional shift type to be applied to the second source register (00=LSL, 01=LSR, 10=ASR, 11=RESERVED)
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_sub_register(reg_t rd, reg_t rn, reg_t rm, uint8_t imm6, reg_shift_t shift, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x4b000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xcb000000;
    break;
  default:
    asserte(false, "encode_sub_register(): invalid size value");
    break;
  }

  instr |= (uint32_t(shift) & 0x03) << 22; // shift operator on rm
  instr |= (imm6 & 0x3F) << 10;            // shift amount in imm6 field
  instr |= (rm & 0x1F) << 16;              // Rm (second source register)
  instr |= (rn & 0x1F) << 5;               // Rn (source register)
  instr |= (rd & 0x1F);                    // Rd (desination register)

  return instr;
}

/**
 * This instruction subtracts an optionally-shifted register value from a register value, and writes the result to the destination register. It
 * updates the condition flags based on the result.
 *
 * `SUBS rd, rn, rm{, shift #imm6}`
 * @param rd destination register
 * @param rn first source register
 * @param rm second source register
 * @param imm6 shift amount in the range 0..63 (64-bit) or 0..31 (32-bit)
 * @param shift optional shift type to be applied to the second source register (00=LSL, 01=LSR, 10=ASR, 11=RESERVED)
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_subs_shifted_register(reg_t rd, reg_t rn, reg_t rm, reg_shift_t shift, uint8_t imm6, reg_size_t size) {
  uint32_t instr = 0;
  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x6B000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xEB000000;
    break;
  default:
    asserte(false, "encode_subs_shifted_register(): invalid size value");
    break;
  }

  instr |= (uint32_t(shift) & 0x3) << 22; // shift type
  instr |= (imm6 & 0x3F) << 10;           // shift amount (0-63 for 64-bit, 0-31 for 32-bit)
  instr |= (rm & 0x1F) << 16;             // Rm (operand register)
  instr |= (rn & 0x1F) << 5;              // Rn (source register)
  instr |= (rd & 0x1F);                   // Rd (destination register)

  return instr;
}

/**
 * This instruction subtracts an optionally-shifted register value from a register value. It updates the condition flags based on the result, and
 * discards the result.
 *
 * `CMP rn, rm{, shift #imm6}`
 * @param rn first source register
 * @param rm second source register
 * @param imm6 shift amount in the range 0..63 (64-bit) or 0..31 (32-bit)
 * @param shift optional shift type to be applied to the second source register (00=LSL, 01=LSR, 10=ASR, 11=RESERVED)
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_cmp_shifted_register(reg_t rn, reg_t rm, reg_shift_t shift, uint8_t imm6, reg_size_t size) {
  return encode_subs_shifted_register((size == reg_size_t::SIZE_64BIT) ? XZR : WZR, rn, rm, shift, imm6, size);
}

/**
 * This instruction subtracts a sign or zero-extended register value, followed by an optional left shift amount, from a register value, and writes
 * the result to the destination register. The argument that is extended from the <Rm> register can be a byte, halfword, word, or doubleword. It
 * updates the condition flags based on the result. SUBS rd, rn|SP, rm{, extend {#imm3}}
 * @param rd destination register
 * @param rn first source register
 * @param rm second source register
 * @param option extension to be applied to the second source operand
 * @param imm3 the left shift amount to be applied after extension in the range 0..4
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_subs_extended_register(reg_t rd, reg_t rn, reg_t rm, extend_type_t option, uint8_t imm3, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x6b200000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xeb200000;
    break;
  default:
    asserte(false, "encode_subs_extended_register(): invalid size value");
    break;
  }

  instr |= (rm & 0x1F) << 16;              // Rm (operand register)
  instr |= (uint32_t(option) & 0x7) << 13; // extend type
  instr |= (imm3 & 0x7) << 10;             // shift amount (0-4)
  instr |= (rn & 0x1F) << 5;               // Rn (source register)
  instr |= (rd & 0x1F);                    // Rd (destination register)

  return instr;
}

/**
 * This instruction adds a register value and an optionally-shifted immediate value, and writes the result to the destination register.
 * ADD rd, rn, #imm12{, shift12}
 * @param rd destination register
 * @param rn source register
 * @param imm12 12-bit immediate value
 * @param shift12 whether to left shift the immediate by 12 bits
 * @param size 32-bit or 64-bit variant
 */
uint32_t encode_add_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x11000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0x91000000;
    break;
  default:
    asserte(false, "encode_add_immediate(): invalid size value");
    break;
  }

  instr |= (shift12) ? 0x400000 : 0; // optional left shift (LSL #12)
  instr |= (imm12 & 0xFFF) << 10;    // imm12 field
  instr |= (rn & 0x1F) << 5;         // Rn (source register)
  instr |= (rd & 0x1F);              // Rd (desination register)

  return instr;
}

/**
 * This instruction adds a register value and an optionally-shifted register value, and writes the result to the destination register.
 * ADD rd, rn, rm{, shift #imm6}
 * @param rd destination register
 * @param rn first source register
 * @param rm second source register
 * @param imm6 shift amount in the range 0..63 (64-bit) or 0..31 (32-bit)
 * @param shift optional shift type to be applied to the second source register (00=LSL, 01=LSR, 10=ASR, 11=RESERVED)
 * @return the encoded instruction
 */
uint32_t encode_add_register(reg_t rd, reg_t rn, reg_t rm, uint8_t imm6, reg_shift_t shift, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x0b000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0x8b000000;
    break;
  default:
    asserte(false, "encode_add_register(): invalid size value");
    break;
  }

  instr |= (uint32_t(shift) & 0x03) << 22; // shift operator on rm
  instr |= (imm6 & 0x3F) << 10;            // shift amount in imm6 field
  instr |= (rm & 0x1F) << 16;              // Rm (second source register)
  instr |= (rn & 0x1F) << 5;               // Rn (source register)
  instr |= (rd & 0x1F);                    // Rd (desination register)

  return instr;
}

/**
 * This instruction multiplies two register values, adds a third register value, and writes the result to the destination register.
 * MADD rd, rn, rm, ra
 * where: rd = ra + rn * rm
 * @param rd destination register
 * @param rn multiplicand source register
 * @param rm multiplier source register
 * @param ra addend source register
 * @return the encoded instruction
 */
uint32_t encode_madd_register(reg_t rd, reg_t rn, reg_t rm, reg_t ra, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x1b000000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0x9b000000;
    break;
  default:
    asserte(false, "encode_madd_register(): invalid size value");
    break;
  }

  instr |= (rm & 0x1F) << 16; // Rm (multiplier source register)
  instr |= (ra & 0x1F) << 10; // Ra (addend source register)
  instr |= (rn & 0x1F) << 5;  // Rn (multiplicand source register)
  instr |= (rd & 0x1F);       // Rd (desination register)

  return instr;
}

uint32_t encode_mul_register(reg_t rd, reg_t rn, reg_t rm, reg_size_t size) {
  return encode_madd_register(rd, rn, rm, WZR, size);
}

/**
 * This instruction copies the value in a source register to the destination register.
 * This is an alias for ORR Xd, XZR, Xm
 * MOV Xd, Xm
 * @param rd destination register
 * @param rm source register
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_mov_register(reg_t rd, reg_t rm, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x2A0003E0; // 32-bit ORR
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xAA0003E0; // 64-bit ORR
    break;
  default:
    asserte(false, "encode_mov_register(): invalid size value");
    break;
  }

  instr |= (rm & 0x1F) << 16; // Rm (source register)
  instr |= (rd & 0x1F);       // Rd (destination register)

  return instr;
}

/**
 * This instruction copies the value of a register to or from the stack pointer.
 * sh == '0' && imm12 == '000000000000' && (Rd == '11111' || Rn == '11111')
 * MOV SP, Rn
 * MOV Rd, SP
 * @param rd destination register
 * @param rn source register
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_mov_sp(reg_t rd, reg_t rn, reg_size_t size) {
  return encode_add_immediate(rd, rn, 0, false, size);
}

/**
 * This instruction moves a 16-bit immediate value to a register.
 * This is an alias of MOVZ
 * MOV Wd, #imm16
 * @param rd destination register
 * @param imm16 16-bit immediate value
 * @param shift bits by which to shift the immediate left
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_mov_immediate(reg_t rd, uint16_t imm16, uint8_t shift, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x52800000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xD2800000;
    break;
  default:
    asserte(false, "encode_mov_immediate(): invalid size value");
    break;
  }

  // hw = shift / 16 (which 16-bit position)
  uint8_t hw = shift >> 4;

  instr |= (hw & 0x3) << 21;      // hw field (0-3 for 64-bit, 0-1 for 32-bit)
  instr |= (imm16 & 0xFFFF) << 5; // imm16 field
  instr |= (rd & 0x1F);           // Rd (destination register)

  return instr;
}

/**
 * This instruction moves a 16-bit immediate value to a register, zeroing the rest of the register.
 * MOVZ Wd, #imm16 {, LSL #shift}
 * @param rd destination register
 * @param imm16 16-bit immediate value
 * @param shift bits by which to shift the immediate left
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_movz(reg_t rd, uint16_t imm16, uint8_t shift, reg_size_t size) {
  return encode_mov_immediate(rd, imm16, shift, size);
}

/**
 * This instruction moves a 16-bit immediate value to a register, keeping the rest of the register unchanged.
 * MOVK Wd, #imm16 {, LSL #shift}
 * @param rd destination register
 * @param imm16 16-bit immediate value
 * @param shift bits by which to shift the immediate left
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_movk(reg_t rd, uint16_t imm16, uint8_t shift, reg_size_t size) {
  uint32_t instr = 0;

  switch (size) {
  case reg_size_t::SIZE_32BIT:
    instr = 0x72800000;
    break;
  case reg_size_t::SIZE_64BIT:
    instr = 0xF2800000;
    break;
  default:
    asserte(false, "encode_mov_immediate(): invalid size value");
    break;
  }

  uint8_t hw = shift >> 4;

  instr |= (hw & 0x3) << 21;      // hw field
  instr |= (imm16 & 0xFFFF) << 5; // imm16 field
  instr |= (rd & 0x1F);           // Rd (destination register)

  return instr;
}

/**
 * This instruction branches unconditionally to an address in a register. This instruction provides a hint that this is a subroutine return.
 * rn defaults to X30
 * RET rn
 * @param rn register containing the return address (defaults to X30)
 * @return the encoded instruction
 */
uint32_t encode_ret(reg_t rn) {
  return 0xD65F0000 | ((rn & 0x1F) << 5);
}

/**
 * This instruction branches conditionally to a label at a PC-relative offset. This instruction provides a hint that this is not a subroutine call or
 * return.
 *
 * `B.cond imm19`
 * @param cond one of the standard conditions
 * @param imm19 offset from the address of this instruction, in the range +/-1MB
 * @return the encoded instruction
 */
uint32_t encode_branch_cond(branch_condition_t cond, int32_t imm19) {
  uint32_t instr = 0x54000000;

  instr |= ((imm19 >> 2) & 0x7FFFF) << 5; // imm19 offset
  instr |= uint32_t(cond);                // branch condition

  return instr;
}

/**
 * This instruction does nothing, other than advance the value of the program counter by 4.
 */
uint32_t encode_nop() {
  return 0xD503201F;
}
} // namespace arm64