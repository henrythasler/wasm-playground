#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(extern_extended, myPrint) {
  auto wasmModule = helper::loadModule("extern.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto increment = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("increment");
  auto simplePrint = instance.getFunction<wasm::wasm_i32_t>("simplePrint");
  auto mixedPrint = instance.getFunction<wasm::wasm_i32_t>("mixedPrint");
  auto complexPrint = instance.getFunction<wasm::wasm_i32_t>("complexPrint");
  auto _start = instance.getFunction<wasm::wasm_i32_t>("_start");

  // Test the increment function
  EXPECT_EQ(increment(32), 33);
  EXPECT_EQ(increment(-2), -1);

  // "1 2 9223372036854775807\n" has length 24
  EXPECT_EQ(simplePrint(), 24);

  // "[mixed] 1 2 9223372036854775807 48879 -3 -4\n" has length 44
  EXPECT_EQ(mixedPrint(), 44);

  // len("[mixed] 1 2 9223372036854775807 48879 -3 -4\n") == 44
  EXPECT_EQ(complexPrint(), 44);
  EXPECT_EQ(_start(), 44);
}

TEST(extern, myPrint) {
  auto wasmModule = helper::loadModule("myPrint.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<void>("_start");
  EXPECT_NO_THROW(_start());
}

TEST(extern, fractal) {
  auto wasmModule = helper::loadModule("fractal.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto _start = instance.getFunction<void>("_start");
  EXPECT_NO_THROW(_start());
}

} // namespace