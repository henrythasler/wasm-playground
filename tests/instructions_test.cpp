#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>
#include <iomanip>

#include "../src/modules/aarch64-instructions.hpp"

#define EXPECT_EQ_HEX(actual, expected) \
    EXPECT_EQ(actual, expected) \
        << "Expected: 0x" << std::hex << (expected) \
        << ", Got: 0x" << std::hex << (actual)

using namespace arm64;

// Demonstrate some basic assertions.
TEST(instructions, str) {
  // str w0, [sp, 24]
  EXPECT_EQ_HEX(encode_str_immediate(W0, SP, 24, size4_t::SIZE_32BIT), 0xB9001BE0);
  // str x0, [sp, 16]
  EXPECT_EQ_HEX(encode_str_immediate(X1, SP, 16, size4_t::SIZE_64BIT), 0xF9000BE1);
}

TEST(instruction, sub) {
  // sub sp, sp, #0x40
  EXPECT_EQ_HEX(encode_sub_immediate(SP, SP, 0x40, false, size2_t::SIZE_64BIT), 0xD10103FF);
  // sub w0, w0, #1
  EXPECT_EQ_HEX(encode_sub_immediate(W0, W0, 0x01, false, size2_t::SIZE_32BIT), 0x51000400);
}

TEST(instruction, add) {
  // sub sp, sp, #0x40
  EXPECT_EQ_HEX(encode_add_immediate(SP, SP, 0x40, false, size2_t::SIZE_64BIT), 0x910103FF);
  // sub w0, w0, #1
  EXPECT_EQ_HEX(encode_add_immediate(W1, W0, 0x0a, false, size2_t::SIZE_32BIT), 0x11002801);
}

TEST(instruction, mov) {
  // mov fp, sp
  EXPECT_EQ_HEX(encode_mov_sp(FP, SP, size2_t::SIZE_64BIT), 0x910003FD);
}

TEST(instruction, ret) {
  // ret
  EXPECT_EQ_HEX(encode_ret(), 0xD65F03C0);
  EXPECT_EQ_HEX(encode_ret(X8), 0xD65F0100);
}