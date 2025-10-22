#include <gtest/gtest.h>
#include <gmock/gmock.h>  // This is the key include for EXPECT_THAT

#include <filesystem>
#include <fstream>

#include "../src/modules/loader.hpp"
#include "../src/modules/assembler.hpp"
#include "../src/modules/runtime.hpp"

// Demonstrate some basic assertions.
TEST(local0, function0) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / "local.0.wasm");

  // Check that loading succeeded
  ASSERT_TRUE(loadSuccess); // assertion stops the test if it fails

  std::vector<uint8_t> bytecode = loader.getBytecode();

  auto wasmModule = tiny::Assembler().compileModule(bytecode);
  auto machinecode = wasmModule.at(0).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function1) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / "local.0.wasm");

  // Check that loading succeeded
  ASSERT_TRUE(loadSuccess); // assertion stops the test if it fails

  std::vector<uint8_t> bytecode = loader.getBytecode();

  auto wasmModule = tiny::Assembler().compileModule(bytecode);
  auto machinecode = wasmModule.at(1).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction();
  EXPECT_EQ(res, 0);
}

TEST(local0, function2) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / "local.0.wasm");

  // Check that loading succeeded
  ASSERT_TRUE(loadSuccess); // assertion stops the test if it fails

  std::vector<uint8_t> bytecode = loader.getBytecode();

  auto wasmModule = tiny::Assembler().compileModule(bytecode);
  auto machinecode = wasmModule.at(2).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);
  auto res = wasmFunction(2);
  EXPECT_EQ(res, 2);
}

TEST(local0, function3) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / "local.0.wasm");

  // Check that loading succeeded
  ASSERT_TRUE(loadSuccess); // assertion stops the test if it fails

  std::vector<uint8_t> bytecode = loader.getBytecode();

  auto wasmModule = tiny::Assembler().compileModule(bytecode);
  auto machinecode = wasmModule.at(3).getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);
  auto res = wasmFunction(3);
  EXPECT_EQ(res, 3);
}