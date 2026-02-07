#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(memory_extended, init_linear_memory) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto &memory = wasmModule.getMemory();
  EXPECT_EQ(memory->minSize, 0);
  EXPECT_EQ(memory->maxSize, wasm::MAX_LINEAR_MEMORY_PAGES);
  EXPECT_EQ(memory->init.offset, 767);
  EXPECT_EQ(memory->init.data.at(1), '0');
  EXPECT_EQ(memory->init.data.at(2), '1');
  EXPECT_EQ(memory->init.data.at(16), 'F');
}

TEST(memory_extended, load_i64) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i32_t>(wasmModule, "load_i64");
  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(200), 0);
  EXPECT_EQ(wasmFunction(768), 0x3736353433323130);
  EXPECT_EQ(wasmFunction(768 + 8), 0x4645444342413938);
  EXPECT_EQ(wasmFunction(768 + 16), 0x0);
}

TEST(memory_extended, load_i32) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "load_i32");
  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(200), 0);
  EXPECT_EQ(wasmFunction(768), 0x33323130);
  EXPECT_EQ(wasmFunction(768 + 4), 0x37363534);
  EXPECT_EQ(wasmFunction(768 + 16), 0x0);
}

TEST(memory_extended, load_u16) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "load_u16");
  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(200), 0);
  EXPECT_EQ(wasmFunction(768), 0x3130);
  EXPECT_EQ(wasmFunction(768 + 2), 0x3332);
  EXPECT_EQ(wasmFunction(768 + 16), 0x0);
}

TEST(memory_extended, load_u8) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "load_u8");
  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(200), 0);
  EXPECT_EQ(wasmFunction(768), 0x30);
  EXPECT_EQ(wasmFunction(768 + 1), 0x31);
  EXPECT_EQ(wasmFunction(768 + 15), 0x46);
  EXPECT_EQ(wasmFunction(768 + 16), 0x0);
}

TEST(memory_extended, load_i8) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "load_i8");
  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(200), 0);
  EXPECT_EQ(wasmFunction(767), -3);
  EXPECT_EQ(wasmFunction(768 + 16), 0x0);
}

TEST(memory_extended, load_u8_offset) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "load_u8_offset");
  EXPECT_EQ(wasmFunction(0), 0x30);
  EXPECT_EQ(wasmFunction(1), 0x31);
  EXPECT_EQ(wasmFunction(15), 0x46);
  EXPECT_EQ(wasmFunction(16), 0x0);
}

TEST(memory_extended, store_i64) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i32_t, wasm::wasm_i64_t>(wasmModule, "store_i64");
  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(0, 0x3736353433323130), 0x3736353433323130);
}

TEST(memory_extended, store_i32) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "store_i32");
  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0x33323130), 0x33323130);
}

TEST(memory_extended, store_i16) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "store_i16");
  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0x3130), 0x3130);
}

TEST(memory_extended, store_i8) {
  auto wasmModule = helper::loadModule("memory.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "store_i8");
  EXPECT_EQ(wasmFunction(0, 1), 1);
  EXPECT_EQ(wasmFunction(1, 0x33), 0x33);
}

TEST(memory_extended_grow, load_i32) {
  auto wasmModule = helper::loadModule("memory-grow.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "load_i32");
  EXPECT_EQ(wasmFunction(0), 0);
  EXPECT_EQ(wasmFunction(0x1000), 0);
}

TEST(memory_extended_grow, memory_grow) {
  auto wasmModule = helper::loadModule("memory-grow.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "memory_grow");
  EXPECT_EQ(wasmFunction(1), 1);
  EXPECT_EQ(wasmFunction(255), -1);
}
} // namespace