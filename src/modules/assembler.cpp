#include "assembler.hpp"

namespace assembler {
arm64::reg_size_t map_valtype_to_regsize(const webassembly_t::val_types_t type) {
  switch (type) {
  case webassembly_t::VAL_TYPES_I32:
    return arm64::reg_size_t::SIZE_32BIT;
  case webassembly_t::VAL_TYPES_I64:
    return arm64::reg_size_t::SIZE_64BIT;
  default:
    asserte(false, "Unsupported value type for register size mapping");
    return arm64::reg_size_t::SIZE_32BIT; // To suppress compiler warning
  }
}
} // namespace assembler