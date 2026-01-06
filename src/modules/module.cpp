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

  asserte(code_section != nullptr, "WasmModule: Invalid Code Section");
  asserte(code_section->entries() != nullptr, "WasmModule: Code section is empty");

  machinecode.clear();

  // Create trap handler builtin; it will be used by all compiled functions
  auto trapHandlerBuiltin = new Builtin();
  trapHandlerBuiltin->machinecodeOffset = machinecode.size();
  auto trapHandler = assembler::createTrapHandler(
      {
          wasm::trap_code_t::UnreachableCodeReached,
          wasm::trap_code_t::IntegerDivisionByZero,
          wasm::trap_code_t::IntegerOverflow,
          wasm::trap_code_t::AssemblerAddressPatchError,
          wasm::trap_code_t::TableOutOfBounds,
      },
      machinecode);
  trapHandlerBuiltin->machinecodeSize = machinecode.size() - trapHandlerBuiltin->machinecodeOffset;
  trapHandlerBuiltin->name = "trap_handler";
  builtins.push_back(trapHandlerBuiltin);

  // Process table and element sections to create and inline literal pool to store the data
  // auto dataSectionStartOffset = machinecode.size();
  // auto dataSectionSize = 0u;
  // auto dataSectionOffset = 0u;

  if (table_section != nullptr && element_section != nullptr) {
    // first table and first element is used
    const auto &table = *table_section->tables()->at(0);
    const auto &element = *element_section->elements()->at(0);

    this->functionTable = new assembler::FunctionTable();

    asserte(table.elemtype() == webassembly_t::types_t::TYPES_ELEMENT,
            "Only funcref element type is supported in function tables. Found: " + std::to_string(table.elemtype()));
    auto limits = table.limits();
    asserte(limits->min()->value() < 0xff, "Function table size > 254: " + std::to_string(limits->min()->value()));
    for (auto i = 0; i < limits->min()->value(); i++) {
      this->functionTable->data.push_back(0xff);
    }

    // initialize function table with element section
    auto table_index = element.tableidx()->value(); // currently only one table is supported
    asserte(table_index == 0, "Only one function table is supported. Found table index: " + std::to_string(table_index));
    for (int32_t i = 0; i < element.num_init()->value(); i++) {
      auto value = element.init_vec()->at(i)->value();
      asserte(value < 0xff, "Function index in table >254: " + std::to_string(value));
      this->functionTable->data.at(i) = static_cast<uint8_t>(value);
    }

    // assembler::emitFunctionTable(table_section, element_section, data);
    functionTable->size = this->functionTable->data.size();
    functionTable->name = "function_table";
    // dataSectionSize += functionTable->size;

    // insert padding to align to 8 bytes
    while (this->functionTable->data.size() % 8 != 0) {
      this->functionTable->data.push_back(0xff);
    }

    // insert function table data into machinecode as inline literal pool
    // functionTable->offset = machinecode.size();
    // const uint32_t *ptr = reinterpret_cast<const uint32_t *>(this->functionTable->data.data());
    // size_t count = this->functionTable->data.size() / sizeof(uint32_t);
    // machinecode.insert(machinecode.end(), ptr, ptr + count);
  }

  // Compile each function in the code section
  for (size_t j = 0; j < code_section->entries()->size(); ++j) {
    const auto &code = code_section->entries()->at(j);
    const auto &func = function_section->typeidx()->at(j);
    const auto &funcType = type_section->functypes()->at(static_cast<size_t>(func->value()));

    auto wasmFunction = new WasmFunction();
    wasmFunction->compile(code->func(), funcType, type_section, function_section, trapHandler, functionTable, machinecode);
    wasmFunctions.push_back(wasmFunction);
  }

  auto export_section = getSectionContent<webassembly_t::export_section_t>(*(wasm->sections()), webassembly_t::SECTION_ID_EXPORT_SECTION);
  for (size_t j = 0; j < export_section->exports()->size(); ++j) {
    const auto &item = export_section->exports()->at(j);
    wasmFunctions.at(static_cast<size_t>(item->idx()->value()))->setName(item->name()->value());
  }
}

/**
 * Concatenate all compiled functions to create the final machinecode
 */
void WasmModule::linkModule() {
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
  }
}

} // namespace tiny