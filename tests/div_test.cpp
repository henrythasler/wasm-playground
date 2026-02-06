#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(div_0_wasm, div_s_0) {
  auto wasmModule = helper::loadModule("div.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "div_s");
  EXPECT_THROW(wasmFunction(1, 0), std::runtime_error);
  EXPECT_THROW(wasmFunction(0, 0), std::runtime_error);
  EXPECT_THROW(wasmFunction(2147483648, 4294967295), std::runtime_error);
  EXPECT_THROW(wasmFunction(2147483648, 0), std::runtime_error);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(0, 4294967295), 0);
  EXPECT_EQ(wasmFunction(4294967295, 4294967295), 1);
  EXPECT_EQ(wasmFunction(2147483648, 2), 3221225472);
  EXPECT_EQ(wasmFunction(2147483649, 1000), 4292819813);
  EXPECT_EQ(wasmFunction(5, 2), 2);
  EXPECT_EQ(wasmFunction(4294967291, 2), 4294967294);
  EXPECT_EQ(wasmFunction(5, 4294967294), 4294967294);
  EXPECT_EQ(wasmFunction(4294967291, 4294967294), 2);
  EXPECT_EQ(wasmFunction(7, 3), 2);
  EXPECT_EQ(wasmFunction(4294967289, 3), 4294967294);
  EXPECT_EQ(wasmFunction(7, 4294967293), 4294967294);
  EXPECT_EQ(wasmFunction(4294967289, 4294967293), 2);
  EXPECT_EQ(wasmFunction(11, 5), 2);
  EXPECT_EQ(wasmFunction(17, 7), 2);
}

TEST(div_0_wasm, div_u_1) {
  auto wasmModule = helper::loadModule("div.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "div_u");
  EXPECT_THROW(wasmFunction(1, 0), std::runtime_error);
  EXPECT_THROW(wasmFunction(0, 0), std::runtime_error);
}

TEST(div_1_wasm, div_s_0) {
  auto wasmModule = helper::loadModule("div.1.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "div_s");
  EXPECT_THROW(wasmFunction(1, 0), std::runtime_error);
  EXPECT_THROW(wasmFunction(0, 0), std::runtime_error);
  EXPECT_THROW(wasmFunction(9223372036854775808, 18446744073709551615), std::runtime_error);
  EXPECT_THROW(wasmFunction(9223372036854775808, 0), std::runtime_error);
  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(0, 18446744073709551615), 0);
  EXPECT_EQ(wasmFunction(18446744073709551615, 18446744073709551615), 1);
  EXPECT_EQ(wasmFunction(9223372036854775808, 2), 13835058055282163712);
  EXPECT_EQ(wasmFunction(9223372036854775809, 1000), 18437520701672696841);
  EXPECT_EQ(wasmFunction(5, 2), 2);
  EXPECT_EQ(wasmFunction(18446744073709551611, 2), 18446744073709551614);
  EXPECT_EQ(wasmFunction(5, 18446744073709551614), 18446744073709551614);
  EXPECT_EQ(wasmFunction(18446744073709551611, 18446744073709551614), 2);
  EXPECT_EQ(wasmFunction(7, 3), 2);
  EXPECT_EQ(wasmFunction(18446744073709551609, 3), 18446744073709551614);
  EXPECT_EQ(wasmFunction(7, 18446744073709551613), 18446744073709551614);
  EXPECT_EQ(wasmFunction(18446744073709551609, 18446744073709551613), 2);
  EXPECT_EQ(wasmFunction(11, 5), 2);
  EXPECT_EQ(wasmFunction(17, 7), 2);
}

TEST(div_1_wasm, div_u_1) {
  auto wasmModule = helper::loadModule("div.1.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(wasmModule, "div_u");
  EXPECT_THROW(wasmFunction(1, 0), std::runtime_error);
  EXPECT_THROW(wasmFunction(0, 0), std::runtime_error);
}

} // namespace