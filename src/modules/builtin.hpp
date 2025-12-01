#pragma once

#include <cstdint>
#include <vector>

#include "assembler.hpp"

namespace tiny {

class Builtin {
private:
public:
  size_t machinecodeOffset = 0;
  size_t machinecodeSize = 0;
  std::string name;

  Builtin() = default;
  ~Builtin() = default;
};
} // namespace tiny