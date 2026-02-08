#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, linear_memory_grow_0_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-grow.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_size = instance.getFunction<wasm::wasm_i32_t>("size");
  auto wasm_store_at_zero = instance.getFunction<void>("store_at_zero");
  auto wasm_load_at_zero = instance.getFunction<wasm::wasm_i32_t>("load_at_zero");
  auto wasm_store_at_page_size = instance.getFunction<void>("store_at_page_size");
  auto wasm_load_at_page_size = instance.getFunction<wasm::wasm_i32_t>("load_at_page_size");
  auto wasm_grow = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("grow");

  // EXPECT_EQ(wasm_size(), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_size(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_size(), (static_cast<int32_t>(5ULL)));
  // EXPECT_THROW(wasm_store_at_zero(), std::runtime_error);
  // wasm_store_at_zero();
  // wasm_store_at_zero();
  // EXPECT_THROW(wasm_load_at_zero(), std::runtime_error);
  // EXPECT_EQ(wasm_load_at_zero(), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_load_at_zero(), (static_cast<int32_t>(2ULL)));
  // EXPECT_EQ(wasm_load_at_zero(), (static_cast<int32_t>(2ULL)));
  // EXPECT_EQ(wasm_load_at_zero(), (static_cast<int32_t>(2ULL)));
  // EXPECT_THROW(wasm_store_at_page_size(), std::runtime_error);
  // EXPECT_THROW(wasm_store_at_page_size(), std::runtime_error);
  // wasm_store_at_page_size();
  // EXPECT_THROW(wasm_load_at_page_size(), std::runtime_error);
  // EXPECT_THROW(wasm_load_at_page_size(), std::runtime_error);
  // EXPECT_EQ(wasm_load_at_page_size(), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_load_at_page_size(), (static_cast<int32_t>(3ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(4ULL)), (static_cast<int32_t>(1ULL)));
}
TEST(Spectest, linear_memory_grow_1_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-grow.1.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_grow = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("grow");

  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(2ULL)), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(800ULL)), (static_cast<int32_t>(3ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(65536ULL)), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(64736ULL)), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(803ULL)));
}
TEST(Spectest, linear_memory_grow_2_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-grow.2.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_grow = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("grow");

  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(2ULL)), (static_cast<int32_t>(2ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(6ULL)), (static_cast<int32_t>(4ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(0ULL)), (static_cast<int32_t>(10ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(65536ULL)), (static_cast<int32_t>(4294967295ULL)));
}
TEST(Spectest, linear_memory_grow_3_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-grow.3.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_check_memory_zero = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>("check-memory-zero");
  auto wasm_grow = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("grow");

  // EXPECT_EQ(wasm_check_memory_zero(static_cast<int32_t>(0ULL), static_cast<int32_t>(65535ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_check_memory_zero(static_cast<int32_t>(65536ULL), static_cast<int32_t>(131071ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_check_memory_zero(static_cast<int32_t>(131072ULL), static_cast<int32_t>(196607ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_check_memory_zero(static_cast<int32_t>(196608ULL), static_cast<int32_t>(262143ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_check_memory_zero(static_cast<int32_t>(262144ULL), static_cast<int32_t>(327679ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_check_memory_zero(static_cast<int32_t>(327680ULL), static_cast<int32_t>(393215ULL)), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(2ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(3ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(4ULL)));
  // EXPECT_EQ(wasm_grow(static_cast<int32_t>(1ULL)), (static_cast<int32_t>(5ULL)));
}
TEST(Spectest, linear_memory_grow_4_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-grow.4.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_as_br_value = instance.getFunction<wasm::wasm_i32_t>("as-br-value");
  auto wasm_as_br_if_cond = instance.getFunction<void>("as-br_if-cond");
  auto wasm_as_br_if_value = instance.getFunction<wasm::wasm_i32_t>("as-br_if-value");
  auto wasm_as_br_if_value_cond = instance.getFunction<wasm::wasm_i32_t>("as-br_if-value-cond");
  auto wasm_as_return_value = instance.getFunction<wasm::wasm_i32_t>("as-return-value");
  auto wasm_as_if_cond = instance.getFunction<wasm::wasm_i32_t>("as-if-cond");
  auto wasm_as_if_then = instance.getFunction<wasm::wasm_i32_t>("as-if-then");
  auto wasm_as_if_else = instance.getFunction<wasm::wasm_i32_t>("as-if-else");
  auto wasm_as_call_first = instance.getFunction<wasm::wasm_i32_t>("as-call-first");
  auto wasm_as_call_mid = instance.getFunction<wasm::wasm_i32_t>("as-call-mid");
  auto wasm_as_call_last = instance.getFunction<wasm::wasm_i32_t>("as-call-last");
  auto wasm_as_call_indirect_first = instance.getFunction<wasm::wasm_i32_t>("as-call_indirect-first");
  auto wasm_as_call_indirect_mid = instance.getFunction<wasm::wasm_i32_t>("as-call_indirect-mid");
  auto wasm_as_call_indirect_last = instance.getFunction<wasm::wasm_i32_t>("as-call_indirect-last");
  auto wasm_as_call_indirect_index = instance.getFunction<wasm::wasm_i32_t>("as-call_indirect-index");
  auto wasm_as_local_set_value = instance.getFunction<void>("as-local.set-value");
  auto wasm_as_local_tee_value = instance.getFunction<wasm::wasm_i32_t>("as-local.tee-value");
  auto wasm_as_global_set_value = instance.getFunction<void>("as-global.set-value");
  auto wasm_as_load_address = instance.getFunction<wasm::wasm_i32_t>("as-load-address");
  auto wasm_as_loadN_address = instance.getFunction<wasm::wasm_i32_t>("as-loadN-address");
  auto wasm_as_store_address = instance.getFunction<void>("as-store-address");
  auto wasm_as_store_value = instance.getFunction<void>("as-store-value");
  auto wasm_as_storeN_address = instance.getFunction<void>("as-storeN-address");
  auto wasm_as_storeN_value = instance.getFunction<void>("as-storeN-value");
  auto wasm_as_unary_operand = instance.getFunction<wasm::wasm_i32_t>("as-unary-operand");
  auto wasm_as_binary_left = instance.getFunction<wasm::wasm_i32_t>("as-binary-left");
  auto wasm_as_binary_right = instance.getFunction<wasm::wasm_i32_t>("as-binary-right");
  auto wasm_as_test_operand = instance.getFunction<wasm::wasm_i32_t>("as-test-operand");
  auto wasm_as_compare_left = instance.getFunction<wasm::wasm_i32_t>("as-compare-left");
  auto wasm_as_compare_right = instance.getFunction<wasm::wasm_i32_t>("as-compare-right");
  auto wasm_as_memory_grow_size = instance.getFunction<wasm::wasm_i32_t>("as-memory.grow-size");

  // EXPECT_EQ(wasm_as_br_value(), (static_cast<int32_t>(1ULL)));
  // wasm_as_br_if_cond();
  // EXPECT_EQ(wasm_as_br_if_value(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_as_br_if_value_cond(), (static_cast<int32_t>(6ULL)));
  // EXPECT_EQ(wasm_as_return_value(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_as_if_cond(), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_as_if_then(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_as_if_else(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_as_call_first(), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_as_call_mid(), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_as_call_last(), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_as_call_indirect_first(), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_as_call_indirect_mid(), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_EQ(wasm_as_call_indirect_last(), (static_cast<int32_t>(4294967295ULL)));
  // EXPECT_THROW(wasm_as_call_indirect_index(), std::runtime_error);
  // wasm_as_local_set_value();
  // EXPECT_EQ(wasm_as_local_tee_value(), (static_cast<int32_t>(1ULL)));
  // wasm_as_global_set_value();
  // EXPECT_EQ(wasm_as_load_address(), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_as_loadN_address(), (static_cast<int32_t>(0ULL)));
  // wasm_as_store_address();
  // wasm_as_store_value();
  // wasm_as_storeN_address();
  // wasm_as_storeN_value();
  // EXPECT_EQ(wasm_as_unary_operand(), (static_cast<int32_t>(31ULL)));
  // EXPECT_EQ(wasm_as_binary_left(), (static_cast<int32_t>(11ULL)));
  // EXPECT_EQ(wasm_as_binary_right(), (static_cast<int32_t>(9ULL)));
  // EXPECT_EQ(wasm_as_test_operand(), (static_cast<int32_t>(0ULL)));
  // EXPECT_EQ(wasm_as_compare_left(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_as_compare_right(), (static_cast<int32_t>(1ULL)));
  // EXPECT_EQ(wasm_as_memory_grow_size(), (static_cast<int32_t>(1ULL)));
}
} // namespace