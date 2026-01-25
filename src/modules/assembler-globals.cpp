#include "assembler-globals.hpp"

namespace assembler {

void parseGlobalsSection(Globals &globals, webassembly_t::global_section_t &global_section) {
  auto &wasm_globals = *global_section.globals();

  for (const auto &global : wasm_globals) {
    globals.entries.push_back(GlobalVariable{static_cast<bool>(global->is_mutable()), global->valtype(), 8});
  }
}

uint64_t parseInitExpr(void) {
  return 0;
}

} // namespace assembler