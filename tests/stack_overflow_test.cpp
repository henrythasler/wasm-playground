#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, stack_overflow_0_wasm) {
  auto wasmModule = helper::loadModule("stack_overflow.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_exhaust = instance.getFunction<void>("exhaust");

}
} // namespace