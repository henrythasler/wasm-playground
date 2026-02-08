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

  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(1ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(0ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(2147483648ULL), static_cast<int32_t>(4294967295ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int32_t>(2147483648ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(1ULL), static_cast<int32_t>(1ULL)), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0ULL), static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(0ULL), static_cast<int32_t>(4294967295ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(4294967295ULL), static_cast<int32_t>(4294967295ULL)), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(2147483648ULL), static_cast<int32_t>(2ULL)), (static_cast<int32_t>(3221225472ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(2147483649ULL), static_cast<int32_t>(1000ULL)), (static_cast<int32_t>(4292819813ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(5ULL), static_cast<int32_t>(2ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(4294967291ULL), static_cast<int32_t>(2ULL)), (static_cast<int32_t>(4294967294ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(5ULL), static_cast<int32_t>(4294967294ULL)), (static_cast<int32_t>(4294967294ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(4294967291ULL), static_cast<int32_t>(4294967294ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(7ULL), static_cast<int32_t>(3ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(4294967289ULL), static_cast<int32_t>(3ULL)), (static_cast<int32_t>(4294967294ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(7ULL), static_cast<int32_t>(4294967293ULL)), (static_cast<int32_t>(4294967294ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(4294967289ULL), static_cast<int32_t>(4294967293ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(11ULL), static_cast<int32_t>(5ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int32_t>(17ULL), static_cast<int32_t>(7ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_THROW(wasm_div_u(static_cast<int32_t>(1ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_u(static_cast<int32_t>(0ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
}
TEST(Spectest, div_1_wasm) {
  auto wasmModule = helper::loadModule("div.1.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_div_s = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>("div_s");
  auto wasm_div_u = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>("div_u");

  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(1ULL), static_cast<int64_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(0ULL), static_cast<int64_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(9223372036854775808ULL), static_cast<int64_t>(18446744073709551615ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_s(static_cast<int64_t>(9223372036854775808ULL), static_cast<int64_t>(0ULL)), std::runtime_error);
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(1ULL), static_cast<int64_t>(1ULL)), (static_cast<int64_t>(1ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0ULL), static_cast<int64_t>(1ULL)), (static_cast<int64_t>(0ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(0ULL), static_cast<int64_t>(18446744073709551615ULL)), (static_cast<int64_t>(0ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(18446744073709551615ULL), static_cast<int64_t>(18446744073709551615ULL)), (static_cast<int64_t>(1ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(9223372036854775808ULL), static_cast<int64_t>(2ULL)), (static_cast<int64_t>(13835058055282163712ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(9223372036854775809ULL), static_cast<int64_t>(1000ULL)), (static_cast<int64_t>(18437520701672696841ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(5ULL), static_cast<int64_t>(2ULL)), (static_cast<int64_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(18446744073709551611ULL), static_cast<int64_t>(2ULL)), (static_cast<int64_t>(18446744073709551614ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(5ULL), static_cast<int64_t>(18446744073709551614ULL)), (static_cast<int64_t>(18446744073709551614ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(18446744073709551611ULL), static_cast<int64_t>(18446744073709551614ULL)), (static_cast<int64_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(7ULL), static_cast<int64_t>(3ULL)), (static_cast<int64_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(18446744073709551609ULL), static_cast<int64_t>(3ULL)), (static_cast<int64_t>(18446744073709551614ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(7ULL), static_cast<int64_t>(18446744073709551613ULL)), (static_cast<int64_t>(18446744073709551614ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(18446744073709551609ULL), static_cast<int64_t>(18446744073709551613ULL)), (static_cast<int64_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(11ULL), static_cast<int64_t>(5ULL)), (static_cast<int64_t>(2ULL)));
  EXPECT_EQ(wasm_div_s(static_cast<int64_t>(17ULL), static_cast<int64_t>(7ULL)), (static_cast<int64_t>(2ULL)));
  EXPECT_THROW(wasm_div_u(static_cast<int64_t>(1ULL), static_cast<int64_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasm_div_u(static_cast<int64_t>(0ULL), static_cast<int64_t>(0ULL)), std::runtime_error);
}
} // namespace