#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"

namespace {

TEST(echo, echo32) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getMachinecode();
  // ASSERT_EQ(wasmModule.getFunctionOffset("echo32"), 0x34);
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("echo32"));

  EXPECT_EQ(wasmFunction(-1), -1);
  EXPECT_EQ(wasmFunction(10000), 10000);
  EXPECT_EQ(wasmFunction(-10000), -10000);
  EXPECT_EQ(wasmFunction(0xffffffff), 0xffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffff), 0x7fffffff);
}

TEST(echo, echo64) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getMachinecode();
  // ASSERT_EQ(wasmModule.getFunctionOffset("echo64"), 0x58);
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("echo64"));

  EXPECT_EQ(wasmFunction(-1), -1);
  EXPECT_EQ(wasmFunction(10000), 10000);
  EXPECT_EQ(wasmFunction(-10000), -10000);
  EXPECT_EQ(wasmFunction(0xffffffff), 0xffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffff), 0x7fffffff);

  EXPECT_EQ(wasmFunction(0xffffffffffffffff), 0xffffffffffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffffffffffff), 0x7fffffffffffffff);
  EXPECT_EQ(wasmFunction(0x123456789ABCDEF0), 0x123456789ABCDEF0);
}

TEST(echo, geti64) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getMachinecode();
  // ASSERT_EQ(wasmModule.getFunctionOffset("geti64"), 0x7c);
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("geti64"));

  EXPECT_EQ(wasmFunction(), 0x123456789ABCDEF0);
}

TEST(echo, geti64max) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getMachinecode();
  // ASSERT_EQ(wasmModule.getFunctionOffset("geti64max"), 0xa0);
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("geti64max"));

  EXPECT_EQ(wasmFunction(), 0x7fffffffffffffff);
}

} // namespace