#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, linear_memory_data_0_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_read_byte = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("read_byte");

  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x00ULL)), (static_cast<int32_t>(0x48ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x01ULL)), (static_cast<int32_t>(0x65ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x02ULL)), (static_cast<int32_t>(0x6cULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x03ULL)), (static_cast<int32_t>(0x6cULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x04ULL)), (static_cast<int32_t>(0x6fULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x05ULL)), (static_cast<int32_t>(0x2cULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x06ULL)), (static_cast<int32_t>(0x20ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x07ULL)), (static_cast<int32_t>(0x57ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x08ULL)), (static_cast<int32_t>(0x65ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x09ULL)), (static_cast<int32_t>(0x62ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x0aULL)), (static_cast<int32_t>(0x41ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x0bULL)), (static_cast<int32_t>(0x73ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x0cULL)), (static_cast<int32_t>(0x73ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x0dULL)), (static_cast<int32_t>(0x65ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x0eULL)), (static_cast<int32_t>(0x6dULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x0fULL)), (static_cast<int32_t>(0x62ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x10ULL)), (static_cast<int32_t>(0x6cULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x11ULL)), (static_cast<int32_t>(0x79ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0x12ULL)), (static_cast<int32_t>(0x21ULL)));
}
} // namespace