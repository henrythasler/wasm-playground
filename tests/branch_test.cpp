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

TEST(branch, simple_if_add1) {
  auto wasmModule = helper::loadModule("branch.wasm");
  auto machinecode = wasmModule.getWasmFunction("simple_if_add1")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("branch.simple-if-add1.bin", machinecode);

  EXPECT_EQ(wasmFunction(-1), 0);
  EXPECT_EQ(wasmFunction(1), 2);
}

TEST(branch, nested_if) {
  auto wasmModule = helper::loadModule("branch.wasm");
  auto machinecode = wasmModule.getWasmFunction("nested_if")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("branch.nested-if.bin", machinecode);

  EXPECT_EQ(wasmFunction(10), 1);
  EXPECT_EQ(wasmFunction(-1), -10);
  EXPECT_EQ(wasmFunction(-11), -100);
}

TEST(branch, nested_else) {
  auto wasmModule = helper::loadModule("branch.wasm");
  auto machinecode = wasmModule.getWasmFunction("nested_else")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("branch.nested-else.bin", machinecode);

  EXPECT_EQ(wasmFunction(-10), -1);
  EXPECT_EQ(wasmFunction(1), 10);
  EXPECT_EQ(wasmFunction(11), 100);
}
  
TEST(branch, nested_else_add1) {
  auto wasmModule = helper::loadModule("branch.wasm");
  auto machinecode = wasmModule.getWasmFunction("nested_else_add1")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  helper::dump("branch.nested-else-add1.bin", machinecode);

  EXPECT_EQ(wasmFunction(-10), 0);
  EXPECT_EQ(wasmFunction(1), 11);
  EXPECT_EQ(wasmFunction(11), 101);
}

} // namespace