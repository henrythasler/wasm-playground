#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(extern_extended, myPrint) {
  auto wasmModule = helper::loadModule("extern.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<wasm::wasm_i32_t>("_start");
  // len("[mixed] 1 2 9223372036854775807 48879 -3 -4\n") == 44
  EXPECT_EQ(_start(), 44);
}

TEST(extern, myPrint) {
  auto wasmModule = helper::loadModule("myPrint.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<void>("_start");
  _start();
}

} // namespace