#include "wasm.hpp"
namespace wasm {

const TrapCategory &trap_category() {
  static TrapCategory instance;
  return instance;
}

std::error_code make_trap_error(trap_code_t code) {
  return {static_cast<int>(code), trap_category()};
}

} // namespace wasm