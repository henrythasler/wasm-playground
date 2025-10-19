#include <cerrno>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <sys/mman.h>
#include <vector>

#include "colors.hpp"
#include "helper.hpp"

namespace tiny {
class Runtime {
public:
  Runtime() = default;
  ~Runtime() = default;
  void execute(const std::vector<uint8_t> &machinecode);
};
} // namespace tiny