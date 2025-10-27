#include <gtest/gtest.h>
#include <gmock/gmock.h>  // This is the key include for EXPECT_THAT

#include "../src/modules/leb128.hpp"

TEST(leb128, unsigned) {
    std::string data = std::string("\xE5\x8E\x26", 3);
    std::istringstream stream(data);
    EXPECT_EQ(LEB128Decoder::decodeUnsigned(stream), 624485);
}

TEST(leb128, signed) {
    std::string data = std::string("\xC0\xBB\x78", 3);
    std::istringstream stream(data);
    EXPECT_EQ(LEB128Decoder::decodeSigned(stream), -123456);
}

TEST(leb128, multiple) {
    std::string data = std::string("\x7F\xE5\x8E\x26\x0c7\x9f\x7f", 7);
    std::istringstream stream(data);
    EXPECT_EQ(LEB128Decoder::decodeSigned(stream), -1);
    EXPECT_EQ(LEB128Decoder::decodeUnsigned(stream), 624485);
    EXPECT_EQ(LEB128Decoder::decodeSigned(stream), -12345);
}