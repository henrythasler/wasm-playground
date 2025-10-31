#include "aarch64-instructions.hpp"
#include "helper.hpp"
#include "webassembly.h"

namespace assembler {
arm64::reg_size_t map_valtype_to_regsize(const webassembly_t::val_types_t type);
}