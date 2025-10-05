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

void Assembler::serializeUint32LE(std::vector<uint8_t> &vec, uint32_t value) {
  vec.push_back(uint8_t(value & 0xFF));
  vec.push_back(uint8_t((value >> 8) & 0xFF));
  vec.push_back(uint8_t((value >> 16) & 0xFF));
  vec.push_back(uint8_t((value >> 24) & 0xFF));
}

std::vector<uint8_t> Assembler::assembleCodeSection(webassembly_t::code_section_t *code_section) {
  std::vector<uint8_t> machinecode;

  asserte(code_section != nullptr, "Code section is null");
  asserte(code_section->entries() != nullptr, "Code section entries are null");

  for (size_t j = 0; j < code_section->entries()->size(); ++j) {
    const auto &entry = code_section->entries()->at(j);
    if (entry->func()->num_locals()->value() > 0) {
      for (size_t k = 0; k < static_cast<size_t>(entry->func()->num_locals()->value()); ++k) {
        if (k > 0) {
          // FIXME: handle local variables
        }
      }
    }

    // serializeUint32LE(machinecode, 0xD2800540); // mov x0, 42

    if (entry->func()->expr().size() > 0) {
      for (size_t k = 0; k < entry->func()->expr().size(); ++k) {
        if (k > 0) {
          serializeUint32LE(machinecode, mapOpcodeToArm64(entry->func()->expr().at(k)));
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
  const auto &section_items = *(sections);
  for (size_t i = 0; i < section_items.size(); ++i) {
    const auto &section = section_items.at(i);
    if (section->id() == 0x0a) {
      auto code_section = dynamic_cast<webassembly_t::code_section_t *>(section->content());
      machinecode = assembleCodeSection(code_section);
    }
  }
  return machinecode;
}
} // namespace tiny