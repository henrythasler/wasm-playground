#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(branch, simple_if) {
  auto wasmModule = helper::loadModule("branch.wasm");
  auto machinecode = wasmModule.getWasmFunction("simple_if")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("branch.simple-if.bin", machinecode);

  EXPECT_EQ(wasmFunction(-10), -1);
  EXPECT_EQ(wasmFunction(10), 1);
}


TEST(branch, nested_if) {
  auto wasmModule = helper::loadModule("branch.wasm");
  auto machinecode = wasmModule.getWasmFunction("nested_if")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("branch.nested-if.bin", machinecode);

  EXPECT_EQ(wasmFunction(-10), -1);
  // EXPECT_EQ(wasmFunction(1), 10);
  // EXPECT_EQ(wasmFunction(11), 100);
}

} // namespace