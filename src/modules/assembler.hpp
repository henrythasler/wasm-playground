#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "aarch64-instructions.hpp"
#include "helper.hpp"
#include "leb128.hpp"
#include "webassembly.h"

namespace assembler {
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

class Variables {
private:
  std::vector<uint32_t> addresses;
  std::vector<webassembly_t::val_types_t> valTypes;
  uint32_t offset_ = 0;

public:
  Variables() = default;
  ~Variables() = default;

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

arm64::reg_size_t map_valtype_to_regsize(const webassembly_t::val_types_t type);
std::vector<uint32_t> assembleExpression(std::vector<uint8_t>::const_iterator &stream, std::vector<uint8_t>::const_iterator streamEnd,
                                         Variables &locals, RegisterPool &registerPool, std::vector<arm64::reg_t> &stack);
uint32_t mapWasmValTypeToArm64Size(webassembly_t::val_types_t valType);
std::vector<uint32_t> saveParametersToStack(const std::vector<webassembly_t::val_types_t> &parameters, uint32_t &offset,
                                            assembler::Variables &locals);
std::vector<uint32_t> initLocals(const std::map<webassembly_t::val_types_t, uint32_t> &locals, uint32_t &offset, assembler::Variables &variables);
std::vector<uint32_t> loadResult(const std::vector<webassembly_t::val_types_t> &results, const std::vector<arm64::reg_t> &wasmStack);
} // namespace assembler