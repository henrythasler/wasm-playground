#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "assembler.hpp"
#include "helper.hpp"
#include "webassembly.h"

namespace tiny {

class WasmFunction {
private:
  size_t machinecodeOffset = 0;
  size_t machinecodeSize = 0;
  std::string name;
  std::vector<webassembly_t::val_types_t> parameters;
  std::map<webassembly_t::val_types_t, uint32_t> locals;
  std::vector<webassembly_t::val_types_t> results;
  std::vector<assembler::FunctionCallPatchLocation> functionCallPatches;
  std::vector<assembler::LoadAddressPatchLocation> loadAddressPatches;

  std::string joinValTypes(const std::vector<webassembly_t::val_types_t> &valTypes);

public:
  WasmFunction() = default;
  ~WasmFunction() = default;

  size_t compile(const webassembly_t::func_t *func, const std::unique_ptr<webassembly_t::functype_t> &funcType,
                 webassembly_t::type_section_t *type_section, webassembly_t::function_section_t *function_section,
                 std::unique_ptr<assembler::Globals> &globals, const std::map<wasm::trap_code_t, int32_t> &trapHandler,
                 std::unique_ptr<assembler::FunctionTable> &functionTable, std::vector<uint32_t> &machinecode);

  std::string getName() const {
    return name;
  };

  const std::vector<webassembly_t::val_types_t> &getResults() {
    return results;
  };

  std::string getResultString() {
    return joinValTypes(results);
  }

  std::string getParameterString() {
    return joinValTypes(parameters);
  }

  const std::vector<webassembly_t::val_types_t> &getParameters() {
    return parameters;
  };

  void setName(const std::string newName) {
    name = newName;
  };

  size_t getMachinecodeOffset() const {
    return machinecodeOffset;
  }

  size_t getMachinecodeSize() const {
    return machinecodeSize;
  }

  void setMachinecodeOffset(size_t offset) {
    machinecodeOffset = offset;
  }

  void setMachinecodeSize(size_t size) {
    machinecodeSize = size;
  }

  // const std::vector<uint32_t> &getMachinecode() const {
  //   return machinecode;
  // }

  const std::vector<assembler::FunctionCallPatchLocation> &getFunctionCalls() const {
    return functionCallPatches;
  }

  const std::vector<assembler::LoadAddressPatchLocation> &getLoadAddressPatches() const {
    return loadAddressPatches;
  }
};

} // namespace tiny