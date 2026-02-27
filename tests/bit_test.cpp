#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(bit, ctz_i32) {
  auto wasmModule = helper::loadModule("bit.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("ctz-i32"));

  EXPECT_EQ(wasmFunction(0x01), 0);
  EXPECT_EQ(wasmFunction(0x02), 1);
  EXPECT_EQ(wasmFunction(0x08), 3);
  EXPECT_EQ(wasmFunction(0x80), 7);
  EXPECT_EQ(wasmFunction(0x80000000), 31);
}

TEST(bit, and) {
  auto wasmModule = helper::loadModule("bit.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);

  auto bitand32 = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>("bitand32");
  auto bitand64 = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>("bitand64");

  EXPECT_EQ(bitand32(0x01, 0x01), 0x01);
  EXPECT_EQ(bitand32(0x02, 0x01), 0x00);
  EXPECT_EQ(bitand32(0x88, 0x88), 0x88);
  EXPECT_EQ(bitand32(0x88, 0xFF), 0x88);
  EXPECT_EQ(bitand32(0x12345678, 0xFFFF0000), 0x12340000);

  EXPECT_EQ(bitand64(0x01, 0x01), 0x01);
  EXPECT_EQ(bitand64(0x02, 0x01), 0x00);
  EXPECT_EQ(bitand64(0x88, 0x88), 0x88);
  EXPECT_EQ(bitand64(0x88, 0xFF), 0x88);
  EXPECT_EQ(bitand64(0x123456789ABCDEF0LLU, 0x0000FFFF00000000LLU), 0x567800000000LLU);
  EXPECT_EQ(bitand64(0x123456789ABCDEF0LLU, 0xFFFF00000000FFFFLLU), 0x123400000000DEF0LLU);
}
} // namespace testing