#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(globals_extended, get_const0) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "get_const0");
  EXPECT_EQ(wasmFunction(), -2);
}

TEST(globals_extended, get_const1) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "get_const1");
  EXPECT_EQ(wasmFunction(), -5);
}

} // namespace