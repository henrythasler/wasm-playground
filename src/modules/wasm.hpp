#pragma once

#include <cstdint>

namespace wasm {
using wasm_i32_t = int32_t;
using wasm_i64_t = int64_t;
using wasm_f32_t = float;
using wasm_f64_t = double;

enum class trap_code_t {
  UnreachableCodeReached = 0x01,
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
};
} // namespace wasm