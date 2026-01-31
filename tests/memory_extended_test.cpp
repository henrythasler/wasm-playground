#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(memory_extended, init_linear_memory) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto &memory = wasmModule.getMemory();
  EXPECT_EQ(memory->minSize, 1);
  EXPECT_EQ(memory->maxSize, 4);

  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "get_byte");
  EXPECT_EQ(wasmFunction(0), 42);
}

} // namespace