#include <cstdint>

namespace tiny {

enum class OpCodes : uint32_t {
  RET = 0xD65F03C0,
  STP = 0xA9BE7BFD,     // 1010100110 1111100111101111111101b
};

}