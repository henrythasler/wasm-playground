#include "loader.hpp"

namespace tiny {

bool Loader::loadFromFile(std::string path) {
  // Load bytecode from file if path is provided
  if (!path.empty()) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
      return false;
    }
    this->bytecode = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
    file.close();
    return true; // Return true if loading was successful
  } else {
    return false; // Return false if no path is provided
  }
}

std::vector<uint8_t> Loader::getBytecode() {
  return this->bytecode;
}
} // namespace tiny
