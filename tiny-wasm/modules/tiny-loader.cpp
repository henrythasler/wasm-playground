#include "tiny-loader.hpp"

namespace tiny {
Loader::Loader(std::string path) {
}

Loader::~Loader() {
}

std::vector<uint8_t> Loader::getBytecode() {
  return std::vector<uint8_t>(nop_fn, nop_fn + sizeof(nop_fn));
}
} // namespace tiny
