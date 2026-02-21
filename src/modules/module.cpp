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
  // asserte(false, "getSectionContent(): could not find section '" + std::to_string(section_id) + "'");
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

size_t WasmModule::getFunctionOffset(std::string name) {
  for (auto function : wasmFunctions) {
    if (name == function->getName()) {
      return function->getMachinecodeOffset() << 2;
    }
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
  auto table_section = getSectionContent<webassembly_t::table_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_TABLE_SECTION);
  auto element_section = getSectionContent<webassembly_t::element_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_ELEMENT_SECTION);
  auto global_section = getSectionContent<webassembly_t::global_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_GLOBAL_SECTION);
  auto memory_section = getSectionContent<webassembly_t::memory_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_MEMORY_SECTION);
  auto data_section = getSectionContent<webassembly_t::data_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_DATA_SECTION);
  auto import_section = getSectionContent<webassembly_t::import_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_IMPORT_SECTION);

  asserte(code_section != nullptr, "WasmModule: Invalid Code Section");
  asserte(code_section->entries() != nullptr, "WasmModule: Code section is empty");

  machinecode.clear();

  // Create trap handler builtin; it will be used by all compiled functions
  auto trapHandlerBuiltin = new Builtin();
  trapHandlerBuiltin->machinecodeOffset = machinecode.size();
  auto trapHandler = assembler::createTrapHandler(
      {
          wasm::trap_code_t::AssemblerAddressPatchError,
          wasm::trap_code_t::UnreachableCodeReached,
          wasm::trap_code_t::IntegerDivisionByZero,
          wasm::trap_code_t::IntegerOverflow,
          wasm::trap_code_t::TableOutOfBounds,
          wasm::trap_code_t::IndirectCallToNull,
          wasm::trap_code_t::BadSignature,
          wasm::trap_code_t::MemoryOutOfBounds,
          wasm::trap_code_t::StackOverflow,
      },
      machinecode);
  trapHandlerBuiltin->machinecodeSize = machinecode.size() - trapHandlerBuiltin->machinecodeOffset;
  trapHandlerBuiltin->name = "trap_handler";
  builtins.push_back(trapHandlerBuiltin);

  // Process table and element sections to create and inline literal pool to store the data
  if (table_section != nullptr && element_section != nullptr) {
    functionTable = std::make_unique<assembler::FunctionTable>();
    emitFunctionTable(*functionTable, function_section, table_section, element_section, machinecode);
  }

  // process global section
  if (global_section != nullptr) {
    globals = std::make_unique<assembler::Globals>();
    assembler::parseGlobalsSection(*globals, *global_section);
  }

  // process memory section
  if (memory_section != nullptr) {
    linearMemory = std::make_unique<assembler::LinearMemory>();
    linearMemory->parseMemorySection(memory_section, data_section);
  }

  if (import_section != nullptr) {
    auto imports = import_section->imports();
    int index = 0;
    for (const auto &import : *imports) {
      if (import->import_type() == webassembly_t::import_types_t::IMPORT_TYPES_FUNC_TYPE) {
        auto wasmFunction = new WasmFunction();
        const auto &funcType = type_section->functypes()->at(index);
        wasmFunction->isImported = true;
        wasmFunctions.push_back(wasmFunction);
        importedFunctions.emplace(index, api::ImportedFunction(index, import->module()->value(), import->name()->value(), funcType,
                                                               api::getApiFunction(import->module()->value(), import->name()->value())));
        index++;
      }
    }
  }

  // Compile each function in the code section
  for (size_t j = 0; j < code_section->entries()->size(); ++j) {
    const auto &code = code_section->entries()->at(j);
    const auto &func = function_section->typeidx()->at(j);
    const auto &funcType = type_section->functypes()->at(static_cast<size_t>(func->value()));

    auto wasmFunction = new WasmFunction();
    wasmFunction->compile(code->func(), funcType, type_section, function_section, globals, trapHandler, functionTable, importedFunctions,
                          machinecode);
    wasmFunctions.push_back(wasmFunction);
  }

  auto export_section = getSectionContent<webassembly_t::export_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_EXPORT_SECTION);
  for (size_t j = 0; j < export_section->exports()->size(); ++j) {
    const auto &item = export_section->exports()->at(j);
    if (item->exportdesc() == webassembly_t::export_types_t::EXPORT_TYPES_FUNC_TYPE) {
      wasmFunctions.at(static_cast<size_t>(item->idx()->value()))->setName(item->name()->value());
    }
  }
}

/**
 * Concatenate all compiled functions to create the final machinecode
 */
void WasmModule::linkModule() {
  if (this->functionTable) {
    for (size_t j = 0; j < this->functionTable->entries.size(); j++) {
      if (this->functionTable->entries.at(j).index == 0xff)
        continue;
      auto offset = wasmFunctions.at(this->functionTable->entries.at(j).index)->getMachinecodeOffset() * sizeof(uint32_t);
      machinecode[this->functionTable->entries.at(j).offset] = offset;
      auto typeidx = this->functionTable->entries.at(j).typeIndex;
      machinecode[this->functionTable->entries.at(j).offset + 1] = typeidx;
    }
  }

  for (auto wasmFunction : wasmFunctions) {
    for (auto functionCall : wasmFunction->getFunctionCalls()) {
      int32_t patchLocation = functionCall.offset;
      int32_t targetFunctionOffset =
          int32_t(wasmFunctions.at(functionCall.funcidx)->getMachinecodeOffset() * sizeof(uint32_t)) - patchLocation * sizeof(uint32_t);

      std::stringstream message;
      message << std::hex << std::setw(2) << std::setfill('0') << patchLocation * 8;
      asserte(patchLocation < machinecode.size(),
              "linkModule(): patch location out of bounds in '" + wasmFunction->getName() + "()': 0x" + message.str());
      arm64::patch_branch_link(machinecode[patchLocation], targetFunctionOffset);
    }

    for (auto loadAddressPatch : wasmFunction->getLoadAddressPatches()) {
      int32_t patchLocation = loadAddressPatch.offset;

      uint64_t code_page = (uint64_t)(patchLocation * sizeof(uint32_t)) & ~0xfffULL;
      uint64_t target_page = (uint64_t)(this->functionTable->offset * sizeof(uint32_t)) & ~0xfffULL;
      int64_t page_offset = (int64_t)(target_page - code_page);

      uint32_t low12 = (uint64_t)(this->functionTable->offset * sizeof(uint32_t)) & 0xfff;

      arm64::patch_adrp(machinecode[patchLocation], page_offset);
      arm64::patch_add_immediate(machinecode[patchLocation + 1], static_cast<uint16_t>(low12));
    }
  }
}

} // namespace tiny