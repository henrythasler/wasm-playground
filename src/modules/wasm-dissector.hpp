#include <iomanip>
#include <iostream>
#include <vector>

#include "webassembly.h"

class Dissector
{
private:
    /* data */
    static void dissectCodeSection(webassembly_t::code_section_t *code_section);
public:
    Dissector() = default;
    ~Dissector() = default;

    static void dissect(std::vector<uint8_t> bytecode);
};
