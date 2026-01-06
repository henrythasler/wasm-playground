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

} // namespace arm64