#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>
#include "../src/modules/runtime.hpp"
#include "helper.hpp"

TEST(SpecTest, module_0) {
    auto wasmModule = helper::loadModule("module_0");

    auto machinecode_0 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_0);
    EXPECT_THROW(wasmFunction_0(1, 0), std::runtime_error);  // integer divide by zero

    auto machinecode_1 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_1 = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_1);
    EXPECT_THROW(wasmFunction_1(0, 0), std::runtime_error);  // integer divide by zero

    auto machinecode_2 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_2 = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_2);
    EXPECT_THROW(wasmFunction_2(0x80000000, -1), std::runtime_error);  // integer overflow

    auto machinecode_3 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_3 = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_3);
    EXPECT_THROW(wasmFunction_3(0x80000000, 0), std::runtime_error);  // integer divide by zero

    auto machinecode_4 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_4 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_4);
    EXPECT_EQ(wasmFunction_4(1, 1), 1);

    auto machinecode_5 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_5 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_5);
    EXPECT_EQ(wasmFunction_5(0, 1), 1);

    auto machinecode_6 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_6 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_6);
    EXPECT_EQ(wasmFunction_6(0, -1), -1);

    auto machinecode_7 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_7 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_7);
    EXPECT_EQ(wasmFunction_7(-1, -1), -1);

    auto machinecode_8 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_8 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_8);
    EXPECT_EQ(wasmFunction_8(0x80000000, 2), 2);

    auto machinecode_9 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_9 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_9);
    EXPECT_EQ(wasmFunction_9(0x80000001, 1000), 1000);

    auto machinecode_10 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_10 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_10);
    EXPECT_EQ(wasmFunction_10(5, 2), 2);

    auto machinecode_11 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_11 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_11);
    EXPECT_EQ(wasmFunction_11(-5, 2), 2);

    auto machinecode_12 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_12 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_12);
    EXPECT_EQ(wasmFunction_12(5, -2), -2);

    auto machinecode_13 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_13 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_13);
    EXPECT_EQ(wasmFunction_13(-5, -2), -2);

    auto machinecode_14 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_14 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_14);
    EXPECT_EQ(wasmFunction_14(7, 3), 3);

    auto machinecode_15 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_15 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_15);
    EXPECT_EQ(wasmFunction_15(-7, 3), 3);

    auto machinecode_16 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_16 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_16);
    EXPECT_EQ(wasmFunction_16(7, -3), -3);

    auto machinecode_17 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_17 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_17);
    EXPECT_EQ(wasmFunction_17(-7, -3), -3);

    auto machinecode_18 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_18 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_18);
    EXPECT_EQ(wasmFunction_18(11, 5), 5);

    auto machinecode_19 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_19 = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_19);
    EXPECT_EQ(wasmFunction_19(17, 7), 7);

    auto machinecode_20 = wasmModule.getWasmFunction("div_u")->getMachinecode();
    auto wasmFunction_20 = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_20);
    EXPECT_THROW(wasmFunction_20(1, 0), std::runtime_error);  // integer divide by zero

    auto machinecode_21 = wasmModule.getWasmFunction("div_u")->getMachinecode();
    auto wasmFunction_21 = tiny::make_wasm_function<void, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode_21);
    EXPECT_THROW(wasmFunction_21(0, 0), std::runtime_error);  // integer divide by zero

}

TEST(SpecTest, module_1) {
    auto wasmModule = helper::loadModule("module_1");

    auto machinecode_0 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_0);
    EXPECT_THROW(wasmFunction_0(1LL, 0LL), std::runtime_error);  // integer divide by zero

    auto machinecode_1 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_1 = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_1);
    EXPECT_THROW(wasmFunction_1(0LL, 0LL), std::runtime_error);  // integer divide by zero

    auto machinecode_2 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_2 = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_2);
    EXPECT_THROW(wasmFunction_2(0x8000000000000000LL, -1LL), std::runtime_error);  // integer overflow

    auto machinecode_3 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_3 = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_3);
    EXPECT_THROW(wasmFunction_3(0x8000000000000000LL, 0LL), std::runtime_error);  // integer divide by zero

    auto machinecode_4 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_4 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_4);
    EXPECT_EQ(wasmFunction_4(1LL, 1LL), 1LL);

    auto machinecode_5 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_5 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_5);
    EXPECT_EQ(wasmFunction_5(0LL, 1LL), 1LL);

    auto machinecode_6 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_6 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_6);
    EXPECT_EQ(wasmFunction_6(0LL, -1LL), -1LL);

    auto machinecode_7 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_7 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_7);
    EXPECT_EQ(wasmFunction_7(-1LL, -1LL), -1LL);

    auto machinecode_8 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_8 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_8);
    EXPECT_EQ(wasmFunction_8(0x8000000000000000LL, 2LL), 2LL);

    auto machinecode_9 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_9 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_9);
    EXPECT_EQ(wasmFunction_9(0x8000000000000001LL, 1000LL), 1000LL);

    auto machinecode_10 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_10 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_10);
    EXPECT_EQ(wasmFunction_10(5LL, 2LL), 2LL);

    auto machinecode_11 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_11 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_11);
    EXPECT_EQ(wasmFunction_11(-5LL, 2LL), 2LL);

    auto machinecode_12 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_12 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_12);
    EXPECT_EQ(wasmFunction_12(5LL, -2LL), -2LL);

    auto machinecode_13 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_13 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_13);
    EXPECT_EQ(wasmFunction_13(-5LL, -2LL), -2LL);

    auto machinecode_14 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_14 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_14);
    EXPECT_EQ(wasmFunction_14(7LL, 3LL), 3LL);

    auto machinecode_15 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_15 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_15);
    EXPECT_EQ(wasmFunction_15(-7LL, 3LL), 3LL);

    auto machinecode_16 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_16 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_16);
    EXPECT_EQ(wasmFunction_16(7LL, -3LL), -3LL);

    auto machinecode_17 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_17 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_17);
    EXPECT_EQ(wasmFunction_17(-7LL, -3LL), -3LL);

    auto machinecode_18 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_18 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_18);
    EXPECT_EQ(wasmFunction_18(11LL, 5LL), 5LL);

    auto machinecode_19 = wasmModule.getWasmFunction("div_s")->getMachinecode();
    auto wasmFunction_19 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_19);
    EXPECT_EQ(wasmFunction_19(17LL, 7LL), 7LL);

    auto machinecode_20 = wasmModule.getWasmFunction("div_u")->getMachinecode();
    auto wasmFunction_20 = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_20);
    EXPECT_THROW(wasmFunction_20(1LL, 0LL), std::runtime_error);  // integer divide by zero

    auto machinecode_21 = wasmModule.getWasmFunction("div_u")->getMachinecode();
    auto wasmFunction_21 = tiny::make_wasm_function<void, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_21);
    EXPECT_THROW(wasmFunction_21(0LL, 0LL), std::runtime_error);  // integer divide by zero

}

