#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(linear_memory_load_0_wasm, as_br_value_0) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_br_if_cond_1) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-br_if-cond");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_br_if_value_2) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_br_if_value_cond_3) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-value-cond");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(7ULL)));
}

TEST(linear_memory_load_0_wasm, as_return_value_4) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-return-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_if_cond_5) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-cond");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_load_0_wasm, as_if_then_6) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-then");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_if_else_7) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-else");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_call_first_8) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call-first");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_load_0_wasm, as_call_mid_9) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call-mid");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_load_0_wasm, as_call_last_10) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call-last");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_load_0_wasm, as_local_set_value_11) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-local.set-value");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_local_tee_value_12) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-local.tee-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_global_set_value_13) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-global.set-value");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_load_address_14) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-load-address");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_loadN_address_15) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-loadN-address");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_load_0_wasm, as_store_address_16) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-store-address");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_store_value_17) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-store-value");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_storeN_address_18) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-storeN-address");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_storeN_value_19) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-storeN-value");
  wasmFunction();
}

TEST(linear_memory_load_0_wasm, as_unary_operand_20) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-unary-operand");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(32ULL)));
}

TEST(linear_memory_load_0_wasm, as_binary_left_21) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-binary-left");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(10ULL)));
}

TEST(linear_memory_load_0_wasm, as_binary_right_22) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-binary-right");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(10ULL)));
}

TEST(linear_memory_load_0_wasm, as_test_operand_23) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-test-operand");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_load_0_wasm, as_compare_left_24) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-compare-left");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_load_0_wasm, as_compare_right_25) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-compare-right");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_load_0_wasm, as_memory_grow_size_26) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-memory.grow-size");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_load_0_wasm, address_as_param_27) {
  auto wasmModule = helper::loadModule("linear-memory-load.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "address-as-param");
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(4294967040ULL)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(65534ULL)), std::runtime_error);
}

} // namespace