#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "aarch64-instructions.hpp"
#include "helper.hpp"
#include "webassembly.h"

namespace tiny {

class Locals {
  private:
    std::vector<uint32_t> locals_;
    uint32_t offset_ = 0;

  public:
  Locals() = default;
  ~Locals() = default;

  uint32_t get(uint32_t id) {
    return (locals_.at(id) + offset_);
  }

  void set(uint32_t id, uint32_t address) {
    locals_[id] = address;
  }

  void append(uint32_t address) {
    locals_.emplace_back(address);
  }

  void setOffset(uint32_t offset) {
    offset_ = offset;
  };
};

class WasmFunction {
private:
  std::vector<uint8_t> bytecode;
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

  const std::vector<uint8_t> &getBytecode() const {
    return bytecode;
  }
};

class WasmModule {
private:
  /* data */
public:
  WasmModule() = default;
  ~WasmModule() = default;
};

} // namespace tiny