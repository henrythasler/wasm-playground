#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "aarch64-instructions.hpp"
#include "helper.hpp"

namespace arm64 {

/** bit operations */
uint32_t encode_clz(reg_t rd, reg_t rn, reg_size_t size);
uint32_t encode_rbit(reg_t rd, reg_t rn, reg_size_t size);

/* bit shift and move */
uint32_t encode_ubfm(reg_t rd, reg_t rn, uint8_t immr6, uint8_t imms6, reg_size_t size);
uint32_t encode_lsr_immediate(reg_t rd, reg_t rn, uint8_t shift, reg_size_t size);

} // namespace arm64