#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(block, simple) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("simple"));
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, simple_br_i32) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("simple-br-i32"));
  EXPECT_EQ(wasmFunction(), 42);
}

TEST(block, simple_br_if) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("simple-br_if"));
  EXPECT_EQ(wasmFunction(), 42);
}

TEST(block, parameter_br_if) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("parameter-br_if"));
  EXPECT_EQ(wasmFunction(1), 42);
  EXPECT_EQ(wasmFunction(-1), 42);
  EXPECT_EQ(wasmFunction(10), 42);
  EXPECT_EQ(wasmFunction(0), -4);
}

TEST(block, nested_br_if) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("nested-br_if"));
  EXPECT_EQ(wasmFunction(), 42);
}

TEST(block, simple_return) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("simple-return"));
  EXPECT_EQ(wasmFunction(), 42);
}

TEST(block, parameter_nested_return) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("parameter-nested-return"));
  EXPECT_EQ(wasmFunction(1), 42);
  EXPECT_EQ(wasmFunction(0), -4);
}

} // namespace testing