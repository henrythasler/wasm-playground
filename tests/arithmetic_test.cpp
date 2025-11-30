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
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("add"));

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
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("add"));

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

TEST(arithmetic_i32, sub) {
  auto wasmModule = helper::loadModule("arithmetic.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("sub"));

  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(1, 0), 1);
  EXPECT_EQ(wasmFunction(0, 1), -1);
  EXPECT_EQ(wasmFunction(0, -10), 10);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(-1, -1), 0);
  EXPECT_EQ(wasmFunction(-1, 1), -2);
  EXPECT_EQ(wasmFunction(1, -1), 2);

  EXPECT_EQ(wasmFunction(0x7fffffff, -1), 0x80000000);
  EXPECT_EQ(wasmFunction(0x80000000, 1), 0x7fffffff);
  EXPECT_EQ(wasmFunction(0x80000000, 0x80000000), 0);
  EXPECT_EQ(wasmFunction(0x3fffffff, -1), 0x40000000);
}

TEST(arithmetic_i64, sub) {
  auto wasmModule = helper::loadModule("arithmetic.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("sub"));

  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(1, 0), 1);
  EXPECT_EQ(wasmFunction(0, 1), -1);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(-1, -1), 0);
  EXPECT_EQ(wasmFunction(-1, 1), -2);
  EXPECT_EQ(wasmFunction(1, -1), 2);

  EXPECT_EQ(wasmFunction(0x7fffffffffffffff, -1), 0x8000000000000000);
  EXPECT_EQ(wasmFunction(0x8000000000000000, 1), 0x7fffffffffffffff);
  EXPECT_EQ(wasmFunction(0x8000000000000000, 0x8000000000000000), 0);
  EXPECT_EQ(wasmFunction(0x3fffffff, -1), 0x40000000);
}

TEST(arithmetic_i32, mul) {
  auto wasmModule = helper::loadModule("arithmetic.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("mul"));

  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(-1, -1), 1);
  EXPECT_EQ(wasmFunction(-1, 1), -1);
  EXPECT_EQ(wasmFunction(1, -1), -1);

  EXPECT_EQ(wasmFunction(0x10000000, 4096), 0);
  EXPECT_EQ(wasmFunction(0x80000000, 0), 0);
  EXPECT_EQ(wasmFunction(0x80000000, -1), 0x80000000);
  EXPECT_EQ(wasmFunction(0x7fffffff, -1), 0x80000001);
  EXPECT_EQ(wasmFunction(0x01234567, 0x76543210), 0x358e7470);
  EXPECT_EQ(wasmFunction(0x7fffffff, 0x7fffffff), 1);
}

TEST(arithmetic_i64, mul) {
  auto wasmModule = helper::loadModule("arithmetic.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("mul"));

  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(-1, -1), 1);
  EXPECT_EQ(wasmFunction(-1, 1), -1);
  EXPECT_EQ(wasmFunction(1, -1), -1);

  EXPECT_EQ(wasmFunction(0x1000000000000000, 4096), 0);
  EXPECT_EQ(wasmFunction(0x8000000000000000, 0), 0);
  EXPECT_EQ(wasmFunction(0x8000000000000000, -1), 0x8000000000000000);
  EXPECT_EQ(wasmFunction(0x7fffffffffffffff, -1), 0x8000000000000001);
  EXPECT_EQ(wasmFunction(0x0123456789abcdef, 0xfedcba9876543210), 0x2236d88fe5618cf0);
  EXPECT_EQ(wasmFunction(0x7fffffffffffffff, 0x7fffffffffffffff), 1);
}

} // namespace