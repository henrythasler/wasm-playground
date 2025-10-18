#include "tiny-assembler.hpp"

namespace tiny {

Assembler::~Assembler() {
  if (wasm != nullptr) {
    delete wasm;
  }
}

// u_int32_t Assembler::mapOpcodeToArm64(uint8_t opcode) {
//   switch (opcode) {
//   case 0x00:           // unreachable
//     return 0xD4200000; // BRK #0
//   case 0x0f:           // return
//     return 0xD65F03C0; // RET
//   case 0x0b:           // end
//     return 0xD65F03C0; // RET
//   default:
//     return 0xD4200000; // BRK #0 for unhandled opcodes
//   }
// }

// std::vector<uint8_t> Assembler::assembleCodeSection(webassembly_t::code_section_t *code_section) {
//   std::vector<uint8_t> machinecode;

//   asserte(code_section != nullptr, "Code section is null");
//   asserte(code_section->entries() != nullptr, "Code section entries are null");

//   for (size_t j = 0; j < code_section->entries()->size(); ++j) {
//     const auto &entry = code_section->entries()->at(j);
//     if (entry->func()->num_locals()->value() > 0) {
//       for (size_t k = 0; k < static_cast<size_t>(entry->func()->num_locals()->value()); ++k) {
//         if (k > 0) {
//           // FIXME: handle local variables
//         }
//       }
//     }

//     // serializeUint32(machinecode, 0xD2800540); // mov x0, 42

//     if (entry->func()->expr().size() > 0) {
//       for (size_t k = 0; k < entry->func()->expr().size(); ++k) {
//         if (k > 0) {
//           serializeUint32(machinecode, mapOpcodeToArm64(entry->func()->expr().at(k)));
//         }
//       }
//     }
//   }
//   return machinecode;
// }

void Assembler::loadModule(const std::vector<uint8_t> &bytecode) {
  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  wasm = new webassembly_t(&ks);

  auto magic = wasm->magic();
  asserte(magic.at(0) == 0 && magic.at(1) == 'a' && magic.at(2) == 's' && magic.at(3) == 'm', "Invalid WASM magic number");
  asserte(wasm->version() == 1, "Unsupported WASM version");
}

template <typename Derived, typename Base>
Derived *Assembler::getSectionContent(const std::vector<std::unique_ptr<Base>> &sections, webassembly_t::section_id_t section_id) {
  for (const auto &section : sections) {
    if (section->id() == section_id) {
      return dynamic_cast<Derived *>(section.get()->content());
    }
  }
  return nullptr;
}

/**
 * Assembling steps for each entry (function) in the code-section
 * 1. allocate memory to hold all locals (64-bit) using the stack; init with 0x00
 * 2. create a map where each local and it's memory address is kept
 * 3. create a variable in memory to store the size of the wasm-stack; init with 0x00
 * 4. create a stack structure in memory that can hold n*8 bytes; make sure that the stack size can not exceed n
 * 5. create a memory region to hold all parameters; copy all of them from their registers to the memory region
 * 6. read the first instruction
 */
std::vector<WasmFunction> Assembler::compileModule(const std::vector<uint8_t> &bytecode) {
  loadModule(bytecode);

  asserte(wasm != nullptr, "Assembler: WebAssembly module is null");

  auto code_section = getSectionContent<webassembly_t::code_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_CODE_SECTION);
  auto function_section = getSectionContent<webassembly_t::function_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_FUNCTION_SECTION);
  auto type_section = getSectionContent<webassembly_t::type_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_TYPE_SECTION);

  asserte(code_section != nullptr, "Assembler: Invalid Code Section");
  asserte(code_section->entries() != nullptr, "Assembler: Code section is empty");

  std::vector<WasmFunction> functions;

  for (size_t j = 0; j < code_section->entries()->size(); ++j) {
    const auto &code = code_section->entries()->at(j);
    const auto &func = function_section->typeidx()->at(j);
    const auto &funcType = type_section->functypes()->at(static_cast<size_t>(func->value()));

    WasmFunction wasmFunction;
    wasmFunction.compile(code->func(), funcType);
    functions.push_back(wasmFunction);
  }

  auto export_section = getSectionContent<webassembly_t::export_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_EXPORT_SECTION);
  for (size_t j = 0; j < export_section->exports()->size(); ++j) {
    const auto &item = export_section->exports()->at(j);

    functions.at(static_cast<size_t>(item->idx()->value())).setName(item->name()->value());
  }

  return functions;
}

} // namespace tiny