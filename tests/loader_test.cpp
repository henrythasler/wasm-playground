#include <gtest/gtest.h>
#include <gmock/gmock.h>  // This is the key include for EXPECT_THAT

#include <filesystem>
#include <fstream>

#include "../src/modules/loader.hpp"

// Demonstrate some basic assertions.
TEST(loader, fail) {
  tiny::Loader loader = tiny::Loader();
  auto res = loader.loadFromFile("unknown.wasm");
  EXPECT_FALSE(res);
}

TEST(loader, success) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto res = loader.loadFromFile(path / "empty-fn.wasm");

  // Check that loading succeeded
  ASSERT_TRUE(res); // assertion stops the test if it fails

  std::vector<uint8_t> bytecode = loader.getBytecode();
  
  // Check that some data was loaded
  const size_t magic_size = 4;
  ASSERT_GE(bytecode.size(), magic_size); // At least 4 bytes for the magic number

  // Check that the bytecode starts with the WebAssembly magic number
  std::vector<uint8_t> magic(bytecode.begin(), bytecode.begin() + magic_size);
  EXPECT_THAT(magic, testing::ElementsAreArray({0x00, 0x61, 0x73, 0x6D})); // "\0asm"

}