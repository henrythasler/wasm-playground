#include "aarch64-instructions-bit.hpp"

namespace arm64 {

/**
 * This instruction counts the number of consecutive binary zero bits, starting from the most significant bit in the source register, and places the
 * count in the destination register.
 *
 * `CLZ rd, rn`
 * @param rd destination register
 * @param rm source register
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_clz(reg_t rd, reg_t rn, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x5ac01000, 0xdac01000, "encode_clz");
  instr |= (rn & 0x1F) << 5; // Rn (dividend source register)
  instr |= (rd & 0x1F);      // Rd (desination register)
  return instr;
}

/**
 * This instruction reverses the bit order in a register.
 *
 * `RBIT rd, rn`
 * @param rd destination register
 * @param rm source register
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_rbit(reg_t rd, reg_t rn, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x5ac00000, 0xdac00000, "encode_rbit");
  instr |= (rn & 0x1F) << 5; // Rn (dividend source register)
  instr |= (rd & 0x1F);      // Rd (desination register)
  return instr;
}

/**
 * This instruction performs a bitwise AND of two registers, with an optional shift applied to the second source register, and writes the result to
 * the destination register.
 *
 * `AND rd, rn, rm{, shift #imm6}`
 * @param rd destination register
 * @param rn first source register
 * @param rm second source register
 * @param shift optional shift type to be applied to the second source register (00=LSL, 01=LSR, 10=ASR, 11=RESERVED)
 * @param imm6 shift amount in the range 0..63 (64-bit) or 0..31 (32-bit)
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_and(reg_t rd, reg_t rn, reg_t rm, reg_shift_t shift, uint8_t imm6, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x0a000000, 0x8a000000, "encode_and");
  instr |= (uint32_t(shift) & 0x03) << 22; // shift operator on rm
  if (size == reg_size_t::SIZE_32BIT) {
    imm6 &= 0x1F; // for 32-bit variant, only allow shift amounts 0-31
  } else {
    imm6 &= 0x3F; // for 64-bit variant, allow shift amounts 0-63
  }
  instr |= (imm6 & 0x3F) << 10; // shift amount in imm6 field
  instr |= (rm & 0x1F) << 16;   // Rm (second register)
  instr |= (rn & 0x1F) << 5;    // Rn (first register)
  instr |= (rd & 0x1F);         // Rd (desination register)
  return instr;
}

/**
 * Unsigned bitfield move
 *
 * `UBFM rd, rn, #immr, #imms`
 * @param rd destination register
 * @param rn source register
 * @param immr6 6-bit immediate value for right rotate amount
 * @param imms6 6-bit immediate value for the leftmost bit number to be moved from the source
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_ubfm(reg_t rd, reg_t rn, uint8_t immr6, uint8_t imms6, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x53000000, 0xD3400000, "encode_ubfm");
  instr |= (immr6 & 0x3F) << 16; // immr
  instr |= (imms6 & 0x3F) << 10; // imms
  instr |= (rn & 0x1F) << 5;     // Rn (source register)
  instr |= (rd & 0x1F);          // Rd (destination register)
  return instr;
}

/**
 * Logical Shift Right (immediate). This instruction shifts a register value right by an immediate number of bits, shifting in zeros, and writes the
 * result to the destination register.
 *
 * `LSR rd, rn, #shift`
 * @param rd destination register
 * @param rn source register
 * @param shift amount to shift
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_lsr_immediate(reg_t rd, reg_t rn, uint8_t shift, reg_size_t size) {
  return encode_ubfm(rd, rn, shift, (size == reg_size_t::SIZE_32BIT) ? 31 : 63, size);
}

} // namespace arm64