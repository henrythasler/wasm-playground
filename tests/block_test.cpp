#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(block, signed32) {
  auto wasmModule = helper::loadModule("block.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  helper::dump("block.type-i32.bin", machinecode);

  EXPECT_NO_THROW(wasmFunction());
}

} // namespace testing