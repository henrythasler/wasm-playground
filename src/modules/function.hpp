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
  // std::vector<uint8_t> bytecode;
  std::vector<uint32_t> machinecode;
  std::string name;
  std::vector<webassembly_t::val_types_t> parameters;
  std::vector<webassembly_t::val_types_t> results;

  void serializeUint32LE(uint32_t value);

  std::string joinValTypes(const std::vector<webassembly_t::val_types_t> &valTypes);

public:
  WasmFunction() = default;
  ~WasmFunction() = default;

  size_t compile(const webassembly_t::func_t *func, const std::unique_ptr<webassembly_t::functype_t> &funcType);

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

  // const std::vector<uint8_t> &getBytecode() const {
  //   return bytecode;
  // }

  const std::vector<uint32_t> &getMachinecode() const {
    return machinecode;
  }
};

} // namespace tiny