#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(linear_memory_store_0_wasm, as_block_value_0) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-block-value");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_loop_value_1) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-loop-value");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_br_value_2) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-br-value");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_br_if_value_3) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-br_if-value");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_br_if_value_cond_4) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-br_if-value-cond");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_return_value_5) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-return-value");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_if_then_6) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-if-then");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, as_if_else_7) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void>(wasmModule, "as-if-else");
  wasmFunction();
}

TEST(linear_memory_store_0_wasm, address_as_param_8) {
  auto wasmModule = helper::loadModule("linear-memory-store.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "address-as-param");
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(16777215ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
  EXPECT_THROW(wasmFunction(static_cast<int32_t>(65534ULL), static_cast<int32_t>(0ULL)), std::runtime_error);
}

} // namespace