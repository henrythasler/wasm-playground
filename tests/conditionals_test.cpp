#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(conditionals, singular) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("singular")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("conditionals.singular.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 8);
  EXPECT_EQ(wasmFunction(1), 7);
  EXPECT_EQ(wasmFunction(10), 7);
  EXPECT_EQ(wasmFunction(-10), 7);
}

TEST(conditionals, return_value) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-return-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("conditionals.as-return-value.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(1), 1);
}

TEST(conditionals, local_set) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-local.set-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("conditionals.as-local.set-value.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(1), 1);
}

TEST(conditionals, local_tee) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-local.tee-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("conditionals.as-local.tee-value.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(1), 1);
}

TEST(conditionals, abs) {
  auto wasmModule = helper::loadModule("abs.wasm");
  auto machinecode = wasmModule.getWasmFunction("abs")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("conditionals.abs.bin", machinecode);

  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(10), 10);
  EXPECT_EQ(wasmFunction(-10), 10);
  EXPECT_EQ(wasmFunction(-0x7fffffff), 0x7fffffff);
}

} // namespace