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

void dumpMachinecode(std::string filename, std::vector<uint8_t> data) {
  auto path = std::filesystem::path(__FILE__).parent_path() / "machinecode";
  std::filesystem::create_directories(path);

  if (!path.empty()) {
    std::ofstream outFile(path / filename, std::ios::binary);
    if (!outFile) {
      return;
    }
    outFile << std::hex << std::setw(8) << std::setfill('0');
    std::stringstream stream;
    stream.write(reinterpret_cast<const char *>(data.data()), data.size());
    for (int i = 0; i < data.size() >> 2; i++) {
      uint32_t instr = (uint32_t(stream.get()) << 24) + (uint32_t(stream.get()) << 16) + (uint32_t(stream.get()) << 8) + (uint32_t(stream.get()));
      outFile << instr << " ";
    }
    outFile.close();
    return; // Return true if loading was successful
  } else {
    return; // Return false if no path is provided
  }
}

TEST(echo, echo32) {
  auto wasmModule = testLoadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("echo32")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t, tiny::wasm_i32_t>(machinecode);

  EXPECT_EQ(wasmFunction(-1), -1);
  EXPECT_EQ(wasmFunction(10000), 10000);
  EXPECT_EQ(wasmFunction(-10000), -10000);
  EXPECT_EQ(wasmFunction(0xffffffff), 0xffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffff), 0x7fffffff);
}

TEST(echo, echo64) {
  auto wasmModule = testLoadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("echo64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t, tiny::wasm_i64_t>(machinecode);

  EXPECT_EQ(wasmFunction(-1), -1);
  EXPECT_EQ(wasmFunction(10000), 10000);
  EXPECT_EQ(wasmFunction(-10000), -10000);
  EXPECT_EQ(wasmFunction(0xffffffff), 0xffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffff), 0x7fffffff);

  EXPECT_EQ(wasmFunction(0xffffffffffffffff), 0xffffffffffffffff);
  EXPECT_EQ(wasmFunction(0x7fffffffffffffff), 0x7fffffffffffffff);
  EXPECT_EQ(wasmFunction(0x123456789ABCDEF0), 0x123456789ABCDEF0);
}

TEST(echo, geti64) {
  auto wasmModule = testLoadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("geti64")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  dumpMachinecode("geti64.hex", machinecode);

  EXPECT_EQ(wasmFunction(), 0x123456789ABCDEF0);
}

TEST(echo, geti64max) {
  auto wasmModule = testLoadModule("echo.wasm");
  auto machinecode = wasmModule.getWasmFunction("geti64max")->getBytecode();
  auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i64_t>(machinecode);
  dumpMachinecode("geti64max.hex", machinecode);

  EXPECT_EQ(wasmFunction(), 0x7fffffffffffffff);
}

} // namespace