#include "tiny-assembler.hpp"

namespace tiny {

std::vector<uint8_t> Assembler::assemble(std::vector<uint8_t> bytecode) {
  // kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  // webassembly_t wasm(&ks);

  // std::cout << "Magic : " << wasm.magic() << std::endl;
  // std::cout << "WASM version: " << wasm.version() << std::endl;

  // For now, just return empty vector
  return std::vector<uint8_t>();
}
} // namespace tiny