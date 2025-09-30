#include <iostream>
#include <vector>
#include <fstream>
#include <array>

namespace tiny {

class Loader {
private:
  std::string path;
  std::vector<uint8_t> bytecode = {};
  /* data */
public:
  Loader() = default;
  ~Loader() = default;

  bool loadFromFile(std::string path);
  std::vector<uint8_t> getBytecode();
};
} // namespace tiny
