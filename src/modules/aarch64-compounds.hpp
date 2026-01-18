#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <vector>

#include "aarch64-instructions-bit.hpp"
#include "aarch64-instructions.hpp"

namespace arm64 {

void emit_ctz(reg_t rd, reg_t rn, reg_size_t size, std::vector<uint32_t> &machinecode);
void emit_mov_large_immediate(reg_t rd, uint64_t immediate, reg_size_t size, std::vector<uint32_t> &machinecode);

} // namespace arm64