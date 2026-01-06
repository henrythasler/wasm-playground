#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "aarch64-instructions.hpp"
#include "helper.hpp"

namespace arm64 {

/** bit handling */
uint32_t encode_clz(reg_t rd, reg_t rn, reg_size_t size);
uint32_t encode_rbit(reg_t rd, reg_t rn, reg_size_t size);

} // namespace arm64