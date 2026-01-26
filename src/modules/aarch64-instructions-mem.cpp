#include "aarch64-instructions-mem.hpp"

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
 * This instruction loads a word or doubleword from memory and writes it to a register using the register offset addressing mode.
 *
 * `LDR rt, [rn, rm{, extend {#imm3}}]`
 * @param rt destination register
 * @param rn base register
 * @param rm offset register
 * @param option extension to be applied to the offset register
 * @param shift_amount the left shift amount to be applied after extension in the range 0..4
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_ldr_register(reg_t rt, reg_t rn, reg_t rm, index_extend_type_t option, uint8_t shift_amount, reg_size_t size) {
  uint32_t instr = 0;

  // Base opcode for LDR register
  switch (size) {
  // case reg_size_t::SIZE_8BIT: // LDRB
  //   instr = 0x38607800;
  //   break;
  // case reg_size_t::SIZE_16BIT: // LDRH
  //   instr = 0x79000000;
  //   break;
  case reg_size_t::SIZE_32BIT: // LDR with index shifted by 2 bits
    asserte((shift_amount == 0) || (shift_amount == 2), "encode_ldr_register(): invalid shift amount for 32-bit load");
    instr = 0xB8600800 | (shift_amount == 2 ? 0x1000 : 0) | (static_cast<uint32_t>(option) << 13);
    break;
  case reg_size_t::SIZE_64BIT: // LDR
    asserte((shift_amount == 0) || (shift_amount == 3), "encode_ldr_register(): invalid shift amount for 64-bit load");
    instr = 0xF8600800 | (shift_amount == 3 ? 0x1000 : 0) | (static_cast<uint32_t>(option) << 13);
    break;
  default:
    asserte(false, "encode_ldr_register(): invalid size value");
    break;
  }
  instr |= (rm & 0x1F) << 16; // Rm (index register)
  instr |= (rn & 0x1F) << 5;  // Rn (base register)
  instr |= (rt & 0x1F);       // Rt (source register)

  return instr;
}

/**
 * This instruction calculates an address from a base register value and an offset register value, and stores a 32-bit word or a 64-bit doubleword to
 * the calculated address, from a register.
 *
 * `STR w0, [x0, x0, lsl #2]`
 * @param rt source register
 * @param rn base register
 * @param rm index register
 * @param option extension to be applied to the index register
 * @param shift_amount the left shift amount to be applied after extension in the range 0..4
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_str_register(reg_t rt, reg_t rn, reg_t rm, index_extend_type_t option, uint8_t shift_amount, reg_size_t size) {
  uint32_t instr = 0;

  // Base opcode for STR register
  switch (size) {
  // case reg_size_t::SIZE_8BIT: // STRB
  //   instr = 0x0;
  //   break;
  // case reg_size_t::SIZE_16BIT: // STRH
  //   instr = 0x0;
  //   break;
  case reg_size_t::SIZE_32BIT: // STR with index shifted by 2 bits
    asserte((shift_amount == 0) || (shift_amount == 2), "encode_str_register(): invalid shift amount for 32-bit load");
    instr = 0xB8200800 | (shift_amount == 2 ? 0x1000 : 0) | (static_cast<uint32_t>(option) << 13);
    break;
  case reg_size_t::SIZE_64BIT: // STR
    asserte((shift_amount == 0) || (shift_amount == 3), "encode_str_register(): invalid shift amount for 64-bit load");
    instr = 0xF8200800 | (shift_amount == 3 ? 0x1000 : 0) | (static_cast<uint32_t>(option) << 13);
    break;
  default:
    asserte(false, "encode_str_register(): invalid size value");
    break;
  }
  instr |= (rm & 0x1F) << 16; // Rm (index register)
  instr |= (rn & 0x1F) << 5;  // Rn (base register)
  instr |= (rt & 0x1F);       // Rt (source register)

  return instr;
}

/**
 * This instruction calculates an address from a base register value and an immediate offset, and stores two 32-bit words or two 64-bit doublewords to
 * the calculated address, from two registers.
 *
 * `STP rt1, rt2, [rn, #imm7]{!}`
 * @param rt1 first source register
 * @param rt2 second source register
 * @param rn base register
 * @param imm7 7-bit signed immediate offset
 * @param mode addressing mode (post-index, signed offset, pre-index)
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_stp(reg_t rt1, reg_t rt2, reg_t rn, int16_t imm7, addressing_mode_t mode, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x28000000, 0xA8000000, "encode_stp");
  auto imm = imm7 >> ((size == reg_size_t::SIZE_64BIT) ? 3 : 2); // scale by 8 for 64-bit, 4 for 32-bit
  instr |= (imm & 0x7F) << 15;                                   // imm7 field
  instr |= (rt2 & 0x1F) << 10;                                   // Rt2 (second source register)
  instr |= (rn & 0x1F) << 5;                                     // Rn (base register)
  instr |= (rt1 & 0x1F);                                         // Rt1 (first source register)
  instr |= (static_cast<uint32_t>(mode) & 0x3) << 23;            // addressing mode
  return instr;
}

/**
 * This instruction calculates an address from a base register value and an immediate offset, loads two 32-bit words or two 64-bit doublewords from
 * memory, and writes them to two registers.
 *
 * `LDP rt1, rt2, [rn, #imm7]{!}`
 * @param rt1 first destination register
 * @param rt2 second destination register
 * @param rn base register
 * @param imm7 7-bit signed immediate offset
 * @param mode addressing mode (post-index, signed offset, pre-index)
 * @param size 32-bit or 64-bit variant
 * @return the encoded instruction
 */
uint32_t encode_ldp(reg_t rt1, reg_t rt2, reg_t rn, int16_t imm7, addressing_mode_t mode, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x28400000, 0xA8400000, "encode_ldp");
  auto imm = imm7 >> ((size == reg_size_t::SIZE_64BIT) ? 3 : 2); // scale by 8 for 64-bit, 4 for 32-bit
  instr |= (imm & 0x7F) << 15;                                   // imm7 field
  instr |= (rt2 & 0x1F) << 10;                                   // Rt2 (second source register)
  instr |= (rn & 0x1F) << 5;                                     // Rn (base register)
  instr |= (rt1 & 0x1F);                                         // Rt1 (first source register)
  instr |= (static_cast<uint32_t>(mode) & 0x3) << 23;            // addressing mode
  return instr;
}

/**
 * This instruction adds an immediate value that is shifted left by 12 bits, to the PC value to form a PC-relative address, with the bottom 12 bits
 * masked out, and writes the result to the destination register.
 *
 * `ADRP rd, imm21`
 * @param rd destination register
 * @param address Is the program label whose 4KB page address is to be calculated.
 * @return the encoded instruction
 */
uint32_t encode_adrp(reg_t rd, uint64_t address) {
  uint32_t instr = 0x90000000;

  auto imm = address >> 12;               // Shift right by 12 to get the page number
  instr |= (imm & 0x3) << 29;             // immlo
  instr |= (((imm >> 2) & 0x7FFFF) << 5); // immhi
  instr |= (rd & 0x1F);                   // Rd (desination register)

  return instr;
}

void patch_adrp(uint32_t &offset, uint64_t address) {
  auto imm = address >> 12;                // Shift right by 12 to get the page number
  offset &= 0x9F00001F;                    // clear existing values
  offset |= (imm & 0x3) << 29;             // immlo
  offset |= (((imm >> 2) & 0x7FFFF) << 5); // immhi
}

} // namespace arm64