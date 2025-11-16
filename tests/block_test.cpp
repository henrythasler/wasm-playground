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
  auto wasmModule = helper::loadModule("block.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  helper::dump("block.type-i32.bin", machinecode);
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, type_i64) {
  auto wasmModule = helper::loadModule("block.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  helper::dump("block.type-i64.bin", machinecode);
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, type_i32_value) {
  auto wasmModule = helper::loadModule("block.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i32-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.type-i32-value.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 1);
}

// TEST(block, type_i64_value) {
//   auto wasmModule = helper::loadModule("block.wasm");
//   auto machinecode = wasmModule.getWasmFunction("type-i64-value")->getMachinecode();
//   auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode);
//   helper::dump("block.type-i64-value.bin", machinecode);
//   EXPECT_EQ(wasmFunction(), 2);
// }

} // namespace testing