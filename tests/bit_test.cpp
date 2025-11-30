#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(bit, ctz_i32) {
  auto wasmModule = helper::loadModule("bit.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("ctz-i32"));

  EXPECT_EQ(wasmFunction(0x01), 0);
  EXPECT_EQ(wasmFunction(0x02), 1);
  EXPECT_EQ(wasmFunction(0x08), 3);
  EXPECT_EQ(wasmFunction(0x80), 7);
  EXPECT_EQ(wasmFunction(0x80000000), 31);
}

} // namespace testing