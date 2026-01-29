#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

// (assert_return (invoke "get-a") (i32.const -2))
TEST(globals_extended, get_a) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "get-a");

  EXPECT_EQ(wasmFunction(), -2);
}

// (assert_return (invoke "get-b") (i64.const -5))
TEST(globals_extended, get_b) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "get-b");

  EXPECT_EQ(wasmFunction(), -5);
}

// (assert_return (invoke "get-x") (i32.const -12))
TEST(globals_extended, get_x) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "get-x");

  EXPECT_EQ(wasmFunction(), -12);
}

// (assert_return (invoke "get-y") (i64.const -15))
TEST(globals_extended, get_y) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "get-y");

  EXPECT_EQ(wasmFunction(), -5);
}

// (assert_return (invoke "set-x" (i32.const 6)))
TEST(globals_extended, set_x) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "set-x");

  EXPECT_EQ(wasmFunction(), 6);
}

// (assert_return (invoke "set-y" (i64.const 7)))
TEST(globals_extended, set_y) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "set-y");

  EXPECT_EQ(wasmFunction(), 7);
}

// (assert_return (invoke "as-if-then") (i32.const 6))
TEST(globals_extended, as_if_then) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-then");

  EXPECT_EQ(wasmFunction(), 6);
}

// (assert_return (invoke "as-if-else") (i32.const 6))
TEST(globals_extended, as_if_else) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-if-else");

  EXPECT_EQ(wasmFunction(), 6);
}

// (assert_return (invoke "as-br_if-first") (i32.const 6))
TEST(globals_extended, as_br_if_first) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-first");

  EXPECT_EQ(wasmFunction(), 6);
}

// (assert_return (invoke "as-br_if-last") (i32.const 2))
TEST(globals_extended, as_br_if_last) {
  auto wasmModule = helper::loadModule("globals.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(wasmModule, "as-br_if-larst");

  EXPECT_EQ(wasmFunction(), 2);
}

} // namespace