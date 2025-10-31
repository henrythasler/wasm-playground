#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "aarch64-instructions.hpp"
#include "assembler.hpp"
#include "helper.hpp"
#include "webassembly.h"

namespace tiny {

class RegisterPool {
private:
  // true=available; false=in use
  std::map<arm64::reg_t, bool> registers = {{arm64::X9, true},  {arm64::X10, true}, {arm64::X11, true}, {arm64::X12, true},
                                            {arm64::X13, true}, {arm64::X14, true}, {arm64::X15, true}};

public:
  RegisterPool() = default;
  ~RegisterPool() = default;

  arm64::reg_t allocateRegister(void) {
    for (auto reg : registers) {
      if (reg.second) {
        registers[reg.first] = false;
        return reg.first;
      }
    }
    asserte(false, "RegisterPool::allocateRegister(): no available register");
  };
  void freeRegister(arm64::reg_t reg) {
    registers[reg] = true;
  }
};

class Locals {
private:
  std::vector<uint32_t> addresses;
  std::vector<webassembly_t::val_types_t> valTypes;
  uint32_t offset_ = 0;

public:
  Locals() = default;
  ~Locals() = default;

  uint32_t get(uint32_t id) {
    return (addresses.at(id) + offset_);
  }

  webassembly_t::val_types_t getType(uint32_t id) {
    return (valTypes.at(id));
  }

  void set(uint32_t id, uint32_t address, webassembly_t::val_types_t valType) {
    addresses[id] = address;
    valTypes[id] = valType;
  }

  void append(uint32_t address, webassembly_t::val_types_t valType) {
    addresses.emplace_back(address);
    valTypes.emplace_back(valType);
  }

  void setOffset(uint32_t offset) {
    offset_ = offset;
  };
};

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