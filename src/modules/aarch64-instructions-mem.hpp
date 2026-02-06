#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "aarch64-instructions.hpp"
#include "helper.hpp"

namespace arm64 {

/** memory operations */
uint32_t encode_ldr_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);
uint32_t encode_str_unsigned_offset(reg_t rt, reg_t rn, uint16_t imm12, reg_size_t size);
uint32_t encode_ldr_register(reg_t rt, reg_t rn, reg_t rm, index_extend_type_t option, uint8_t shift_amount, mem_size_t mem, reg_size_t size);
uint32_t encode_ldr_register_signed(reg_t rt, reg_t rn, reg_t rm, index_extend_type_t option, uint8_t shift_amount, mem_size_t mem, reg_size_t size);
uint32_t encode_str_register(reg_t rt, reg_t rn, reg_t rm, index_extend_type_t option, uint8_t shift_amount, mem_size_t mem, reg_size_t size);
uint32_t encode_stp(reg_t rt1, reg_t rt2, reg_t rn, int16_t imm7, addressing_mode_t mode, reg_size_t size);
uint32_t encode_ldp(reg_t rt1, reg_t rt2, reg_t rn, int16_t imm7, addressing_mode_t mode, reg_size_t size);

/** memory page instructions */
uint32_t encode_adrp(reg_t rd, uint64_t address);
void patch_adrp(uint32_t &offset, uint64_t address);

} // namespace arm64