#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

namespace {
tiny::WasmModule testLoadModule(std::string filename) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / filename);
  std::vector<uint8_t> bytecode = loader.getBytecode();
  return tiny::WasmModule(bytecode);
}

TEST(local0, function0) {
  auto wasmModule = testLoadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i32")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function1) {
  auto wasmModule = testLoadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function2) {
  auto wasmModule = testLoadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i32")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 2);
}

TEST(local0, function3) {
  auto wasmModule = testLoadModule("local.0.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 3);
}

TEST(local1, function0) {
  auto wasmModule = testLoadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i32")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  wasmFunction();
}

TEST(local1, function1) {
  auto wasmModule = testLoadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  wasmFunction();
}

TEST(local1, function2) {
  auto wasmModule = testLoadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<void, tiny::wasm_i32_t>(machinecode);
  wasmFunction(2);
}

TEST(local1, function3) {
  auto wasmModule = testLoadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<void, tiny::wasm_i32_t>(machinecode);
  wasmFunction(3);
}

TEST(local1, function4) {
  auto wasmModule = testLoadModule("local.1.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-mixed")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<void, tiny::wasm_i64_t, tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  wasmFunction(0, 0, 0);
}

TEST(local2, function0) {
  auto wasmModule = testLoadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i32")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 1);
}

TEST(local2, function1) {
  auto wasmModule = testLoadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-local-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 1);
}

TEST(local2, function2) {
  auto wasmModule = testLoadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i32")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 10);
}

TEST(local2, function3) {
  auto wasmModule = testLoadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("type-param-i64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 11);
}

TEST(local2, function4) {
  auto wasmModule = testLoadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-local.set-value")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode);
  wasmFunction();
}

TEST(local2, function5) {
  auto wasmModule = testLoadModule("local.2.wasm");
  auto machinecode = wasmModule.getWasmFunction("as-local.tee-value")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(0);
  EXPECT_EQ(res, 1);
}

} // namespace