#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>
#include "../src/modules/runtime.hpp"
#include "helper.hpp"

TEST(loop, loop_if_then) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-if-then"));

    EXPECT_EQ(wasmFunction(), 1);
}

TEST(loop, loop_if_else) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-if-else"));

    EXPECT_EQ(wasmFunction(), 2);
}

TEST(loop, loop_as_br_if_first) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-br_if-first"));

    EXPECT_EQ(wasmFunction(), 1);
}

TEST(loop, loop_as_br_if_last) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("as-br_if-last"));

    EXPECT_EQ(wasmFunction(), 2);
}

TEST(loop, loop_effects) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode, wasmModule.getFunctionOffset("effects"));

    EXPECT_EQ(wasmFunction(), 1);
}

TEST(loop, loop_while) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("while"));

    EXPECT_EQ(wasmFunction(0LL), 1LL);
    EXPECT_EQ(wasmFunction(1LL), 1LL);
    EXPECT_EQ(wasmFunction(2LL), 2LL);
    EXPECT_EQ(wasmFunction(3LL), 6LL);
    EXPECT_EQ(wasmFunction(5LL), 120LL);
    EXPECT_EQ(wasmFunction(20LL), 2432902008176640000LL);
}

TEST(loop, loop_for) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode = wasmModule.getMachinecode();
    auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode, wasmModule.getFunctionOffset("for"));

    EXPECT_EQ(wasmFunction(0LL), 1LL);
    EXPECT_EQ(wasmFunction(1LL), 1LL);
    EXPECT_EQ(wasmFunction(2LL), 2LL);
    EXPECT_EQ(wasmFunction(3LL), 6LL);
    EXPECT_EQ(wasmFunction(5LL), 120LL);
    EXPECT_EQ(wasmFunction(20LL), 2432902008176640000LL);
}
