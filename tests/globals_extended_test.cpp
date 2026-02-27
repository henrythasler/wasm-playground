#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(globals_extended, get_const0) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "get_const0");

  auto& globals = wasmModule.getGlobals();
  EXPECT_EQ(globals->entries.size(), 5);
  EXPECT_EQ(globals->entries.at(0).value, -2);
  EXPECT_EQ(globals->entries.at(1).value, -5);
  EXPECT_EQ(globals->entries.at(2).value, -12);
  EXPECT_EQ(globals->entries.at(3).value, 100);
  EXPECT_EQ(globals->entries.at(4).value, 186384);

  auto serialized = globals->serialize();

  std::vector<uint8_t> mem(serialized.size() * sizeof(uint64_t));
  std::memcpy(mem.data(), serialized.data(), mem.size());
  EXPECT_EQ(mem.size(), globals->entries.size() * sizeof(uint64_t));
  EXPECT_THAT(mem, testing::ElementsAreArray({
    0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xf4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0xd8, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  }));

  EXPECT_EQ(wasmFunction(), -2);
}

TEST(globals_extended, get_const1) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "get_const1");
  EXPECT_EQ(wasmFunction(), -5);
}

TEST(globals_extended, get_mut0) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "get_mut0");
  EXPECT_EQ(wasmFunction(), -12);
}

TEST(globals_extended, get_mut1) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "get_mut1");
  EXPECT_EQ(wasmFunction(), 100);
}

TEST(globals_extended, store_mut0) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "store_mut0");
  EXPECT_EQ(wasmFunction(-42), -42);
}

TEST(globals_extended, store_mut1) {
  auto wasmModule = helper::loadModule("globals-extended.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "store_mut1");
  EXPECT_EQ(wasmFunction(-42), -42);
  EXPECT_EQ(wasmFunction(UINT64_MAX), UINT64_MAX);
  EXPECT_EQ(wasmFunction(INT64_MIN), INT64_MIN);
}

} // namespace