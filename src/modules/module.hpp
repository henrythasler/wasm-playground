#pragma once

#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "assembler.hpp"
#include "builtin.hpp"
#include "function.hpp"
#include "helper.hpp"
#include "module.hpp"
#include "webassembly.h"

namespace tiny {

class WasmModule {
private:
  webassembly_t *wasm = nullptr;
  std::vector<Builtin *> builtins;
  std::vector<WasmFunction *> wasmFunctions;
  std::vector<uint32_t> machinecode;
  std::vector<uint32_t> linkedMachinecode;
  std::unique_ptr<assembler::FunctionTable> functionTable;
  std::unique_ptr<assembler::Globals> globals;

  template <typename Derived, typename Base>
  Derived *getSectionContent(const std::vector<std::unique_ptr<Base>> &sections, webassembly_t::section_id_t section_type);

  void loadModule(const std::vector<uint8_t> &bytecode);
  void compileModule();
  void linkModule();

public:
  // WasmModule() = default;
  WasmModule(const std::vector<uint8_t> &bytecode);
  ~WasmModule();

  size_t getNumFunctions() {
    return wasmFunctions.size();
  }

  const std::vector<WasmFunction *> &getWasmFunctions() {
    return wasmFunctions;
  }

  const std::vector<Builtin *> &getBuiltins() {
    return builtins;
  }

  const std::vector<uint32_t> &getMachinecode() const {
    return machinecode;
  }

  const std::vector<uint32_t> &linkMachinecode() const;

  // std::vector<uint32_t> &getMutableMachinecode() {
  //   return machinecode;
  // }

  const assembler::FunctionTable *getFunctionTable() const {
    return functionTable.get();
  }

  const WasmFunction *getWasmFunction(std::string name);
  size_t getFunctionOffset(std::string name);
};

} // namespace tiny
