#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(conditionals, singular) {
  auto wasmModule = helper::loadModule("conditionals.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("singular")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  helper::dump("conditionals.singular.bin", machinecode);

  // EXPECT_EQ(wasmFunction(0), 8);
  // EXPECT_EQ(wasmFunction(1), 7);
  // EXPECT_EQ(wasmFunction(10), 7);
  // EXPECT_EQ(wasmFunction(-10), 7);
}

} // namespace