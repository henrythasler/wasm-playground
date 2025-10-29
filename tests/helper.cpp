#include "helper.hpp"

namespace helper {
tiny::WasmModule loadModule(std::string filename) {
  tiny::Loader loader = tiny::Loader();
  auto path = std::filesystem::path(__FILE__).parent_path() / "assets";
  auto loadSuccess = loader.loadFromFile(path / filename);
  std::vector<uint8_t> bytecode = loader.getBytecode();
  return tiny::WasmModule(bytecode);
}

void dump(std::string filename, std::vector<uint32_t> data) {
  auto path = std::filesystem::path(__FILE__).parent_path() / "machinecode";
  std::filesystem::create_directories(path);

  if (!path.empty()) {
    std::ofstream outFile(path / filename, std::ios::binary);
    if (outFile) {
      outFile.write(reinterpret_cast<const char *>(data.data()), data.size() * sizeof(uint32_t));

      outFile.close();
    }
  } else {
    return; // Return false if no path is provided
  }
}
} // namespace helper