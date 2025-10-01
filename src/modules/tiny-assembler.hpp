#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

#include "helper.hpp"
#include "webassembly.h"

namespace tiny {

class Assembler {
private:
  std::vector<uint8_t> assembleCodeSection(webassembly_t::code_section_t *code_section);
  u_int32_t mapOpcodeToArm64(uint8_t opcode);
  void serializeUint32LE(std::vector<uint8_t> &vec, uint32_t value);

public:
  Assembler() = default;
  ~Assembler() = default;
  std::vector<uint8_t> assemble(std::vector<uint8_t> bytecode);
};

} // namespace tiny
