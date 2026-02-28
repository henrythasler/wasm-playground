#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, linear_memory_store_0_wasm) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_as_block_value = instance.getFunction<void>("as-block-value");
  auto wasm_as_loop_value = instance.getFunction<void>("as-loop-value");
  auto wasm_as_br_value = instance.getFunction<void>("as-br-value");
  auto wasm_as_br_if_value = instance.getFunction<void>("as-br_if-value");
  auto wasm_as_br_if_value_cond = instance.getFunction<void>("as-br_if-value-cond");
  auto wasm_as_return_value = instance.getFunction<void>("as-return-value");
  auto wasm_as_if_then = instance.getFunction<void>("as-if-then");
  auto wasm_as_if_else = instance.getFunction<void>("as-if-else");
  auto wasm_address_as_param = instance.getFunction<void, wasm::wasm_i32_t, wasm::wasm_i32_t>("address-as-param");

  wasm_as_block_value();
  wasm_as_loop_value();
  wasm_as_br_value();
  wasm_as_br_if_value();
  wasm_as_br_if_value_cond();
  wasm_as_return_value();
  wasm_as_if_then();
  wasm_as_if_else();
  EXPECT_THROW(wasm_address_as_param(static_cast<int32_t>(0xffffffULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
  EXPECT_THROW(wasm_address_as_param(static_cast<int32_t>(0xfffeULL), static_cast<int32_t>(0x00ULL)), std::runtime_error);
}
} // namespace