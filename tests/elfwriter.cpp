#include "elfwriter.hpp"

namespace ELFWriter {

void ELFWriter::add_code(const uint8_t *data, size_t size) {
  code.insert(code.end(), data, data + size);
}

void ELFWriter::add_symbol(const std::string &name, uint64_t offset, uint64_t size) {
  symbol_names.push_back(name);
  symbol_offsets.push_back(offset);
  symbol_sizes.push_back(size);
}

void ELFWriter::write_elf(std::string filename) {
  auto path = std::filesystem::path(__FILE__).parent_path() / "machinecode";
  std::filesystem::create_directories(path);

  if (path.empty()) {
    return;
  }

  // ELF Header
  Elf64_Ehdr ehdr = {};
  ehdr.e_ident[EI_MAG0] = ELFMAG0;
  ehdr.e_ident[EI_MAG1] = ELFMAG1;
  ehdr.e_ident[EI_MAG2] = ELFMAG2;
  ehdr.e_ident[EI_MAG3] = ELFMAG3;
  ehdr.e_ident[EI_CLASS] = ELFCLASS64;
  ehdr.e_ident[EI_DATA] = ELFDATA2LSB;
  ehdr.e_ident[EI_VERSION] = EV_CURRENT;
  ehdr.e_ident[EI_OSABI] = ELFOSABI_NONE;
  ehdr.e_type = ET_REL; // Relocatable file
  ehdr.e_machine = EM_AARCH64;
  ehdr.e_version = EV_CURRENT;
  ehdr.e_ehsize = sizeof(Elf64_Ehdr);
  ehdr.e_shentsize = sizeof(Elf64_Shdr);

  // Calculate offsets
  size_t text_offset = sizeof(Elf64_Ehdr);
  size_t text_size = code.size();

  // Build string tables
  std::vector<uint8_t> shstrtab = build_section_string_table();
  std::vector<uint8_t> strtab = build_string_table();
  std::vector<Elf64_Sym> symtab = build_symbol_table(strtab);

  size_t shstrtab_offset = text_offset + text_size;
  size_t strtab_offset = shstrtab_offset + shstrtab.size();
  size_t symtab_offset = strtab_offset + strtab.size();
  size_t shdr_offset = symtab_offset + symtab.size() * sizeof(Elf64_Sym);

  ehdr.e_shoff = shdr_offset;
  ehdr.e_shnum = 5;    // NULL, .text, .shstrtab, .strtab, .symtab
  ehdr.e_shstrndx = 2; // .shstrtab section index

  std::ofstream file(path / filename, std::ios::binary);
  if (file) {
    // Write ELF header
    file.write(reinterpret_cast<char *>(&ehdr), sizeof(ehdr));

    // Write .text section
    file.write(reinterpret_cast<const char *>(code.data()), code.size());

    // Write .shstrtab
    file.write(reinterpret_cast<const char *>(shstrtab.data()), shstrtab.size());

    // Write .strtab
    file.write(reinterpret_cast<const char *>(strtab.data()), strtab.size());

    // Write .symtab
    file.write(reinterpret_cast<const char *>(symtab.data()), symtab.size() * sizeof(Elf64_Sym));

    // Write section headers
    write_section_headers(file, text_offset, text_size, shstrtab_offset, shstrtab.size(), strtab_offset, strtab.size(), symtab_offset,
                          symtab.size() * sizeof(Elf64_Sym));
    file.close();
  }
}

std::vector<uint8_t> ELFWriter::build_section_string_table() {
  std::vector<uint8_t> tab;
  tab.push_back(0); // NULL string

  // Add section names
  for (const char *name : {".text", ".shstrtab", ".strtab", ".symtab"}) {
    tab.insert(tab.end(), name, name + strlen(name) + 1);
  }
  return tab;
}

std::vector<uint8_t> ELFWriter::build_string_table() {
  std::vector<uint8_t> tab;
  tab.push_back(0); // NULL string

  for (const auto &name : symbol_names) {
    tab.insert(tab.end(), name.begin(), name.end());
    tab.push_back(0);
  }
  return tab;
}

std::vector<Elf64_Sym> ELFWriter::build_symbol_table(const std::vector<uint8_t> &strtab) {
  std::vector<Elf64_Sym> symtab;

  // NULL symbol
  Elf64_Sym null_sym = {};
  symtab.push_back(null_sym);

  // Add function symbols
  size_t str_offset = 1; // Skip NULL string
  for (size_t i = 0; i < symbol_names.size(); i++) {
    Elf64_Sym sym = {};
    sym.st_name = str_offset;
    sym.st_info = ELF64_ST_INFO(STB_GLOBAL, STT_FUNC);
    sym.st_shndx = 1; // .text section
    sym.st_value = symbol_offsets[i];
    sym.st_size = symbol_sizes[i];
    symtab.push_back(sym);

    str_offset += symbol_names[i].length() + 1;
  }

  return symtab;
}

void ELFWriter::write_section_headers(std::ofstream &file, size_t text_offset, size_t text_size, size_t shstrtab_offset, size_t shstrtab_size,
                                      size_t strtab_offset, size_t strtab_size, size_t symtab_offset, size_t symtab_size) {
  // NULL section header
  Elf64_Shdr shdr = {};
  file.write(reinterpret_cast<char *>(&shdr), sizeof(shdr));

  // .text section
  shdr = {};
  shdr.sh_name = 1; // ".text" in .shstrtab
  shdr.sh_type = SHT_PROGBITS;
  shdr.sh_flags = SHF_ALLOC | SHF_EXECINSTR;
  shdr.sh_offset = text_offset;
  shdr.sh_size = text_size;
  shdr.sh_addralign = 4;
  file.write(reinterpret_cast<char *>(&shdr), sizeof(shdr));

  // .shstrtab section
  shdr = {};
  shdr.sh_name = 7; // ".shstrtab" in .shstrtab
  shdr.sh_type = SHT_STRTAB;
  shdr.sh_offset = shstrtab_offset;
  shdr.sh_size = shstrtab_size;
  shdr.sh_addralign = 1;
  file.write(reinterpret_cast<char *>(&shdr), sizeof(shdr));

  // .strtab section
  shdr = {};
  shdr.sh_name = 17; // ".strtab" in .shstrtab
  shdr.sh_type = SHT_STRTAB;
  shdr.sh_offset = strtab_offset;
  shdr.sh_size = strtab_size;
  shdr.sh_addralign = 1;
  file.write(reinterpret_cast<char *>(&shdr), sizeof(shdr));

  // .symtab section
  shdr = {};
  shdr.sh_name = 25; // ".symtab" in .shstrtab
  shdr.sh_type = SHT_SYMTAB;
  shdr.sh_offset = symtab_offset;
  shdr.sh_size = symtab_size;
  shdr.sh_link = 3; // Link to .strtab
  shdr.sh_info = 1; // One local symbol (NULL)
  shdr.sh_addralign = 8;
  shdr.sh_entsize = sizeof(Elf64_Sym);
  file.write(reinterpret_cast<char *>(&shdr), sizeof(shdr));
}
} // namespace