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

/** memory operations */
uint32_t encode_ldr_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);
uint32_t encode_str_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);

/** arithmetic operations*/
uint32_t encode_sub_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size);
uint32_t encode_add_immediate(reg_t rd, reg_t rn, uint16_t imm12, bool shift12, reg_size_t size);

/** register handling */
uint32_t encode_mov_sp(reg_t rd, reg_t rn, reg_size_t size);

/** program flow */
uint32_t encode_ret(reg_t rn = X30);

} // namespace arm64