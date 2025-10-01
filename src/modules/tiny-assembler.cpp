#include "tiny-assembler.hpp"

namespace tiny {

u_int32_t Assembler::mapOpcodeToArm64(uint8_t opcode) {
  switch (opcode) {
  case 0x00:           // unreachable
    return 0xD4200000; // BRK #0
  case 0x0f:           // return
    return 0xD65F03C0; // RET
  case 0x0b:           // end
    return 0xD65F03C0; // RET
  default:
    return 0xD4200000; // BRK #0 for unhandled opcodes
  }
}

void Assembler::serializeUint32LE(std::vector<uint8_t>& vec, uint32_t value) {
    vec.push_back(value & 0xFF);
    vec.push_back((value >> 8) & 0xFF);
    vec.push_back((value >> 16) & 0xFF);
    vec.push_back((value >> 24) & 0xFF);
}

std::vector<uint8_t> Assembler::assembleCodeSection(webassembly_t::code_section_t *code_section) {
  std::vector<uint8_t> machinecode;

  asserte(code_section != nullptr, "Code section is null");
  asserte(code_section->bodies() != nullptr, "Code section bodies are null");

  for (size_t j = 0; j < code_section->bodies()->size(); ++j) {
    const auto &body = code_section->bodies()->at(j);
    if (body->data()->local_count()->value() > 0) {
      for (size_t k = 0; k < body->data()->local_count()->value(); ++k) {
        if (k > 0) {
          // FIXME: handle local variables
        }
      }
    }


    // serializeUint32LE(machinecode, 0xD2800540); // mov x0, 42

    if (body->data()->code().size() > 0) {
      for (size_t k = 0; k < body->data()->code().size(); ++k) {
        if (k > 0) {
          serializeUint32LE(machinecode, mapOpcodeToArm64(body->data()->code().at(k)));
        }
      }
    }
  }
  return machinecode;
}

std::vector<uint8_t> Assembler::assemble(std::vector<uint8_t> bytecode) {
  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  webassembly_t wasm(&ks);

  std::vector<uint8_t> machinecode;

  auto magic = wasm.magic();
  asserte(magic.at(0) == 0 && magic.at(1) == 'a' && magic.at(2) == 's' && magic.at(3) == 'm', "Invalid WASM magic number");
  asserte(wasm.version() == 1, "Unsupported WASM version");

  // iterate over sections
  auto sections = wasm.sections();
  const auto &section_items = *(sections->sections());
  for (size_t i = 0; i < section_items.size(); ++i) {
    const auto &section = section_items.at(i);
    if (section->header()->id() == 0x0a) {
      auto code_section = dynamic_cast<webassembly_t::code_section_t *>(section->payload_data());
      machinecode = assembleCodeSection(code_section);
    }
  }
  return machinecode;
}
} // namespace tiny