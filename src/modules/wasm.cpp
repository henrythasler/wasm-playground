#include "wasm.hpp"
namespace wasm {
std::string trapCodeToString(trap_code_t code) {
  switch (code) {
  case trap_code_t::None:
    return "No trap";
  case trap_code_t::UnreachableCodeReached:
    return "Unreachable code reached";
  case trap_code_t::MemoryOutOfBounds:
    return "Memory out of bounds";
  case trap_code_t::TableOutOfBounds:
    return "Table out of bounds";
  case trap_code_t::IndirectCallToNull:
    return "Indirect call to null";
  case trap_code_t::IntegerDivisionByZero:
    return "Integer division by zero";
  case trap_code_t::IntegerOverflow:
    return "Integer overflow";
  case trap_code_t::BadConversionToInteger:
    return "Bad conversion to integer";
  case trap_code_t::StackOverflow:
    return "Stack overflow";
  case trap_code_t::BadSignature:
    return "Bad signature";
  case trap_code_t::OutOfFuel:
    return "Out of fuel";
  case trap_code_t::GrowthOperationLimited:
    return "Growth operation limited";
  default:
    return "Unknown trap code";
  };
}
} // namespace wasm