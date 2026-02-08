#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, linear_memory_data_0_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_read_byte = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("read_byte");

  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(72ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(101ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(2ULL)), (static_cast<int32_t>(108ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(3ULL)), (static_cast<int32_t>(108ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(4ULL)), (static_cast<int32_t>(111ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(5ULL)), (static_cast<int32_t>(44ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(6ULL)), (static_cast<int32_t>(32ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(7ULL)), (static_cast<int32_t>(87ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(8ULL)), (static_cast<int32_t>(101ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(9ULL)), (static_cast<int32_t>(98ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(10ULL)), (static_cast<int32_t>(65ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(11ULL)), (static_cast<int32_t>(115ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(12ULL)), (static_cast<int32_t>(115ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(13ULL)), (static_cast<int32_t>(101ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(14ULL)), (static_cast<int32_t>(109ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(15ULL)), (static_cast<int32_t>(98ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(16ULL)), (static_cast<int32_t>(108ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(17ULL)), (static_cast<int32_t>(121ULL)));
  EXPECT_EQ(wasm_read_byte(static_cast<int32_t>(18ULL)), (static_cast<int32_t>(33ULL)));
}
} // namespace