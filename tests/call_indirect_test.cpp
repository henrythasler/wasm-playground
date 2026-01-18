#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(call_indirect, callt1) {
  auto wasmModule = helper::loadModule("call_indirect.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "callt");

  EXPECT_EQ(wasmFunction(0), 1);
  EXPECT_EQ(wasmFunction(1), 2);
  EXPECT_EQ(wasmFunction(2), 3);
  // EXPECT_EQ(wasmFunction(3), 4);
  // EXPECT_EQ(wasmFunction(4), 5);
  EXPECT_EQ(wasmFunction(5), 1);
  EXPECT_EQ(wasmFunction(6), 3);

  EXPECT_THROW(
      {
        try {
          wasmFunction(7);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::TableOutOfBounds);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);
  EXPECT_THROW(
      {
        try {
          wasmFunction(100);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::TableOutOfBounds);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);
  EXPECT_THROW(
      {
        try {
          wasmFunction(-1);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::TableOutOfBounds);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);
}

TEST(call_indirect, callu1) {
  auto wasmModule = helper::loadModule("call_indirect.0.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "callu");

  // EXPECT_EQ(wasmFunction(0), 1);
  // EXPECT_EQ(wasmFunction(1), 2);
  // EXPECT_EQ(wasmFunction(2), 3);
  EXPECT_EQ(wasmFunction(3), 4);
  EXPECT_EQ(wasmFunction(4), 5);
  // EXPECT_EQ(wasmFunction(5), 1);
  // EXPECT_EQ(wasmFunction(6), 3);

  EXPECT_THROW(
      {
        try {
          wasmFunction(7);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::TableOutOfBounds);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);
  EXPECT_THROW(
      {
        try {
          wasmFunction(100);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::TableOutOfBounds);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);
  EXPECT_THROW(
      {
        try {
          wasmFunction(-1);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::TableOutOfBounds);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);  
}

TEST(call_indirect, callt2) {
  auto wasmModule = helper::loadModule("call_indirect.1.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "callt");

  EXPECT_EQ(wasmFunction(0), 1);
  EXPECT_EQ(wasmFunction(1), 2);
}

TEST(call_indirect, call_indirect) {
  auto wasmModule = helper::loadModule("call_indirect.2.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "call_indirect");

  EXPECT_EQ(wasmFunction(0, 10), 11);
  // EXPECT_THROW(
  //     {
  //       try {
  //         wasmFunction(1, 10);
  //       } catch (const std::system_error &e) {
  //         EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::BadSignature);
  //         throw; // Re-throw for EXPECT_THROW to catch
  //       }
  //     },
  //     std::system_error);  
}

} // namespace