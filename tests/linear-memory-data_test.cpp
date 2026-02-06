#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(linear_memory_data_0_wasm, read_byte_0) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(0), 72);
  EXPECT_EQ(wasmFunction(1), 101);
  EXPECT_EQ(wasmFunction(2), 108);
  EXPECT_EQ(wasmFunction(3), 108);
  EXPECT_EQ(wasmFunction(4), 111);
  EXPECT_EQ(wasmFunction(5), 44);
  EXPECT_EQ(wasmFunction(6), 32);
  EXPECT_EQ(wasmFunction(7), 87);
  EXPECT_EQ(wasmFunction(8), 101);
  EXPECT_EQ(wasmFunction(9), 98);
  EXPECT_EQ(wasmFunction(10), 65);
  EXPECT_EQ(wasmFunction(11), 115);
  EXPECT_EQ(wasmFunction(12), 115);
  EXPECT_EQ(wasmFunction(13), 101);
  EXPECT_EQ(wasmFunction(14), 109);
  EXPECT_EQ(wasmFunction(15), 98);
  EXPECT_EQ(wasmFunction(16), 108);
  EXPECT_EQ(wasmFunction(17), 121);
  EXPECT_EQ(wasmFunction(18), 33);
}

} // namespace