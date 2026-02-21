#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(extern_extended, imports) {
  auto wasmModule = helper::loadModule("extern.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<wasm::wasm_i32_t>("_start");
  // EXPECT_EQ(_start(), 1);
}
} // namespace