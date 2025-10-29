#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(local0, function0) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function1) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function2) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 2);
}

TEST(local0, function3) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 3);
}

TEST(local1, function0) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  wasmFunction();
}

TEST(local1, function1) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  wasmFunction();
}

TEST(local1, function2) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void, tiny::wasm_i32_t>(machinecode);
  wasmFunction(2);
}

TEST(local1, function3) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void, tiny::wasm_i32_t>(machinecode);
  wasmFunction(3);
}

TEST(local1, function4) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-mixed")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void, tiny::wasm_i64_t, tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  wasmFunction(0, 0, 0);
}

TEST(local2, function0) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 1);
}

TEST(local2, function1) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 1);
}

TEST(local2, function2) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 10);
}

TEST(local2, function3) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 11);
}

TEST(local2, function4) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-local.set-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  wasmFunction();
}

TEST(local2, function5) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-local.tee-value")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(0);
  helper::dump("as-local.tee-value.bin", machinecode);
  EXPECT_EQ(res, 1);
}

} // namespace