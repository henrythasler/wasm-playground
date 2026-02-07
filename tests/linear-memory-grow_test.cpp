#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(linear_memory_grow_0_wasm, size_0) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "size");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(5ULL)));
}

TEST(linear_memory_grow_0_wasm, store_at_zero_1) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "store_at_zero");
  EXPECT_THROW(wasmFunction(), std::runtime_error);
  wasmFunction();
  wasmFunction();
}

TEST(linear_memory_grow_0_wasm, load_at_zero_2) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "load_at_zero");
  EXPECT_THROW(wasmFunction(), std::runtime_error);
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(2ULL)));
}

TEST(linear_memory_grow_0_wasm, store_at_page_size_3) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "store_at_page_size");
  EXPECT_THROW(wasmFunction(), std::runtime_error);
  EXPECT_THROW(wasmFunction(), std::runtime_error);
  wasmFunction();
}

TEST(linear_memory_grow_0_wasm, load_at_page_size_4) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "load_at_page_size");
  EXPECT_THROW(wasmFunction(), std::runtime_error);
  EXPECT_THROW(wasmFunction(), std::runtime_error);
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(3ULL)));
}

TEST(linear_memory_grow_0_wasm, grow_5) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "grow");
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(4ULL)), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_1_wasm, grow_0) {
  auto wasmModule = helper::loadModule("linear-memory-grow.1.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "grow");
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(2ULL)), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(800ULL)), (static_cast<int32_t>(3ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(65536ULL)), (static_cast<int32_t>(4294967295ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(64736ULL)), (static_cast<int32_t>(4294967295ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(803ULL)));
}

TEST(linear_memory_grow_2_wasm, grow_0) {
  auto wasmModule = helper::loadModule("linear-memory-grow.2.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "grow");
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(2ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(6ULL)), (static_cast<int32_t>(4ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(10ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(4294967295ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(65536ULL)), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_3_wasm, check_memory_zero_0) {
  auto wasmModule = helper::loadModule("linear-memory-grow.3.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "check-memory-zero");
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(0ULL), static_cast<int32_t>(65535ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(65536ULL), static_cast<int32_t>(131071ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(131072ULL), static_cast<int32_t>(196607ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(196608ULL), static_cast<int32_t>(262143ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(262144ULL), static_cast<int32_t>(327679ULL)), (static_cast<int32_t>(0ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(327680ULL), static_cast<int32_t>(393215ULL)), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_grow_3_wasm, grow_1) {
  auto wasmModule = helper::loadModule("linear-memory-grow.3.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "grow");
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(1ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(2ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(3ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(4ULL)));
  EXPECT_EQ(wasmFunction(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(5ULL)));
}

TEST(linear_memory_grow_4_wasm, as_br_value_0) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_br_if_cond_1) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-br_if-cond");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_br_if_value_2) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_br_if_value_cond_3) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-value-cond");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(6ULL)));
}

TEST(linear_memory_grow_4_wasm, as_return_value_4) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-return-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_if_cond_5) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-cond");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_grow_4_wasm, as_if_then_6) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-then");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_if_else_7) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-else");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_first_8) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call-first");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_mid_9) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call-mid");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_last_10) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call-last");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_indirect_first_11) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call_indirect-first");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_indirect_mid_12) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call_indirect-mid");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_indirect_last_13) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call_indirect-last");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(4294967295ULL)));
}

TEST(linear_memory_grow_4_wasm, as_call_indirect_index_14) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-call_indirect-index");
  EXPECT_THROW(wasmFunction(), std::runtime_error);
}

TEST(linear_memory_grow_4_wasm, as_local_set_value_15) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-local.set-value");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_local_tee_value_16) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-local.tee-value");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_global_set_value_17) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-global.set-value");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_load_address_18) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-load-address");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_grow_4_wasm, as_loadN_address_19) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-loadN-address");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_grow_4_wasm, as_store_address_20) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-store-address");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_store_value_21) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-store-value");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_storeN_address_22) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-storeN-address");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_storeN_value_23) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-storeN-value");
  wasmFunction();
}

TEST(linear_memory_grow_4_wasm, as_unary_operand_24) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-unary-operand");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(31ULL)));
}

TEST(linear_memory_grow_4_wasm, as_binary_left_25) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-binary-left");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(11ULL)));
}

TEST(linear_memory_grow_4_wasm, as_binary_right_26) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-binary-right");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(9ULL)));
}

TEST(linear_memory_grow_4_wasm, as_test_operand_27) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-test-operand");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(0ULL)));
}

TEST(linear_memory_grow_4_wasm, as_compare_left_28) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-compare-left");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_compare_right_29) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-compare-right");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

TEST(linear_memory_grow_4_wasm, as_memory_grow_size_30) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-memory.grow-size");
  EXPECT_EQ(wasmFunction(), (static_cast<int32_t>(1ULL)));
}

} // namespace