#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(linear_memory_data_0_wasm, read_byte_1) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(0), 72);
}

TEST(linear_memory_data_0_wasm, read_byte_2) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(1), 101);
}

TEST(linear_memory_data_0_wasm, read_byte_3) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(2), 108);
}

TEST(linear_memory_data_0_wasm, read_byte_4) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(3), 108);
}

TEST(linear_memory_data_0_wasm, read_byte_5) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(4), 111);
}

TEST(linear_memory_data_0_wasm, read_byte_6) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(5), 44);
}

TEST(linear_memory_data_0_wasm, read_byte_7) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(6), 32);
}

TEST(linear_memory_data_0_wasm, read_byte_8) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(7), 87);
}

TEST(linear_memory_data_0_wasm, read_byte_9) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(8), 101);
}

TEST(linear_memory_data_0_wasm, read_byte_10) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(9), 98);
}

TEST(linear_memory_data_0_wasm, read_byte_11) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(10), 65);
}

TEST(linear_memory_data_0_wasm, read_byte_12) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(11), 115);
}

TEST(linear_memory_data_0_wasm, read_byte_13) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(12), 115);
}

TEST(linear_memory_data_0_wasm, read_byte_14) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(13), 101);
}

TEST(linear_memory_data_0_wasm, read_byte_15) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(14), 109);
}

TEST(linear_memory_data_0_wasm, read_byte_16) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(15), 98);
}

TEST(linear_memory_data_0_wasm, read_byte_17) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(16), 108);
}

TEST(linear_memory_data_0_wasm, read_byte_18) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(17), 121);
}

TEST(linear_memory_data_0_wasm, read_byte_19) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(18), 33);
}


} // namespace