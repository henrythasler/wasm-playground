#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(conditionals, singular) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("singular"));

  EXPECT_EQ(wasmFunction(0), 8);
  EXPECT_EQ(wasmFunction(1), 7);
  EXPECT_EQ(wasmFunction(10), 7);
  EXPECT_EQ(wasmFunction(-10), 7);
}

TEST(conditionals, return_value) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-return-value"));

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(1), 1);
}

TEST(conditionals, local_set) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-local.set-value"));

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(1), 1);
}

TEST(conditionals, local_tee) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-local.tee-value"));

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(1), 1);
}

TEST(conditionals, abs) {
  auto wasmModule = helper::loadModule("abs.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("abs"));

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(10), 10);
  EXPECT_EQ(wasmFunction(-10), 10);
  EXPECT_EQ(wasmFunction(-0x7fffffff), 0x7fffffff);
}

} // namespace