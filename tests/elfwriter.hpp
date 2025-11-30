#include <cstdint>
#include <cstring>
#include <elf.h>
#include <filesystem>
#include <fstream>
#include <vector>

namespace ELFWriter {

/** mostly written by claude.ai */
class ELFWriter {
private:
  std::vector<uint8_t> code;
  std::vector<std::string> symbol_names;
  std::vector<uint64_t> symbol_offsets;
  std::vector<uint64_t> symbol_sizes;

public:
  void add_code(const uint8_t *data, size_t size);
  void add_symbol(const std::string &name, uint64_t offset, uint64_t size);
  void write_elf(std::string filename);

private:
  std::vector<uint8_t> build_section_string_table();
  std::vector<uint8_t> build_string_table();
  std::vector<Elf64_Sym> build_symbol_table(const std::vector<uint8_t> &strtab);
  void write_section_headers(std::ofstream &file, size_t text_offset, size_t text_size, size_t shstrtab_offset, size_t shstrtab_size,
                             size_t strtab_offset, size_t strtab_size, size_t symtab_offset, size_t symtab_size);
};
} // namespace