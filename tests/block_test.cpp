#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(block, type_i32) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("type-i32"));
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, type_i64) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("type-i64"));
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, type_i32_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-i32-value"));
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, type_i64_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-i64-value"));
  EXPECT_EQ(wasmFunction(), 2);
}

TEST(block, as_block_first) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-block-first"));
  EXPECT_EQ(wasmFunction(0), 2);
  EXPECT_EQ(wasmFunction(1), 3);
}

TEST(block, as_block_first_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-block-first-value"));
  EXPECT_EQ(wasmFunction(0), 11);
  EXPECT_EQ(wasmFunction(1), 10);
}

TEST(block, binary_left) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-binary-left"));
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, binary_right) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-binary-right"));
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, as_test_operand) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-test-operand"));
  EXPECT_EQ(wasmFunction(), 0);
}

TEST(block, as_compare_left) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-compare-left"));
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, as_compare_right) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-compare-right"));
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, as_br_if_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-br_if-value"));
  EXPECT_EQ(wasmFunction(), 8);
}

TEST(block, as_br_if_value_cond) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-br_if-value-cond"));
  EXPECT_EQ(wasmFunction(), 9);
}

TEST(block, nested_br_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("nested-br-value"));
  EXPECT_EQ(wasmFunction(), 9);
}

TEST(block, nested_br_if_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("nested-br_if-value"));
  EXPECT_EQ(wasmFunction(), 9);
}

} // namespace testing