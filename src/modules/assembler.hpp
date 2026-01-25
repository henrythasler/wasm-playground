#pragma once
#include <csetjmp>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "aarch64-compounds.hpp"
#include "aarch64-instructions-bit.hpp"
#include "aarch64-instructions-branch.hpp"
#include "aarch64-instructions-mem.hpp"
#include "aarch64-instructions.hpp"
#include "assembler-globals.hpp"
#include "assembler-tables.hpp"
#include "helper.hpp"
#include "leb128.hpp"
#include "wasm.hpp"
#include "webassembly.h"

// Global jmp_buf for trap handling
extern jmp_buf g_jmpbuf;

// Global variable to hold the base address for JIT-compiled code
extern uint64_t executableMemoryAddress;
extern uint64_t *executableMemoryAddressPtr;

namespace assembler {
class RegisterPool {
private:
  // true=available; false=in use
  std::map<arm64::reg_t, bool> registers = {{arm64::X8, true},  {arm64::X9, true},  {arm64::X10, true}, {arm64::X11, true},
                                            {arm64::X12, true}, {arm64::X13, true}, {arm64::X14, true}, {arm64::X15, true}};

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
  void lockRegister(arm64::reg_t reg) {
    registers[reg] = false;
  }

  // return a vector of all registers
  std::vector<arm64::reg_t> getRegisterNames(void) {
    std::vector<arm64::reg_t> regs;
    for (auto reg : registers) {
      regs.push_back(reg.first);
    }
    return regs;
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

struct PatchLocation {
  size_t offset;
  size_t stackSize;
};

/**
 * Location in the machinecode where a function call instruction is located that needs to be patched later.
 */
struct FunctionCallPatchLocation {
  size_t offset;    // offset in machinecode where the call instruction is located
  uint32_t funcidx; // index of the function being called
};

struct IndirectFunctionCallPatchLocation {
  size_t offset;    // offset in machinecode where the call instruction is located
  uint32_t funcidx; // index of the function being called
};

enum DataSegmentType { FUNCTION_TABLE };

struct LoadAddressPatchLocation {
  size_t offset; // offset in machinecode where the ADRP-ADD pair is located
  DataSegmentType type;
};

struct LoadLiteralPatchLocation {
  size_t offset;    // offset in machinecode where the call instruction is located
  uint32_t funcidx; // index of the function being called
};

struct ControlBlock {
  enum Type { FUNCTION, BLOCK, LOOP, IF, ELSE };
  Type type;
  std::vector<PatchLocation> patchLocations;
  RegisterPool registerPoolState;
  std::vector<arm64::reg_t> stackState;
  webassembly_t::val_types_t resultType;
  arm64::reg_t resultRegister = arm64::reg_t::XZR;
};

arm64::reg_size_t map_valtype_to_regsize(const webassembly_t::val_types_t type);
uint32_t mapWasmValTypeToArm64Size(webassembly_t::val_types_t valType);
uint32_t saveParametersToStack(const std::vector<webassembly_t::val_types_t> &parameters, uint32_t offset, assembler::Variables &variables,
                               std::vector<uint32_t> &machinecode);
uint32_t initLocals(const std::map<webassembly_t::val_types_t, uint32_t> &locals, uint32_t offset, assembler::Variables &variables,
                    std::vector<uint32_t> &machinecode);
void loadResult(const std::vector<webassembly_t::val_types_t> &results, const std::vector<arm64::reg_t> &wasmStack,
                std::vector<uint32_t> &machinecode);
uint32_t createPreamble(uint32_t stackSize, std::vector<uint32_t> &machinecode);
void createEpilogue(const uint32_t stackSize, std::vector<uint32_t> &machinecode);
std::map<wasm::trap_code_t, int32_t> createTrapHandler(const std::vector<wasm::trap_code_t> trapCodes, std::vector<uint32_t> &machinecode);

inline int32_t getTraphandlerOffset(wasm::trap_code_t trapCode, const std::map<wasm::trap_code_t, int32_t> &trapHandler,
                                    const std::vector<uint32_t> &machinecode);

void assembleExpression(std::vector<uint8_t>::const_iterator &stream, std::vector<uint8_t>::const_iterator streamEnd, Variables &locals,
                        RegisterPool &registerPool, std::vector<ControlBlock> &controlStack, std::vector<arm64::reg_t> &stack,
                        const std::map<wasm::trap_code_t, int32_t> &trapHandler, std::vector<FunctionCallPatchLocation> &functionCallPatchLocations,
                        std::vector<LoadAddressPatchLocation> &loadAddressPatches, webassembly_t::type_section_t *type_section,
                        webassembly_t::function_section_t *function_section, std::unique_ptr<assembler::Globals> &globals,
                        std::unique_ptr<assembler::FunctionTable> &functionTable, std::vector<uint32_t> &machinecode);
} // namespace assembler