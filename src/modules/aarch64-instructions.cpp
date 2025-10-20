#include "aarch64-instructions.hpp"

namespace arm64 {

// Encode STR with unsigned offset: STR Xt, [Xn, #imm]
uint32_t encode_str_immediate(reg_t rt, reg_t rn, uint16_t imm12, size4_t size) {
  uint32_t instr = 0;

  // Base opcode for STR unsigned offset
  switch (size) {
  case size4_t::SIZE_8BIT: // STRB
    instr = 0x39000000;
    imm12 = imm12 & 0xFFF; // 12-bit unsigned offset
    break;
  case size4_t::SIZE_16BIT: // STRH
    instr = 0x79000000;
    imm12 = (imm12 >> 1) & 0xFFF; // Scaled by 2
    break;
  case size4_t::SIZE_32BIT: // STR W
    instr = 0xB9000000;
    imm12 = (imm12 >> 2) & 0xFFF; // Scaled by 4
    break;
  case size4_t::SIZE_64BIT: // STR X
    instr = 0xF9000000;
    imm12 = (imm12 >> 3) & 0xFFF; // Scaled by 8
    break;
  default:
    asserte(false, "encode_str_immediate(): invalid size value");
    break;
  }

  instr |= (imm12 & 0xFFF) << 10; // imm12 field
  instr |= (rn & 0x1F) << 5;      // Rn (base register)
  instr |= (rt & 0x1F);           // Rt (source register)

  return instr;
}

uint32_t encode_sub_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, size2_t size) {
  uint32_t instr = 0;

  switch (size) {
  case size2_t::SIZE_32BIT:
    instr = 0x51000000;
    break;
  case size2_t::SIZE_64BIT:
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

uint32_t encode_add_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, size2_t size) {
  uint32_t instr = 0;

  switch (size) {
  case size2_t::SIZE_32BIT:
    instr = 0x11000000;
    break;
  case size2_t::SIZE_64BIT:
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

uint32_t encode_mov_sp(reg_t rd, reg_t rn, size2_t size) {
  return encode_add_immediate(rd, rn, 0, false, size);
}

uint32_t encode_ret(reg_t rn) {
  return 0xD65F0000 | ((rn & 0x1F) << 5);
}
} // namespace arm64