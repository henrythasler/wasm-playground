#include "wasm.hpp"
namespace wasm {

const TrapCategory &trap_category() {
  static TrapCategory instance;
  return instance;
}

std::error_code make_trap_error(trap_code_t code) {
  return {static_cast<int>(code), trap_category()};
}

std::string joinValTypes(const std::vector<webassembly_t::val_types_t> &valTypes) {
  std::string resultString;
  int32_t idx = 0;

  if (valTypes.size() == 0) {
    return "void";
  }

  for (auto valType : valTypes) {
    if (idx > 0) {
      resultString += ", ";
    }
    switch (valType) {
    case webassembly_t::VAL_TYPES_I32:
      resultString += "i32";
      break;
    case webassembly_t::VAL_TYPES_I64:
      resultString += "i64";
      break;
    case webassembly_t::VAL_TYPES_F32:
      resultString += "f32";
      break;
    case webassembly_t::VAL_TYPES_F64:
      resultString += "f64";
      break;
    default:
      break;
    }
    idx++;
  }
  return resultString;
}

} // namespace wasm