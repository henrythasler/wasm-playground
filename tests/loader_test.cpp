#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

#include "../src/modules/tiny-loader.hpp"

// Demonstrate some basic assertions.
TEST(loader, fail) {
  tiny::Loader loader = tiny::Loader();
  auto res = loader.loadFromFile("unknown.wasm");
  EXPECT_FALSE(res);
}

TEST(loader, success) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto res = loader.loadFromFile(path / "nop-fn.wasm");
  EXPECT_TRUE(res);
  auto bytecode = loader.getBytecode();
  EXPECT_GT(bytecode.size(), 0);
  // Check that the bytecode starts with the WebAssembly magic number
  EXPECT_EQ(bytecode[0], 0x00);
  EXPECT_EQ(bytecode[1], 0x61);
  EXPECT_EQ(bytecode[2], 0x73);
  EXPECT_EQ(bytecode[3], 0x6d);
}