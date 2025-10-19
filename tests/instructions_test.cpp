#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>
#include <iomanip>

#include "../src/modules/instructions.hpp"

#define EXPECT_EQ_HEX(actual, expected) \
    EXPECT_EQ(actual, expected) \
        << "Expected: 0x" << std::hex << (expected) \
        << ", Got: 0x" << std::hex << (actual)

// Demonstrate some basic assertions.
TEST(instructions, str) {
  // str w0, [sp, 24]
  EXPECT_EQ_HEX(encode_str_unsigned_offset(W0, SP, 24, SIZE_32BIT), 0xB9001BE0);
  // str x0, [sp, 16]
  EXPECT_EQ_HEX(encode_str_unsigned_offset(X1, SP, 16, SIZE_64BIT), 0xF9000BE1);
}