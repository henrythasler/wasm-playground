#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(conditionals, lt_s) {
  auto wasmModule = helper::loadModule("compare.wasm");
  auto machinecode = wasmModule.getWasmFunction("lt_s")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("compare.lt_s.bin", machinecode);

  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0), 0);
  EXPECT_EQ(wasmFunction(1, 1), 0);
  EXPECT_EQ(wasmFunction(0, 0), 0);
  EXPECT_EQ(wasmFunction(-10, 10), 1);
}

} // namespace