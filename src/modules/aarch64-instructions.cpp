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
 * SUB rd, rn, #imm12{, shift12}
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
 * This instruction copies the value in a source register to the destination register.
 * This is an alias for ORR Xd, XZR, Xm
 * MOV Xd, Xm
 * @param rd destination register
 * @param rm source register
 * @param size 32-bit or 64-bit variant
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
 * @param rn register containing the return address
 */
uint32_t encode_ret(reg_t rn) {
  return 0xD65F0000 | ((rn & 0x1F) << 5);
}
} // namespace arm64