#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/module.hpp"
#include "../src/modules/loader.hpp"
#include "../src/modules/runtime.hpp"

namespace {
std::vector<tiny::WasmFunction> loadModule(std::string filename) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / filename);
  std::vector<uint8_t> bytecode = loader.getBytecode();
  return tiny::WasmModule().compileModule(bytecode);
}

TEST(local0, function0) {
  SCOPED_TRACE("local.0.wasm");
  auto wasmModule = loadModule("local.0.wasm");
  auto machinecode = wasmModule.at(0).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function1) {
  SCOPED_TRACE("local.0.wasm");
  auto wasmModule = loadModule("local.0.wasm");
  auto machinecode = wasmModule.at(1).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function2) {
  SCOPED_TRACE("local.0.wasm");
  auto wasmModule = loadModule("local.0.wasm");
  auto machinecode = wasmModule.at(2).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 2);
}

TEST(local0, function3) {
  SCOPED_TRACE("local.0.wasm");
  auto wasmModule = loadModule("local.0.wasm");
  auto machinecode = wasmModule.at(3).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 3);
}
} // namespace