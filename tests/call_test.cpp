#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(call, type_i32) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-i32"));

  EXPECT_EQ(wasmFunction(), 0x132);
}

TEST(call, type_i64) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-i64"));

  EXPECT_EQ(wasmFunction(), 0x164);
}

TEST(call, type_first_i32) {
  auto wasmModule = helper::loadModule("call.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-first-i32"));

  // EXPECT_EQ(wasmFunction(), 32);
}

} // namespace