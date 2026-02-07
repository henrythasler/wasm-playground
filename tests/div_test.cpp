#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(div_0_wasm, div_s_0) {
  auto wasmModule = helper::loadModule("div.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "div_s");
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(1), static_cast<int32_t>(0)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(0), static_cast<int32_t>(0)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(2147483648), static_cast<int32_t>(4294967295)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(2147483648), static_cast<int32_t>(0)), std::runtime_error);
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1), static_cast<int32_t>(1)), (static_cast<int32_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0), static_cast<int32_t>(1)), (static_cast<int32_t>(0)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0), static_cast<int32_t>(4294967295)), (static_cast<int32_t>(0)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4294967295), static_cast<int32_t>(4294967295)), (static_cast<int32_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(2147483648), static_cast<int32_t>(2)), (static_cast<int32_t>(3221225472)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(2147483649), static_cast<int32_t>(1000)), (static_cast<int32_t>(4292819813)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(5), static_cast<int32_t>(2)), (static_cast<int32_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4294967291), static_cast<int32_t>(2)), (static_cast<int32_t>(4294967294)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(5), static_cast<int32_t>(4294967294)), (static_cast<int32_t>(4294967294)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4294967291), static_cast<int32_t>(4294967294)), (static_cast<int32_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(7), static_cast<int32_t>(3)), (static_cast<int32_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4294967289), static_cast<int32_t>(3)), (static_cast<int32_t>(4294967294)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(7), static_cast<int32_t>(4294967293)), (static_cast<int32_t>(4294967294)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4294967289), static_cast<int32_t>(4294967293)), (static_cast<int32_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(11), static_cast<int32_t>(5)), (static_cast<int32_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(17), static_cast<int32_t>(7)), (static_cast<int32_t>(2)));
}

TEST(div_0_wasm, div_u_1) {
  auto wasmModule = helper::loadModule("div.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "div_u");
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(1), static_cast<int32_t>(0)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(0), static_cast<int32_t>(0)), std::runtime_error);
}

TEST(div_1_wasm, div_s_0) {
  auto wasmModule = helper::loadModule("div.1.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "div_s");
  EXPECT_THROW(wasmFunction(static_cast<int64_t>(1), static_cast<int64_t>(0)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int64_t>(0), static_cast<int64_t>(0)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int64_t>(9223372036854775808), static_cast<int64_t>(18446744073709551615)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int64_t>(9223372036854775808), static_cast<int64_t>(0)), std::runtime_error);
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(1), static_cast<int64_t>(1)), (static_cast<int64_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(0), static_cast<int64_t>(1)), (static_cast<int64_t>(0)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(0), static_cast<int64_t>(18446744073709551615)), (static_cast<int64_t>(0)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(18446744073709551615), static_cast<int64_t>(18446744073709551615)), (static_cast<int64_t>(1)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(9223372036854775808), static_cast<int64_t>(2)), (static_cast<int64_t>(13835058055282163712)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(9223372036854775809), static_cast<int64_t>(1000)), (static_cast<int64_t>(18437520701672696841)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(5), static_cast<int64_t>(2)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(18446744073709551611), static_cast<int64_t>(2)), (static_cast<int64_t>(18446744073709551614)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(5), static_cast<int64_t>(18446744073709551614)), (static_cast<int64_t>(18446744073709551614)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(18446744073709551611), static_cast<int64_t>(18446744073709551614)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(7), static_cast<int64_t>(3)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(18446744073709551609), static_cast<int64_t>(3)), (static_cast<int64_t>(18446744073709551614)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(7), static_cast<int64_t>(18446744073709551613)), (static_cast<int64_t>(18446744073709551614)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(18446744073709551609), static_cast<int64_t>(18446744073709551613)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(11), static_cast<int64_t>(5)), (static_cast<int64_t>(2)));
  EXPECT_EQ(wasmFunction(static_cast<int64_t>(17), static_cast<int64_t>(7)), (static_cast<int64_t>(2)));
}

TEST(div_1_wasm, div_u_1) {
  auto wasmModule = helper::loadModule("div.1.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "div_u");
  EXPECT_THROW(wasmFunction(static_cast<int64_t>(1), static_cast<int64_t>(0)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int64_t>(0), static_cast<int64_t>(0)), std::runtime_error);
}

} // namespace