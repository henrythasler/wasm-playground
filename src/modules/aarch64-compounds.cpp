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
} // namespace arm64