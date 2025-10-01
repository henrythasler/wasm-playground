#include <iomanip>
#include <iostream>
#include <vector>

namespace tiny {

class Assembler {
public:
  Assembler() = default;
  ~Assembler() = default;
  std::vector<uint8_t> assemble(std::vector<uint8_t> bytecode);
};

} // namespace tiny
