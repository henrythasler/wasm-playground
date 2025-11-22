#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(compare, lt_s32) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("lt_s32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("compare.lt_s32.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(-10, 10), 1);
  EXPECT_EQ(wasmFunction(INT32_MAX, INT32_MAX), 0);
  EXPECT_EQ(wasmFunction(INT32_MIN, INT32_MIN), 0);
}

TEST(compare, lt_u32) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("lt_u32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("compare.lt_u32.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(10, 100), 1);
  EXPECT_EQ(wasmFunction(100, 10), 0);
  EXPECT_EQ(wasmFunction(INT32_MAX, INT32_MAX), 0);
  EXPECT_EQ(wasmFunction(INT32_MIN, INT32_MIN), 0);
}

TEST(compare, lt_s64) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("lt_s64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("compare.lt_s64.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(-10, 10), 1);
  EXPECT_EQ(wasmFunction(INT64_MAX, INT64_MAX), 0);
  EXPECT_EQ(wasmFunction(INT64_MIN, INT64_MIN), 0);
}

TEST(compare, lt_u64) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("lt_u64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("compare.lt_u64.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(10, 100), 1);
  EXPECT_EQ(wasmFunction(100, 10), 0);
  EXPECT_EQ(wasmFunction(INT64_MAX, INT64_MAX), 0);
  EXPECT_EQ(wasmFunction(INT64_MIN, INT64_MIN), 0);
}

TEST(compare, le_s32) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("le_s32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("compare.le_s32.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 0), 1);
  EXPECT_EQ(wasmFunction(-10, 10), 1);
  EXPECT_EQ(wasmFunction(INT32_MAX, INT32_MAX), 1);
  EXPECT_EQ(wasmFunction(INT32_MIN, INT32_MIN), 1);
}

TEST(compare, le_u32) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("le_u32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("compare.le_u32.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 0), 1);
  EXPECT_EQ(wasmFunction(10, 100), 1);
  EXPECT_EQ(wasmFunction(100, 10), 0);
  EXPECT_EQ(wasmFunction(INT32_MAX, INT32_MAX), 1);
  EXPECT_EQ(wasmFunction(INT32_MIN, INT32_MIN), 1);
}

TEST(compare, le_s64) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("le_s64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("compare.le_s64.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 0), 1);
  EXPECT_EQ(wasmFunction(-10, 10), 1);
  EXPECT_EQ(wasmFunction(INT64_MAX, INT64_MAX), 1);
  EXPECT_EQ(wasmFunction(INT64_MIN, INT64_MIN), 1);
}

TEST(compare, le_u64) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("le_u64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("compare.le_u64.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 0), 1);
  EXPECT_EQ(wasmFunction(10, 100), 1);
  EXPECT_EQ(wasmFunction(100, 10), 0);
  EXPECT_EQ(wasmFunction(INT64_MAX, INT64_MAX), 1);
  EXPECT_EQ(wasmFunction(INT64_MIN, INT64_MIN), 1);
  EXPECT_EQ(wasmFunction(INT64_MAX - 1, INT64_MAX), 1);
  EXPECT_EQ(wasmFunction(INT64_MIN, INT64_MIN + 1), 1);
  EXPECT_EQ(wasmFunction(INT64_MAX, INT64_MAX - 1), 0);
  EXPECT_EQ(wasmFunction(INT64_MIN, INT64_MIN + 1), 1);
}

TEST(compare, eqz_i32) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("eqz_i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("compare.eqz_i32.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 1);
  EXPECT_EQ(wasmFunction(1), 0);
  EXPECT_EQ(wasmFunction(1024), 0);
  EXPECT_EQ(wasmFunction(INT32_MAX), 0);
  EXPECT_EQ(wasmFunction(INT32_MIN), 0);
}

TEST(compare, eqz_i64) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("eqz_i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("compare.eqz_i64.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 1);
  EXPECT_EQ(wasmFunction(1), 0);
  EXPECT_EQ(wasmFunction(1024), 0);
  EXPECT_EQ(wasmFunction(INT64_MAX), 0);
  EXPECT_EQ(wasmFunction(INT64_MIN), 0);
}

} // namespace