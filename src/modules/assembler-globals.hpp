#include <iomanip>

#include "helper.hpp"
#include "leb128.hpp"
#include "wasm.hpp"
#include "webassembly.h"

namespace assembler {

struct GlobalVariable {
  bool isMutable;
  webassembly_t::val_types_t valType;
  uint64_t value;
};

class Globals {
private:
public:
  std::vector<GlobalVariable> entries;

  Globals() = default;
  ~Globals() = default;

  std::vector<uint32_t> serialize();
};

void parseGlobalsSection(Globals &globals, webassembly_t::global_section_t &global_section);
uint64_t parseInitExpr(std::vector<uint8_t> &initExpr);

} // namespace assembler