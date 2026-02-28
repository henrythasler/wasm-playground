#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(Spectest, local_0_wasm) {
  auto wasmModule = helper::loadModule("local.0.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_type_local_i32 = instance.getFunction<wasm::wasm_i32_t>("type-local-i32");
  auto wasm_type_local_i64 = instance.getFunction<wasm::wasm_i64_t>("type-local-i64");
  auto wasm_type_param_i32 = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("type-param-i32");
  auto wasm_type_param_i64 = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t>("type-param-i64");

  EXPECT_EQ(wasm_type_local_i32(), (static_cast<int32_t>(0x00ULL)));
  EXPECT_EQ(wasm_type_local_i64(), (static_cast<int64_t>(0x00ULL)));
  EXPECT_EQ(wasm_type_param_i32(static_cast<int32_t>(0x02ULL)), (static_cast<int32_t>(0x02ULL)));
  EXPECT_EQ(wasm_type_param_i64(static_cast<int64_t>(0x03ULL)), (static_cast<int64_t>(0x03ULL)));
}
TEST(Spectest, local_1_wasm) {
  auto wasmModule = helper::loadModule("local.1.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_type_local_i32 = instance.getFunction<void>("type-local-i32");
  auto wasm_type_local_i64 = instance.getFunction<void>("type-local-i64");
  auto wasm_type_param_i32 = instance.getFunction<void, wasm::wasm_i32_t>("type-param-i32");
  auto wasm_type_param_i64 = instance.getFunction<void, wasm::wasm_i64_t>("type-param-i64");
  auto wasm_type_mixed = instance.getFunction<void, wasm::wasm_i64_t, wasm::wasm_i32_t, wasm::wasm_i32_t>("type-mixed");

  wasm_type_local_i32();
  wasm_type_local_i64();
  wasm_type_param_i32(static_cast<int32_t>(0x02ULL));
  wasm_type_param_i64(static_cast<int64_t>(0x03ULL));
  wasm_type_mixed(static_cast<int64_t>(0x00ULL), static_cast<int32_t>(0x00ULL), static_cast<int32_t>(0x00ULL));
}
TEST(Spectest, local_2_wasm) {
  auto wasmModule = helper::loadModule("local.2.wasm");
  auto instance = tiny::ModuleInstance(wasmModule);
  
  auto wasm_type_local_i32 = instance.getFunction<wasm::wasm_i32_t>("type-local-i32");
  auto wasm_type_local_i64 = instance.getFunction<wasm::wasm_i64_t>("type-local-i64");
  auto wasm_type_param_i32 = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("type-param-i32");
  auto wasm_type_param_i64 = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t>("type-param-i64");
  auto wasm_as_local_set_value = instance.getFunction<void>("as-local.set-value");
  auto wasm_as_local_tee_value = instance.getFunction<wasm::wasm_i32_t, wasm::wasm_i32_t>("as-local.tee-value");

  EXPECT_EQ(wasm_type_local_i32(), (static_cast<int32_t>(0x01ULL)));
  EXPECT_EQ(wasm_type_local_i64(), (static_cast<int64_t>(0x01ULL)));
  EXPECT_EQ(wasm_type_param_i32(static_cast<int32_t>(0x02ULL)), (static_cast<int32_t>(0x0aULL)));
  EXPECT_EQ(wasm_type_param_i64(static_cast<int64_t>(0x03ULL)), (static_cast<int64_t>(0x0bULL)));
  wasm_as_local_set_value();
  EXPECT_EQ(wasm_as_local_tee_value(static_cast<int32_t>(0x00ULL)), (static_cast<int32_t>(0x01ULL)));
}
} // namespace