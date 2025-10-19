#include <stdbool.h>
#include <stdint.h>

#include "helper.hpp"

// AArch64 Register enumeration
typedef enum {
  X0 = 0,
  X1,
  X2,
  X3,
  X4,
  X5,
  X6,
  X7,
  X8,
  X9,
  X10,
  X11,
  X12,
  X13,
  X14,
  X15,
  X16,
  X17,
  X18,
  X19,
  X20,
  X21,
  X22,
  X23,
  X24,
  X25,
  X26,
  X27,
  X28,
  X29,
  X30,
  SP = 31,  // Stack Pointer
  XZR = 31, // Zero Register (context dependent)

  // 32-bit register aliases
  W0 = 0,
  W1,
  W2,
  W3,
  W4,
  W5,
  W6,
  W7,
  W8,
  W9,
  W10,
  W11,
  W12,
  W13,
  W14,
  W15,
  W16,
  W17,
  W18,
  W19,
  W20,
  W21,
  W22,
  W23,
  W24,
  W25,
  W26,
  W27,
  W28,
  W29,
  W30,
  WSP = 31,
  WZR = 31,

  // Special register aliases
  FP = 29, // Frame Pointer (X29)
  LR = 30  // Link Register (X30)
} aarch64_reg_t;

// STR instruction encoding for AArch64
// Supports multiple addressing modes

enum class str_mode_t {
  STR_UNSIGNED_OFFSET, // STR Xt, [Xn, #imm]
  STR_REGISTER_OFFSET, // STR Xt, [Xn, Xm{, LSL #imm}]
  STR_PRE_INDEX,       // STR Xt, [Xn, #imm]!
  STR_POST_INDEX       // STR Xt, [Xn], #imm
};

enum class size4_t {
  SIZE_8BIT,  // STRB
  SIZE_16BIT, // STRH
  SIZE_32BIT, // STR (W register)
  SIZE_64BIT  // STR (X register)
};

// Encode STR with unsigned offset: STR Xt, [Xn, #imm]
uint32_t encode_str_immediate(aarch64_reg_t rt, aarch64_reg_t rn, uint16_t imm12, size4_t size) {
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

enum class size2_t {
  SIZE_32BIT, // W register
  SIZE_64BIT  // X register
};

uint32_t encode_sub_immediate(aarch64_reg_t rd, aarch64_reg_t rn, uint16_t imm12, bool shift12, size2_t size) {
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

uint32_t encode_add_immediate(aarch64_reg_t rd, aarch64_reg_t rn, uint16_t imm12, bool shift12, size2_t size) {
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