#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "helper.hpp"
#include "webassembly.h"

namespace tiny {

class Assembler {
private:
  webassembly_t *wasm = nullptr;

  template <typename Derived, typename Base>
  Derived *getSectionContent(const std::vector<std::unique_ptr<Base>> &sections, webassembly_t::section_id_t section_type);

  std::vector<uint8_t> assembleCodeSection(webassembly_t::code_section_t *code_section);
  u_int32_t mapOpcodeToArm64(uint8_t opcode);
  void serializeUint32LE(std::vector<uint8_t> &vec, uint32_t value);

public:
  Assembler() = default;
  ~Assembler();

  void loadModule(std::vector<uint8_t> bytecode);
  std::vector<uint8_t> assemble();
};

} // namespace tiny
