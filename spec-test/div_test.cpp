#include <gtest/gtest.h>
#include <cmath>
#include <limits>

// WebAssembly module interface - implement these functions
// based on your actual WASM runtime/implementation

namespace wasm {
    // Add your WASM module execution functions here
    // Example:
    // int32_t invoke_i32(const char* func_name, ...);
    // float invoke_f32(const char* func_name, ...);
    // double invoke_f64(const char* func_name, ...);
}

TEST(WasmTest, module_0) {
    EXPECT_THROW(wasm::invoke_i32("div_s", 1, 0), std::runtime_error);  // integer divide by zero

    EXPECT_THROW(wasm::invoke_i32("div_s", 0, 0), std::runtime_error);  // integer divide by zero

    EXPECT_THROW(wasm::invoke_i32("div_s", 0x80000000, -1), std::runtime_error);  // integer overflow

    EXPECT_THROW(wasm::invoke_i32("div_s", 0x80000000, 0), std::runtime_error);  // integer divide by zero

    EXPECT_EQ(wasm::invoke_i32("div_s", 1, 1), 1);

    EXPECT_EQ(wasm::invoke_i32("div_s", 0, 1), 1);

    EXPECT_EQ(wasm::invoke_i32("div_s", 0, -1), -1);

    EXPECT_EQ(wasm::invoke_i32("div_s", -1, -1), -1);

    EXPECT_EQ(wasm::invoke_i32("div_s", 0x80000000, 2), 2);

    EXPECT_EQ(wasm::invoke_i32("div_s", 0x80000001, 1000), 1000);

    EXPECT_EQ(wasm::invoke_i32("div_s", 5, 2), 2);

    EXPECT_EQ(wasm::invoke_i32("div_s", -5, 2), 2);

    EXPECT_EQ(wasm::invoke_i32("div_s", 5, -2), -2);

    EXPECT_EQ(wasm::invoke_i32("div_s", -5, -2), -2);

    EXPECT_EQ(wasm::invoke_i32("div_s", 7, 3), 3);

    EXPECT_EQ(wasm::invoke_i32("div_s", -7, 3), 3);

    EXPECT_EQ(wasm::invoke_i32("div_s", 7, -3), -3);

    EXPECT_EQ(wasm::invoke_i32("div_s", -7, -3), -3);

    EXPECT_EQ(wasm::invoke_i32("div_s", 11, 5), 5);

    EXPECT_EQ(wasm::invoke_i32("div_s", 17, 7), 7);

    EXPECT_THROW(wasm::invoke_i32("div_u", 1, 0), std::runtime_error);  // integer divide by zero

    EXPECT_THROW(wasm::invoke_i32("div_u", 0, 0), std::runtime_error);  // integer divide by zero
}

TEST(WasmTest, module_1) {
    EXPECT_THROW(wasm::invoke_i64("div_s", 1LL, 0LL), std::runtime_error);  // integer divide by zero

    EXPECT_THROW(wasm::invoke_i64("div_s", 0LL, 0LL), std::runtime_error);  // integer divide by zero

    EXPECT_THROW(wasm::invoke_i64("div_s", 0x8000000000000000LL, -1LL), std::runtime_error);  // integer overflow

    EXPECT_THROW(wasm::invoke_i64("div_s", 0x8000000000000000LL, 0LL), std::runtime_error);  // integer divide by zero

    EXPECT_EQ(wasm::invoke_i64("div_s", 1LL, 1LL), 1LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 0LL, 1LL), 1LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 0LL, -1LL), -1LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", -1LL, -1LL), -1LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 0x8000000000000000LL, 2LL), 2LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 0x8000000000000001LL, 1000LL), 1000LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 5LL, 2LL), 2LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", -5LL, 2LL), 2LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 5LL, -2LL), -2LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", -5LL, -2LL), -2LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 7LL, 3LL), 3LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", -7LL, 3LL), 3LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 7LL, -3LL), -3LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", -7LL, -3LL), -3LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 11LL, 5LL), 5LL);

    EXPECT_EQ(wasm::invoke_i64("div_s", 17LL, 7LL), 7LL);

    EXPECT_THROW(wasm::invoke_i64("div_u", 1LL, 0LL), std::runtime_error);  // integer divide by zero

    EXPECT_THROW(wasm::invoke_i64("div_u", 0LL, 0LL), std::runtime_error);  // integer divide by zero
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
