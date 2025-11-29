#include "module.hpp"

namespace tiny {

WasmModule::WasmModule(const std::vector<uint8_t> &bytecode) {
  loadModule(bytecode);
  compileModule();
  linkModule();
}

WasmModule::~WasmModule() {
  if (wasm != nullptr) {
    delete wasm;
  }
}

void WasmModule::loadModule(const std::vector<uint8_t> &bytecode) {
  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  wasm = new webassembly_t(&ks);

  auto magic = wasm->magic();
  asserte(magic.at(0) == 0 && magic.at(1) == 'a' && magic.at(2) == 's' && magic.at(3) == 'm', "Invalid WASM magic number");
  asserte(wasm->version() == 1, "Unsupported WASM version");
}

template <typename Derived, typename Base>
Derived *WasmModule::getSectionContent(const std::vector<std::unique_ptr<Base>> &sections, webassembly_t::section_id_t section_id) {
  for (const auto &section : sections) {
    if (section->id() == section_id) {
      return dynamic_cast<Derived *>(section.get()->content());
    }
  }
  asserte(false, "getSectionContent(): could not find section '" + std::to_string(section_id) + "'");
  return nullptr;
}

const WasmFunction *WasmModule::getWasmFunction(std::string name) {
  for (auto function : wasmFunctions) {
    if (name == function->getName()) {
      return function;
    }
  }
  asserte(false, "getWasmFunction(): could not find function '" + name + "'");
  return nullptr;
}

size_t WasmModule::getFunctionOffset(std::string name){
  size_t offset = 0;
  for (auto function : wasmFunctions) {
    if (name == function->getName()) {
      return offset;
    }
    offset += function->getMachinecode().size() * sizeof(uint32_t);
  }
  asserte(false, "getFunctionOffset(): could not find function '" + name + "'");
  return 0;
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
void WasmModule::compileModule() {
  asserte(wasm != nullptr, "WasmModule: WebAssembly module is null");

  auto code_section = getSectionContent<webassembly_t::code_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_CODE_SECTION);
  auto function_section = getSectionContent<webassembly_t::function_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_FUNCTION_SECTION);
  auto type_section = getSectionContent<webassembly_t::type_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_TYPE_SECTION);

  asserte(code_section != nullptr, "WasmModule: Invalid Code Section");
  asserte(code_section->entries() != nullptr, "WasmModule: Code section is empty");

  for (size_t j = 0; j < code_section->entries()->size(); ++j) {
    const auto &code = code_section->entries()->at(j);
    const auto &func = function_section->typeidx()->at(j);
    const auto &funcType = type_section->functypes()->at(static_cast<size_t>(func->value()));

    auto wasmFunction = new WasmFunction();
    wasmFunction->compile(code->func(), funcType);
    wasmFunctions.push_back(wasmFunction);
  }

  auto export_section = getSectionContent<webassembly_t::export_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_EXPORT_SECTION);
  for (size_t j = 0; j < export_section->exports()->size(); ++j) {
    const auto &item = export_section->exports()->at(j);
    wasmFunctions.at(static_cast<size_t>(item->idx()->value()))->setName(item->name()->value());
  }
}

void WasmModule::linkModule() {
  for(auto wasmFunction : wasmFunctions) {
    machinecode.insert(machinecode.end(), wasmFunction->getMachinecode().begin(), wasmFunction->getMachinecode().end());
  }
}

} // namespace tiny