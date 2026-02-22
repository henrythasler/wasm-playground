#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(local_extended, many_locals) {
  auto wasmModule = helper::loadModule("local-extended.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("many_locals");
  EXPECT_EQ(_start(42), 42);
}

TEST(local_extended, store_i64) {
  auto wasmModule = helper::loadModule("local-extended.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto store_i64 = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t>("store_i64");
  auto store_i64_const = instance.getFunction<wasm::wasm_i64_t>("store_i64_const");

  EXPECT_EQ(store_i64(0x123456789ABCDEF0ULL), 0x123456789ABCDEF0ULL);
  EXPECT_EQ(store_i64_const(), 9223372036854775807ULL);  
}

} // namespace