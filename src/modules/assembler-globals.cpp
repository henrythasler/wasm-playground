#include "assembler-globals.hpp"

namespace assembler {

std::vector<uint32_t> Globals::serialize() {
  std::vector<uint32_t> serialized;
  for(auto entry: entries) {
    serialized.push_back(entry.value);
  }
  return serialized;
}

void parseGlobalsSection(Globals &globals, webassembly_t::global_section_t &global_section) {
  auto &wasm_globals = *global_section.globals();

  for (const auto &global : wasm_globals) {
    asserte(global->init_expr().size() > 0, "Found empty initExpr for global");
    auto rawInitExpr = global->init_expr();
    std::vector<uint8_t> initExpr(rawInitExpr.begin(), rawInitExpr.end());
    globals.entries.push_back(GlobalVariable{static_cast<bool>(global->mutability()), global->valtype(), parseInitExpr(initExpr)});
  }
}

uint64_t parseInitExpr(std::vector<uint8_t> &initExpr) {
  auto stream = initExpr.cbegin();

  while (stream != initExpr.end()) {
    switch (*stream++) {
    case 0x41:
    case 0x42:
      /** (i32|i64).const n:(i32|i64) */
      { return decoder::LEB128Decoder::decodeSigned(stream, initExpr.end()); }
    default:
      std::stringstream message;
      message << std::hex << std::setw(2) << std::setfill('0') << int32_t(*(stream - 1));
      asserte(false, "parseInitExpr(): unsupported instruction: 0x" + message.str());
      break;
    }
  }

  return 0;
}

} // namespace assembler