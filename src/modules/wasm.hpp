#pragma once

#include <cstdint>
#include <iostream>

namespace wasm {

constexpr int32_t MAX_LINEAR_MEMORY_PAGES = 16;
constexpr int32_t LINEAR_MEMORY_PAGE_SIZE = 0x10000; // 64 KiB

using wasm_i32_t = int32_t;
using wasm_i64_t = int64_t;
using wasm_f32_t = float;
using wasm_f64_t = double;

/**
 * Enum representing various WebAssembly trap codes
 * carry-over from wasi-libc for consistency
 */
enum class trap_code_t {
  None = 0,
  UnreachableCodeReached,
  MemoryOutOfBounds,
  TableOutOfBounds,
  IndirectCallToNull,
  IntegerDivisionByZero,
  IntegerOverflow,
  BadConversionToInteger,
  StackOverflow,
  BadSignature,
  OutOfFuel,
  GrowthOperationLimited,
  AssemblerAddressPatchError, // used as the default jump target when emitting forward jumps to unknown labels; traps when address patching does not
                              // update the jump target
};

class TrapCategory : public std::error_category {
public:
  const char *name() const noexcept override {
    return "trap";
  }

  std::string message(int ev) const override {
    switch (static_cast<trap_code_t>(ev)) {
    case trap_code_t::None:
      return "No trap";
    case trap_code_t::UnreachableCodeReached:
      return "Unreachable code reached";
    case trap_code_t::MemoryOutOfBounds:
      return "Memory out of bounds";
    case trap_code_t::TableOutOfBounds:
      return "Table out of bounds";
    case trap_code_t::IndirectCallToNull:
      return "Indirect call to null";
    case trap_code_t::IntegerDivisionByZero:
      return "Integer division by zero";
    case trap_code_t::IntegerOverflow:
      return "Integer overflow";
    case trap_code_t::BadConversionToInteger:
      return "Bad conversion to integer";
    case trap_code_t::StackOverflow:
      return "Stack overflow";
    case trap_code_t::BadSignature:
      return "Bad signature";
    case trap_code_t::OutOfFuel:
      return "Out of fuel";
    case trap_code_t::GrowthOperationLimited:
      return "Growth operation limited";
    case trap_code_t::AssemblerAddressPatchError:
      return "AssemblerAddressPatchError";
    default:
      return "Unknown trap code";
    }
  }
};

const TrapCategory &trap_category();
std::error_code make_trap_error(trap_code_t code);

} // namespace wasm