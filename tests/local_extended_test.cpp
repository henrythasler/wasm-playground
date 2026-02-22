#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(local_extended, imports) {
  auto wasmModule = helper::loadModule("local-extended.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("many_locals");
  EXPECT_EQ(_start(42), 42);
}
} // namespace