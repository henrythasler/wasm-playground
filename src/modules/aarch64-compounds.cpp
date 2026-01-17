#include "aarch64-compounds.hpp"

namespace arm64 {

/**
 * This instruction counts the number of consecutive binary zero bits, starting from the least significant bit in the source register, and places the
 * count in the destination register.
 *
 * This is a compound instruction using RBIT and CLZ.
 *
 * @param rd destination register
 * @param rm source register
 * @param size 32-bit or 64-bit variant
 * @param machinecode vector to which the emitted instructions will be appended
 */
void emit_ctz(reg_t rd, reg_t rn, reg_size_t size, std::vector<uint32_t> &machinecode) {
  machinecode.push_back(arm64::encode_rbit(rd, rn, size));
  machinecode.push_back(arm64::encode_clz(rd, rd, size));
}

void emit_mov_large_immediate(reg_t rd, uint64_t immediate, reg_size_t size, std::vector<uint32_t> &machinecode) {
  auto chunkLimit = (size == arm64::reg_size_t::SIZE_32BIT) ? 2 : 4;
  for (uint8_t i = 0; i < chunkLimit; i++) {
    uint16_t chunk = uint16_t((immediate >> (i << 4)) & 0xFFFF);
    if (i == 0) {
      machinecode.push_back(arm64::encode_mov_immediate(rd, chunk, 0, size));
    } else if (chunk != 0) {
      machinecode.push_back(arm64::encode_movk(rd, chunk, i << 4, size));
    }
  }
}

} // namespace arm64