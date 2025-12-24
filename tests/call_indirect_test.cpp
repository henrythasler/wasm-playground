#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(call, type_i32) {
  auto wasmModule = helper::loadModule("call_indirect.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("callt"));

  // EXPECT_EQ(wasmFunction(0), 1);
}

} // namespace