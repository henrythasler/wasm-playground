#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(division, signed32) {
  auto wasmModule = helper::loadModule("division.wasm");
  auto machinecode = wasmModule.getWasmFunction("div_s32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("division.div_s32.bin", machinecode);

  EXPECT_EQ(wasmFunction(10, 1), 10);
}

} // namespace