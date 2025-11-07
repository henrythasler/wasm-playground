#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "helper.hpp"

namespace arm64 {
#define AARCH64_INT32_SIZE 4
#define AARCH64_INT64_SIZE 8
#define AARCH64_STACK_ALIGNMENT 16

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
} reg_t;

enum class reg_size_t { SIZE_8BIT, SIZE_16BIT, SIZE_32BIT, SIZE_64BIT };
enum class reg_shift_t { SHIFT_LSL, SHIFT_LSR, SHIFT_ASR, SHIFT_ROR };

// Extend types for register operands
enum class extend_type_t {
  EXTEND_UXTB = 0, // Unsigned extend byte
  EXTEND_UXTH = 1, // Unsigned extend halfword
  EXTEND_UXTW = 2, // Unsigned extend word
  EXTEND_UXTX = 3, // Unsigned extend doubleword
  EXTEND_SXTB = 4, // Signed extend byte
  EXTEND_SXTH = 5, // Signed extend halfword
  EXTEND_SXTW = 6, // Signed extend word
  EXTEND_SXTX = 7  // Signed extend doubleword
};

enum class branch_condition_t {
  EQ = 0b0000, // equal
  NE = 0b0001, // not equal
  CS = 0b0010, // Carry set (identical to HS)
  HS = 0b0010, // Unsigned Higher or same (identical to CS)
  CC = 0b0011, // Carry clear (identical to LO)
  LO = 0b0011, // Unsigned Lower (identical to CC)
  MI = 0b0100, // Minus or negative result
  PL = 0b0101, // Positive or zero result
  VS = 0b0110, // Signed Overflow
  VC = 0b0111, // No signed Overflow
  HI = 0b1000, // Unsigned higher
  LS = 0b1001, // Unsigned lower or same
  GE = 0b1010, // Signed greater than or equal
  LT = 0b1011, // Signed less than
  GT = 0b1100, // Signed greater than
  LE = 0b1101, // Signed less than or equal
  AL = 0b1110, // Always (this is the default)
  NV = 0b1111, // Never executed
};

enum class signed_variant_t { UNSIGNED = 0x00, SIGNED = 0x01 };

/** memory operations */
uint32_t encode_ldr_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);
uint32_t encode_str_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);

/** arithmetic operations*/
uint32_t encode_sub_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size);
uint32_t encode_sub_register(reg_t rd, reg_t rn, reg_t rm, uint8_t imm6, reg_shift_t shift, reg_size_t size);
uint32_t encode_subs_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size);
uint32_t encode_cmp_immediate(reg_t rn, uint16_t imm12, bool shift12, reg_size_t size);
uint32_t encode_subs_shifted_register(reg_t rd, reg_t rn, reg_t rm, reg_shift_t shift, uint8_t imm6, reg_size_t size);
uint32_t encode_cmp_shifted_register(reg_t rn, reg_t rm, reg_shift_t shift, uint8_t imm6, reg_size_t size);
uint32_t encode_subs_extended_register(reg_t rd, reg_t rn, reg_t rm, extend_type_t option, uint8_t imm3, reg_size_t size);

uint32_t encode_add_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size);
uint32_t encode_add_register(reg_t rd, reg_t rn, reg_t rm, uint8_t imm6, reg_shift_t shift, reg_size_t size);
uint32_t encode_madd_register(reg_t rd, reg_t rn, reg_t rm, reg_t ra, reg_size_t size);
uint32_t encode_mul_register(reg_t rd, reg_t rn, reg_t rm, reg_size_t size);
uint32_t encode_div_register(reg_t rd, reg_t rn, reg_t rm, signed_variant_t variant, reg_size_t size);

/** register handling */
uint32_t encode_mov_register(reg_t rd, reg_t rm, reg_size_t size);
uint32_t encode_mov_sp(reg_t rd, reg_t rn, reg_size_t size);
uint32_t encode_mov_immediate(reg_t rd, uint16_t imm, uint8_t shift, reg_size_t size);
uint32_t encode_movz(reg_t rd, uint16_t imm, uint8_t shift, reg_size_t size);
uint32_t encode_movk(reg_t rd, uint16_t imm16, uint8_t shift, reg_size_t size);

/** program flow */
uint32_t encode_ret(reg_t rn = X30);
uint32_t encode_branch(int32_t imm26);
uint32_t encode_branch_register(reg_t rn);
uint32_t encode_branch_cond(branch_condition_t cond, int32_t imm19);
uint32_t encode_cbz(reg_t rt, int32_t imm19, reg_size_t size);
uint32_t encode_cbnz(reg_t rt, int32_t imm19, reg_size_t size);

/** misc */
uint32_t encode_nop();
uint32_t encode_brk(uint16_t imm16 = 0);
uint32_t encode_udf();

} // namespace arm64