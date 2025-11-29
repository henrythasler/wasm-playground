#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(functions, basic) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  // auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode);
  helper::dump("functions.bin", machinecode);

  // EXPECT_EQ(wasmFunction(), 1);
}

} // namespace