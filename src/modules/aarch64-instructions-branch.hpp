#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "aarch64-instructions.hpp"
#include "debug.hpp"

namespace arm64 {

/** program flow */
uint32_t encode_ret(reg_t rn = X30);
uint32_t encode_branch(int32_t imm26);
uint32_t encode_branch_link(int32_t imm26);
uint32_t encode_branch_register(reg_t rn);
uint32_t encode_branch_link_register(reg_t rn);
uint32_t encode_branch_cond(branch_condition_t cond, int32_t imm19);
uint32_t encode_cbz(reg_t rt, int32_t imm19, reg_size_t size);
uint32_t encode_cbnz(reg_t rt, int32_t imm19, reg_size_t size);

/** address patching */
void patch_branch(uint32_t &offset, int32_t imm26);
void patch_branch_link(uint32_t &offset, int32_t imm26);
void patch_cbz(uint32_t &offset, int32_t imm19);

} // namespace arm64