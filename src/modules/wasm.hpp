#pragma once

#include <cstdint>
#include <iostream>

namespace wasm {
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

std::string trapCodeToString(trap_code_t code);
} // namespace wasm