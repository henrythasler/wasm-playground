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

TEST(instructions, ldr) {
  // ldrb w8, [sp, 1]
  EXPECT_EQ_HEX(encode_ldr_unsigned_offset(W8, SP, 1, reg_size_t::SIZE_8BIT), 0x394007E8);
  // ldrh w9, [sp, 6]
  EXPECT_EQ_HEX(encode_ldr_unsigned_offset(W9, SP, 6, reg_size_t::SIZE_16BIT), 0x79400FE9);
  // ldr w0, [sp, 24]
  EXPECT_EQ_HEX(encode_ldr_unsigned_offset(W0, SP, 24, reg_size_t::SIZE_32BIT), 0xB9401BE0);
  // ldr x1, [sp, 16]
  EXPECT_EQ_HEX(encode_ldr_unsigned_offset(X1, SP, 16, reg_size_t::SIZE_64BIT), 0xF9400BE1);
}

TEST(instructions, str) {
  // strb w8, [sp, 1]
  EXPECT_EQ_HEX(encode_str_unsigned_offset(W8, SP, 1, reg_size_t::SIZE_8BIT), 0x390007E8);
  // strh w9, [sp, 6]
  EXPECT_EQ_HEX(encode_str_unsigned_offset(W9, SP, 6, reg_size_t::SIZE_16BIT), 0x79000FE9);
  // str w0, [sp, 24]
  EXPECT_EQ_HEX(encode_str_unsigned_offset(W0, SP, 24, reg_size_t::SIZE_32BIT), 0xB9001BE0);
  // str x1, [sp, 16]
  EXPECT_EQ_HEX(encode_str_unsigned_offset(X1, SP, 16, reg_size_t::SIZE_64BIT), 0xF9000BE1);
}

TEST(instruction, sub) {
  // sub sp, sp, #0x40
  EXPECT_EQ_HEX(encode_sub_immediate(SP, SP, 0x40, false, reg_size_t::SIZE_64BIT), 0xD10103FF);
  // sub w0, w0, #1
  EXPECT_EQ_HEX(encode_sub_immediate(W0, W0, 0x01, false, reg_size_t::SIZE_32BIT), 0x51000400);
}

TEST(instruction, add) {
  // sub sp, sp, #0x40
  EXPECT_EQ_HEX(encode_add_immediate(SP, SP, 0x40, false, reg_size_t::SIZE_64BIT), 0x910103FF);
  // sub w0, w0, #1
  EXPECT_EQ_HEX(encode_add_immediate(W1, W0, 0x0a, false, reg_size_t::SIZE_32BIT), 0x11002801);

  // add w0, w1, w0
  EXPECT_EQ_HEX(encode_add_register(W0, W1, W0, 0, reg_shift_t::SHIFT_LSL, reg_size_t::SIZE_32BIT), 0x0b000020);
  // add x0, x1, x2
  EXPECT_EQ_HEX(encode_add_register(X0, X1, X2, 0, reg_shift_t::SHIFT_LSL, reg_size_t::SIZE_64BIT), 0x8B020020);
  // add x2, x1, x0, ASR #32
  EXPECT_EQ_HEX(encode_add_register(X2, X1, X0, 32, reg_shift_t::SHIFT_ASR, reg_size_t::SIZE_64BIT), 0x8B808022);
}

TEST(instruction, mov) {
  // mov fp, sp
  EXPECT_EQ_HEX(encode_mov_sp(FP, SP, reg_size_t::SIZE_64BIT), 0x910003FD);
  // MOV SP, X1
  EXPECT_EQ_HEX(encode_mov_sp(SP, X1, reg_size_t::SIZE_64BIT), 0x9100003F);

  // MOV X0, X1
  EXPECT_EQ_HEX(encode_mov_register(X0, X1, reg_size_t::SIZE_64BIT), 0xAA0103E0);
  // MOV W5, W10
  EXPECT_EQ_HEX(encode_mov_register(W5, W10, reg_size_t::SIZE_32BIT), 0x2A0A03E5);
  // MOV X29, X30
  EXPECT_EQ_HEX(encode_mov_register(X29, X30, reg_size_t::SIZE_64BIT), 0xAA1E03FD);

  // MOV X0, 42
  EXPECT_EQ_HEX(encode_mov_immediate(X0, 42, 0, reg_size_t::SIZE_64BIT), 0xD2800540);
  // MOV W5, 1000
  EXPECT_EQ_HEX(encode_mov_immediate(W5, 1000, 0, reg_size_t::SIZE_32BIT), 0x52807D05);

  // MOVZ X3, #0x1234, LSL #16
  EXPECT_EQ_HEX(encode_mov_immediate(X3, 0x1234, 16, reg_size_t::SIZE_64BIT), 0xD2A24683);
  // MOVZ X7, 0xABCD, LSL #48
  EXPECT_EQ_HEX(encode_mov_immediate(X7, 0xABCD, 48, reg_size_t::SIZE_64BIT), 0xD2F579A7);
}

TEST(instruction, ret) {
  // ret
  EXPECT_EQ_HEX(encode_ret(), 0xD65F03C0);
  EXPECT_EQ_HEX(encode_ret(X8), 0xD65F0100);
}