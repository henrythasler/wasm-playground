#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(linear_memory_data_0_wasm, read_byte_0) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "read_byte");
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0)), (static_cast<int32_t>(72)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1)), (static_cast<int32_t>(101)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(2)), (static_cast<int32_t>(108)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(3)), (static_cast<int32_t>(108)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4)), (static_cast<int32_t>(111)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(5)), (static_cast<int32_t>(44)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(6)), (static_cast<int32_t>(32)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(7)), (static_cast<int32_t>(87)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(8)), (static_cast<int32_t>(101)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(9)), (static_cast<int32_t>(98)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(10)), (static_cast<int32_t>(65)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(11)), (static_cast<int32_t>(115)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(12)), (static_cast<int32_t>(115)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(13)), (static_cast<int32_t>(101)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(14)), (static_cast<int32_t>(109)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(15)), (static_cast<int32_t>(98)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(16)), (static_cast<int32_t>(108)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(17)), (static_cast<int32_t>(121)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(18)), (static_cast<int32_t>(33)));
}

} // namespace