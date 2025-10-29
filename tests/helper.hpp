#pragma once
#include <filesystem>
#include <fstream>

#include "../src/modules/module.hpp"
#include "../src/modules/loader.hpp"

namespace helper {
tiny::WasmModule loadModule(std::string filename);
void dump(std::string filename, std::vector<uint32_t> data);
} // namespace helper