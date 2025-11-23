#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>
#include "../src/modules/runtime.hpp"
#include "helper.hpp"

TEST(loop, loop_if_then) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_0 = wasmModule.getWasmFunction("as-if-then")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode_0);
    helper::dump("loop.as-if-then.bin", machinecode_0);

    EXPECT_EQ(wasmFunction_0(), 1);
}

TEST(loop, loop_if_else) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_0 = wasmModule.getWasmFunction("as-if-else")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode_0);
    helper::dump("loop.as-if-else.bin", machinecode_0);

    EXPECT_EQ(wasmFunction_0(), 2);
}

TEST(loop, loop_as_br_if_first) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_0 = wasmModule.getWasmFunction("as-br_if-first")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode_0);
    helper::dump("loop.as-br_if-first.bin", machinecode_0);

    EXPECT_EQ(wasmFunction_0(), 1);
}

TEST(loop, loop_as_br_if_last) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_0 = wasmModule.getWasmFunction("as-br_if-last")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode_0);
    helper::dump("loop.as-br_if-last.bin", machinecode_0);

    EXPECT_EQ(wasmFunction_0(), 2);
}

TEST(loop, loop_effects) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_0 = wasmModule.getWasmFunction("effects")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<wasm::wasm_i32_t>(machinecode_0);
    helper::dump("loop.effects.bin", machinecode_0);

    EXPECT_EQ(wasmFunction_0(), 1);
}

TEST(loop, loop_while) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_0 = wasmModule.getWasmFunction("while")->getMachinecode();
    auto wasmFunction_0 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_0);
    helper::dump("loop.while.bin", machinecode_0);

    EXPECT_EQ(wasmFunction_0(0LL), 1LL);
    EXPECT_EQ(wasmFunction_0(1LL), 1LL);
    EXPECT_EQ(wasmFunction_0(2LL), 2LL);
    EXPECT_EQ(wasmFunction_0(3LL), 6LL);
    EXPECT_EQ(wasmFunction_0(5LL), 120LL);
    EXPECT_EQ(wasmFunction_0(20LL), 2432902008176640000LL);
}

TEST(loop, loop_for) {
    auto wasmModule = helper::loadModule("loop.0.wasm");
    auto machinecode_6 = wasmModule.getWasmFunction("for")->getMachinecode();
    auto wasmFunction_6 = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode_6);
    helper::dump("loop.for.bin", machinecode_6);

    EXPECT_EQ(wasmFunction_6(0LL), 1LL);
    EXPECT_EQ(wasmFunction_6(1LL), 1LL);
    EXPECT_EQ(wasmFunction_6(2LL), 2LL);
    EXPECT_EQ(wasmFunction_6(3LL), 6LL);
    EXPECT_EQ(wasmFunction_6(5LL), 120LL);
    EXPECT_EQ(wasmFunction_6(20LL), 2432902008176640000LL);
}
