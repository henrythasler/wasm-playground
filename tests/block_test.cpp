#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(block, type_i32) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  helper::dump("block.type-i32.bin", machinecode);
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, type_i64) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  helper::dump("block.type-i64.bin", machinecode);
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, type_i32_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i32-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.type-i32-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, type_i64_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i64-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode);
  helper::dump("block.type-i64-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 2);
}

TEST(block, as_block_first) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-block-first")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-block-first.bin", machinecode);
  EXPECT_EQ(wasmFunction(0), 2);
  EXPECT_EQ(wasmFunction(1), 3);
}

TEST(block, as_block_first_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-block-first-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-block-first-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(0), 11);
  EXPECT_EQ(wasmFunction(1), 10);
}

TEST(block, binary_left) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-binary-left")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-binary-left.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, binary_right) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-binary-right")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-binary-right.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, as_test_operand) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-test-operand")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-test-operand.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 0);
}

TEST(block, as_compare_left) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-compare-left")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-compare-left.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, as_compare_right) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-compare-right")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-compare-right.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 1);
}

TEST(block, as_br_if_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-br_if-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-br_if-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 8);
}

TEST(block, as_br_if_value_cond) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-br_if-value-cond")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.as-br_if-value-cond.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 9);
}

TEST(block, nested_br_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("nested-br-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.nested-br-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 9);
}

TEST(block, nested_br_if_value) {
  auto wasmModule = helper::loadModule("block.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("nested-br_if-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.nested-br_if-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 9);
}

} // namespace testing