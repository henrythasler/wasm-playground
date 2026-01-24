#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(globals_extended, get_a) {
  // auto wasmModule = helper::loadModule("globals.0.wasm");
  // auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "get-a");

  // EXPECT_EQ(wasmFunction(), -2);
}

} // namespace