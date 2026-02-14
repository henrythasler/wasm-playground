#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(loop_extended, loop_n) {
  auto wasmModule = helper::loadModule("loop-extended.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  auto loop_n = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>("loop_n");
  EXPECT_EQ(loop_n(0, 10), 10);
}

} // namespace testing