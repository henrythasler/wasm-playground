#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, loop_0_wasm) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_as_if_then = instance.getFunction<wasm::wasm_i32_t>("as-if-then");
  auto wasm_as_if_else = instance.getFunction<wasm::wasm_i32_t>("as-if-else");
  auto wasm_as_br_if_first = instance.getFunction<wasm::wasm_i32_t>("as-br_if-first");
  auto wasm_as_br_if_last = instance.getFunction<wasm::wasm_i32_t>("as-br_if-last");
  auto wasm_effects = instance.getFunction<wasm::wasm_i32_t>("effects");
  auto wasm_while = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t>("while");
  auto wasm_for = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t>("for");

  EXPECT_EQ(wasm_as_if_then(), (static_cast<int32_t>(0x01ULL)));
  EXPECT_EQ(wasm_as_if_else(), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_as_br_if_first(), (static_cast<int32_t>(0x01ULL)));
  EXPECT_EQ(wasm_as_br_if_last(), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_effects(), (static_cast<int32_t>(0x01ULL)));
  EXPECT_EQ(wasm_while(static_cast<int64_t>(0x00ULL)), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_while(static_cast<int64_t>(0x01ULL)), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_while(static_cast<int64_t>(0x02ULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_while(static_cast<int64_t>(0x03ULL)), (static_cast<int64_t>(0x06ULL)));
  EXPECT_EQ(wasm_while(static_cast<int64_t>(0x05ULL)), (static_cast<int64_t>(0x78ULL)));
  EXPECT_EQ(wasm_while(static_cast<int64_t>(0x14ULL)), (static_cast<int64_t>(0x21c3677c82b40000ULL)));
  EXPECT_EQ(wasm_for(static_cast<int64_t>(0x00ULL)), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_for(static_cast<int64_t>(0x01ULL)), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_for(static_cast<int64_t>(0x02ULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_for(static_cast<int64_t>(0x03ULL)), (static_cast<int64_t>(0x06ULL)));
  EXPECT_EQ(wasm_for(static_cast<int64_t>(0x05ULL)), (static_cast<int64_t>(0x78ULL)));
  EXPECT_EQ(wasm_for(static_cast<int64_t>(0x14ULL)), (static_cast<int64_t>(0x21c3677c82b40000ULL)));
}
} // namespace