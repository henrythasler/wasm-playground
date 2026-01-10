#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(functions, basic) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto caller = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("basic"));
  auto callee = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("one"));

  EXPECT_EQ(callee(), 1);
  EXPECT_EQ(caller(), 1);
}

TEST(functions, jump_back) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("back"));

  EXPECT_EQ(wasmFunction(), 1);
}

TEST(functions, save_regs) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("four"));

  EXPECT_EQ(wasmFunction(), 4);
}

TEST(functions_indirect, calculate) {
  auto wasmModule = helper::loadModule("functions_indirect.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "calculate");

  // EXPECT_EQ(wasmFunction(0, 10, 20), 2);
}

} // namespace