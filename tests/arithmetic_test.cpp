#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(arithmetic_i32, add) {
  auto wasmModule = helper::loadModule("arithmetic.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("add")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("arithmetic.0.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(1, 0), 1);
  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 1), 2);
  EXPECT_EQ(wasmFunction(-1, -1), -2);
  EXPECT_EQ(wasmFunction(-1, 1), 0);
  EXPECT_EQ(wasmFunction(1, -1), 0);

  EXPECT_EQ(wasmFunction(0x7fffffff, 1), 0x80000000);
  EXPECT_EQ(wasmFunction(0x80000000, -1), 0x7fffffff);
  EXPECT_EQ(wasmFunction(0x80000000, -0x80000000), 0);
  EXPECT_EQ(wasmFunction(0x3fffffff, 1), 0x40000000);
}

TEST(arithmetic_i64, add) {
  auto wasmModule = helper::loadModule("arithmetic.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("add")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("arithmetic.1.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(1, 0), 1);
  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 1), 2);
  EXPECT_EQ(wasmFunction(-1, -1), -2);
  EXPECT_EQ(wasmFunction(-1, 1), 0);
  EXPECT_EQ(wasmFunction(1, -1), 0);

  EXPECT_EQ(wasmFunction(0x7fffffffffffffff, 1), 0x8000000000000000);
  EXPECT_EQ(wasmFunction(0x8000000000000000, -1), 0x7fffffffffffffff);
  EXPECT_EQ(wasmFunction(0x8000000000000000, -0x8000000000000000), 0);
  EXPECT_EQ(wasmFunction(0x3fffffff, 1), 0x40000000);
}

} // namespace