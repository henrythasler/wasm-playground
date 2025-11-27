#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "aarch64-instructions.hpp"
#include "helper.hpp"

namespace arm64 {

/** memory operations */
uint32_t encode_ldr_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);
uint32_t encode_str_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);
uint32_t encode_stp(reg_t rt1, reg_t rt2, reg_t rn, int16_t imm7, addressing_mode_t mode, reg_size_t size);

} // namespace arm64