#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"

namespace {

TEST(echo, echo32) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("echo32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("echo32.bin", machinecode);

  EXPECT_EQ(wasmFunction(-1), -1);
  EXPECT_EQ(wasmFunction(10000), 10000);
  EXPECT_EQ(wasmFunction(-10000), -10000);
  EXPECT_EQ(wasmFunction(0xffffffff), 0xffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffff), 0x7fffffff);
}

TEST(echo, echo64) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("echo64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("echo64.bin", machinecode);

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
  auto machinecode = wasmModule.getWasmFunction("geti64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  helper::dump("geti64.bin", machinecode);

  EXPECT_EQ(wasmFunction(), 0x123456789ABCDEF0);
}

TEST(echo, geti64max) {
  auto wasmModule = helper::loadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("geti64max")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  helper::dump("geti64max.bin", machinecode);

  EXPECT_EQ(wasmFunction(), 0x7fffffffffffffff);
}

} // namespace