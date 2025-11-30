#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(local0, function0) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-local-i32"));
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function1) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-local-i64"));
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function2) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-param-i32"));
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 2);
}

TEST(local0, function3) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-param-i64"));
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 3);
}

TEST(local1, function0) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("type-local-i32"));
  wasmFunction();
}

TEST(local1, function1) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("type-local-i64"));
  wasmFunction();
}

TEST(local1, function2) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-param-i64"));
  wasmFunction(2);
}

TEST(local1, function3) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-param-i64"));
  wasmFunction(3);
}

TEST(local1, function4) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-mixed"));
  wasmFunction(0, 0, 0);
}

TEST(local2, function0) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-local-i32"));
  auto res = wasmFunction();
  EXPECT_EQ(res, 1);
}

TEST(local2, function1) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-local-i64"));
  auto res = wasmFunction();
  EXPECT_EQ(res, 1);
}

TEST(local2, function2) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("type-param-i32"));
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 10);
}

TEST(local2, function3) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("type-param-i64"));
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 11);
}

TEST(local2, function4) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("as-local.set-value"));
  wasmFunction();
}

TEST(local2, function5) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-local.tee-value"));
  auto res = wasmFunction(0);
  EXPECT_EQ(res, 1);
}

} // namespace