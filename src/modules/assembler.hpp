#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "helper.hpp"
#include "module.hpp"
#include "webassembly.h"

namespace tiny {

class Assembler {
private:
  webassembly_t *wasm = nullptr;

  template <typename Derived, typename Base>
  Derived *getSectionContent(const std::vector<std::unique_ptr<Base>> &sections, webassembly_t::section_id_t section_type);

  void loadModule(const std::vector<uint8_t> &bytecode);

  // WasmFunction compileFunction(const std::unique_ptr<webassembly_t::code_t> &entry);
  // u_int32_t mapOpcodeToArm64(uint8_t opcode);

public:
  Assembler() = default;
  ~Assembler();

  std::vector<WasmFunction> compileModule(const std::vector<uint8_t> &bytecode);
};

} // namespace tiny
