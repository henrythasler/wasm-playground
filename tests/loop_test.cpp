#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(loop_0_wasm, as_if_then_0) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-then");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1)));
}

TEST(loop_0_wasm, as_if_else_1) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-else");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(2)));
}

TEST(loop_0_wasm, as_br_if_first_2) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-first");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1)));
}

TEST(loop_0_wasm, as_br_if_last_3) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-last");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(2)));
}

TEST(loop_0_wasm, effects_4) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "effects");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1)));
}

TEST(loop_0_wasm, while_5) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "while");
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(0)), (static_cast<int64_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(1)), (static_cast<int64_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(2)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(3)), (static_cast<int64_t>(6)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(5)), (static_cast<int64_t>(120)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(20)), (static_cast<int64_t>(2432902008176640000)));
}

TEST(loop_0_wasm, for_6) {
  auto wasmModule = helper::loadModule("loop.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "for");
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(0)), (static_cast<int64_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(1)), (static_cast<int64_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(2)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(3)), (static_cast<int64_t>(6)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(5)), (static_cast<int64_t>(120)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(20)), (static_cast<int64_t>(2432902008176640000)));
}

} // namespace