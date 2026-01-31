#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(memory_extended, init_linear_memory) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto &memory = wasmModule.getMemory();
  EXPECT_EQ(memory->minSize, 0);
  EXPECT_EQ(memory->maxSize, MAX_LINEAR_MEMORY_PAGES);
  EXPECT_EQ(memory->initData.offset, 768);
  EXPECT_EQ(memory->initData.data.at(0), '0');
  EXPECT_EQ(memory->initData.data.at(1), '1');
  EXPECT_EQ(memory->initData.data.at(15), 'F');
}

TEST(memory_extended, load_i64) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i32_t>(wasmModule, "load_i64");
  // EXPECT_EQ(wasmFunction(0), 0);
}

} // namespace