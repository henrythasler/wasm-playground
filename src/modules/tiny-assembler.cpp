#include "tiny-assembler.hpp"

namespace tiny {

Assembler::~Assembler() {
  delete wasm;
}

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

void Assembler::loadModule(std::vector<uint8_t> bytecode) {
  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  wasm = new webassembly_t(&ks);

  auto magic = wasm->magic();
  asserte(magic.at(0) == 0 && magic.at(1) == 'a' && magic.at(2) == 's' && magic.at(3) == 'm', "Invalid WASM magic number");
  asserte(wasm->version() == 1, "Unsupported WASM version");
}

webassembly_t::code_section_t *Assembler::getCodeSection() {
  // auto sections = wasm->sections();
  const auto &sections = *(wasm->sections());
  for (const auto &section : sections) {
    if (section->id() == webassembly_t::SECTION_ID_CODE_SECTION) {
      return dynamic_cast<webassembly_t::code_section_t *>(section.get()->content());
    }
  }
  return nullptr;
}

std::vector<uint8_t> Assembler::assemble() {
  auto code_section = getCodeSection();
  asserte(code_section != nullptr, "Invalid Code Section");
  // auto machinecode = assembleCodeSection(code_section);
  return std::vector<uint8_t>();
}
} // namespace tiny