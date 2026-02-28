#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, div_0_wasm) {
  auto wasmModule = helper::loadModule("div.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_div_s = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>("div_s");
  auto wasm_div_u = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>("div_u");

  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(0x01ULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(0x00ULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(0x80000000ULL), static_cast<int32_t>(0xffffffffULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(0x80000000ULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x01ULL), static_cast<int32_t>(0x01ULL)), (static_cast<int32_t>(0x01ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x00ULL), static_cast<int32_t>(0x01ULL)), (static_cast<int32_t>(0x00ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x00ULL), static_cast<int32_t>(0xffffffffULL)), (static_cast<int32_t>(0x00ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0xffffffffULL), static_cast<int32_t>(0xffffffffULL)), (static_cast<int32_t>(0x01ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x80000000ULL), static_cast<int32_t>(0x02ULL)), (static_cast<int32_t>(0xc0000000ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x80000001ULL), static_cast<int32_t>(0x3e8ULL)), (static_cast<int32_t>(0xffdf3b65ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x05ULL), static_cast<int32_t>(0x02ULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0xfffffffbULL), static_cast<int32_t>(0x02ULL)), (static_cast<int32_t>(0xfffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x05ULL), static_cast<int32_t>(0xfffffffeULL)), (static_cast<int32_t>(0xfffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0xfffffffbULL), static_cast<int32_t>(0xfffffffeULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x07ULL), static_cast<int32_t>(0x03ULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0xfffffff9ULL), static_cast<int32_t>(0x03ULL)), (static_cast<int32_t>(0xfffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x07ULL), static_cast<int32_t>(0xfffffffdULL)), (static_cast<int32_t>(0xfffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0xfffffff9ULL), static_cast<int32_t>(0xfffffffdULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x0bULL), static_cast<int32_t>(0x05ULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0x11ULL), static_cast<int32_t>(0x07ULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_THROW(wasm_div_u(static_cast<int32_t>(0x01ULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_u(static_cast<int32_t>(0x00ULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
}
TEST(Spectest, div_1_wasm) {
  auto wasmModule = helper::loadModule("div.1.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_div_s = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>("div_s");
  auto wasm_div_u = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>("div_u");

  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(0x01ULL), static_cast<int64_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(0x00ULL), static_cast<int64_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(0x8000000000000000ULL), static_cast<int64_t>(0xffffffffffffffffULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(0x8000000000000000ULL), static_cast<int64_t>(0x00ULL)), std::runtime_error);
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x01ULL), static_cast<int64_t>(0x01ULL)), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x00ULL), static_cast<int64_t>(0x01ULL)), (static_cast<int64_t>(0x00ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x00ULL), static_cast<int64_t>(0xffffffffffffffffULL)), (static_cast<int64_t>(0x00ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0xffffffffffffffffULL), static_cast<int64_t>(0xffffffffffffffffULL)), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x8000000000000000ULL), static_cast<int64_t>(0x02ULL)), (static_cast<int64_t>(0xc000000000000000ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x8000000000000001ULL), static_cast<int64_t>(0x3e8ULL)), (static_cast<int64_t>(0xffdf3b645a1cac09ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x05ULL), static_cast<int64_t>(0x02ULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0xfffffffffffffffbULL), static_cast<int64_t>(0x02ULL)), (static_cast<int64_t>(0xfffffffffffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x05ULL), static_cast<int64_t>(0xfffffffffffffffeULL)), (static_cast<int64_t>(0xfffffffffffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0xfffffffffffffffbULL), static_cast<int64_t>(0xfffffffffffffffeULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x07ULL), static_cast<int64_t>(0x03ULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0xfffffffffffffff9ULL), static_cast<int64_t>(0x03ULL)), (static_cast<int64_t>(0xfffffffffffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x07ULL), static_cast<int64_t>(0xfffffffffffffffdULL)), (static_cast<int64_t>(0xfffffffffffffffeULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0xfffffffffffffff9ULL), static_cast<int64_t>(0xfffffffffffffffdULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x0bULL), static_cast<int64_t>(0x05ULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0x11ULL), static_cast<int64_t>(0x07ULL)), (static_cast<int64_t>(0x02ULL)));
  EXPECT_THROW(wasm_div_u(static_cast<int64_t>(0x01ULL), static_cast<int64_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_u(static_cast<int64_t>(0x00ULL), static_cast<int64_t>(0x00ULL)), std::runtime_error);
}
} // namespace