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
  auto machinecode = wasmModule.getWasmFunction("simple")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  helper::dump("block.simple.bin", machinecode);
  EXPECT_NO_THROW(wasmFunction());
}

TEST(block, simple_br_i32) {
  auto wasmModule = helper::loadModule("block-extended.wasm");
  auto machinecode = wasmModule.getWasmFunction("simple-br-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
  helper::dump("block.simple-br-i32.bin", machinecode);
  EXPECT_EQ(wasmFunction(), 42);
}

// TEST(block, simple_br_if) {
//   auto wasmModule = helper::loadModule("block-extended.wasm");
//   auto machinecode = wasmModule.getWasmFunction("simple-br_if")->getMachinecode();
//   auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode);
//   helper::dump("block.simple-br_if.bin", machinecode);
//   EXPECT_EQ(wasmFunction(), 42);
// }

} // namespace testing