#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "elfwriter.hpp"
#include "helper.hpp"

namespace {

void writer_test() {
    ELFWriter::ELFWriter writer;
    
    // Example ARM64 code with LDR literal instruction
    // This LDR will reference the literal pool in .rodata
    uint32_t code[] = {
        0x58000040,  // ldr x0, #8  (load from PC + 8, which is the literal pool)
        0xd65f03c0   // ret
    };
    
    writer.add_code(reinterpret_cast<uint8_t*>(code), sizeof(code));
    writer.add_symbol("my_function", 0, sizeof(code), 1);  // section 1 = .text
    
    // Add literal pool to .rodata
    // The LDR above will read this value
    uint64_t literals[] = {
        0x123456789ABCDEF0ULL
    };
    
    writer.add_rodata(reinterpret_cast<uint8_t*>(literals), sizeof(literals));
    writer.add_symbol("literal_pool", 0, sizeof(literals), 3);  // section 3 = .rodata
    
    // Add another function
    uint32_t code2[] = {
        0x52800be0,  // mov w0, #95
        0xd65f03c0   // ret
    };
    
    writer.add_code(reinterpret_cast<uint8_t*>(code2), sizeof(code2));
    writer.add_symbol("another_function", sizeof(code), sizeof(code2), 1);
    
    // Add regular data section
    uint64_t data_values[] = {
        0x1122334455667788,
        0xaabbccddeeff0011
    };
    
    writer.add_data(reinterpret_cast<uint8_t*>(data_values), sizeof(data_values));
    writer.add_symbol("my_data_array", 0, sizeof(data_values), 2);  // section 2 = .data
    
    writer.write_elf("jit_output.o");
}

TEST(objdump, wasm) {
  std::vector<std::string> wasmFiles = {"abs",     "arithmetic.0",   "arithmetic.1", "bit",    "block-extended",    "block.0",   "branch",
                                        "compare", "conditionals.0", "division",     "echo",   "empty-fn",          "functions", "local.0",
                                        "local.1", "local.2",        "loop.0",       "call.0", "functions_indirect"};

  for (const auto &wasmFile : wasmFiles) {
    auto wasmModule = helper::loadModule(wasmFile + ".wasm");
    std::vector<uint32_t> machinecode = wasmModule.getMachinecode();

    ELFWriter::ELFWriter writer;
    writer.add_code(reinterpret_cast<const uint8_t *>(machinecode.data()), machinecode.size() * sizeof(uint32_t));

    for (auto builtin : wasmModule.getBuiltins()) {
      writer.add_symbol(builtin->name, builtin->machinecodeOffset, builtin->machinecodeSize * sizeof(uint32_t));
    }

    int functionIndex = 0;
    for (auto function : wasmModule.getWasmFunctions()) {
      auto name = function->getName().empty() ? "func_" + std::to_string(functionIndex) : function->getName();
      writer.add_symbol(name, function->getMachinecodeOffset() * sizeof(uint32_t), function->getMachinecodeSize() * sizeof(uint32_t));
      functionIndex++;
    }

    // used for inline literal pools
    // int tableIndex = 0;
    // for (auto table : wasmModule.getTables()) {
    //   auto name = table->name.empty() ? "table_" + std::to_string(tableIndex) : table->name;
    //   writer.add_symbol(name, machinecode.size() * sizeof(uint32_t) - wasmModule.getDataSection().size() * sizeof(uint8_t) + table->offset * sizeof(uint8_t), table->size * sizeof(uint8_t), 3);
    //   tableIndex++;
    // }    

    writer.add_rodata(reinterpret_cast<const uint8_t *>(wasmModule.getDataSection().data()), wasmModule.getDataSection().size() * sizeof(uint8_t));
    int tableIndex = 0;
    for (auto table : wasmModule.getTables()) {
      auto name = table->name.empty() ? "table_" + std::to_string(tableIndex) : table->name;
      writer.add_symbol(name, table->offset * sizeof(uint8_t), table->size * sizeof(uint8_t), 3);
      tableIndex++;
    }

    writer.write_elf(wasmFile + ".o");
  }
  // writer_test();
}

} // namespace