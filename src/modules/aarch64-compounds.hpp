#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <vector>

#include "aarch64-instructions.hpp"

namespace arm64 {

void emit_ctz(reg_t rd, reg_t rn, reg_size_t size, std::vector<uint32_t> &machinecode);

} // namespace arm64