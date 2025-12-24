#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(call, type_i32) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-i32"));

  EXPECT_EQ(wasmFunction(), 0x132);
}

TEST(call, type_i64) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-i64"));

  EXPECT_EQ(wasmFunction(), 0x164);
}

TEST(call, type_first_i32) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-first-i32"));

  EXPECT_EQ(wasmFunction(), 32);
}

TEST(call, type_first_i64) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-first-i64"));

  EXPECT_EQ(wasmFunction(), 64);
}

TEST(call, type_second_i64) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-second-i64"));

  EXPECT_EQ(wasmFunction(), 64);
}

TEST(call, fac_acc) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("fac-acc"));

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(5, 1), 120);
  EXPECT_EQ(wasmFunction(25, 1), 7034535277573963776);
}

TEST(call, fib) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("fib"));

  EXPECT_EQ(wasmFunction(0), 1);
  EXPECT_EQ(wasmFunction(1), 1);
  EXPECT_EQ(wasmFunction(2), 2);
  EXPECT_EQ(wasmFunction(5), 8);
  EXPECT_EQ(wasmFunction(20), 10946);
}

TEST(call, even) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("even"));

  EXPECT_EQ(wasmFunction(0), 44);
  EXPECT_EQ(wasmFunction(1), 99);
  EXPECT_EQ(wasmFunction(100), 44);
  EXPECT_EQ(wasmFunction(77), 99);
}

TEST(call, odd) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("odd"));

  EXPECT_EQ(wasmFunction(0), 99);
  EXPECT_EQ(wasmFunction(1), 44);
  EXPECT_EQ(wasmFunction(200), 99);
  EXPECT_EQ(wasmFunction(77), 44);
}

} // namespace