#include "aarch64-instructions-branch.hpp"

namespace arm64 {

/**
 * This instruction branches unconditionally to an address in a register. This instruction provides a hint that this is a subroutine return.
 * rn defaults to X30
 * RET rn
 * @param rn register containing the return address (defaults to X30)
 * @return the encoded instruction
 */
uint32_t encode_ret(reg_t rn) {
  return 0xD65F0000 | ((rn & 0x1F) << 5);
}

/**
 * This instruction branches unconditionally to a label at a PC-relative offset.
 *
 * `B imm26`
 * @param imm26 offset from the address of this instruction, in the range +/-128MB
 * @return the encoded instruction
 */
uint32_t encode_branch(int32_t imm26) {
  return 0x14000000 | ((imm26 >> 2) & 0x3FFFFFF); // imm26 offset
}

void patch_branch(uint32_t &offset, int32_t imm26) {
  offset = 0x14000000 | ((imm26 >> 2) & 0x3FFFFFF); // imm26 offset
}

/**
 * This instruction branches with link unconditionally to a label at a PC-relative offset.
 *
 * `BL imm26`
 * @param imm26 offset from the address of this instruction, in the range +/-128MB
 * @return the encoded instruction
 */
uint32_t encode_branch_link(int32_t imm26) {
  return 0x94000000 | ((imm26 >> 2) & 0x3FFFFFF); // imm26 offset
}

void patch_branch_link(uint32_t &offset, int32_t imm26) {
  offset = 0x94000000 | ((imm26 >> 2) & 0x3FFFFFF); // imm26 offset
}

/**
 * This instruction branches unconditionally to an address in a register.
 *
 * `BR rn`
 * @param rn register containing the target address
 * @return the encoded instruction
 */
uint32_t encode_branch_register(reg_t rn) {
  return 0xD61F0000 | ((rn & 0x1F) << 5);
}

/**
 * This instruction calls a subroutine at an address in a register, setting register X30 to PC+4
 * 
 * `BLR rn`
 * @param rn register containing the target address
 * @return the encoded instruction
 */
uint32_t encode_branch_link_register(reg_t rn) {
  return 0xD63F0000 | ((rn & 0x1F) << 5);
}

/**
 * This instruction branches conditionally to a label at a PC-relative offset. This instruction provides a hint that this is not a subroutine call or
 * return.
 *
 * `B.cond imm19`
 * @param cond one of the standard conditions
 * @param imm19 offset from the address of this instruction, in the range +/-1MB
 * @return the encoded instruction
 */
uint32_t encode_branch_cond(branch_condition_t cond, int32_t imm19) {
  uint32_t instr = 0x54000000;
  instr |= ((imm19 >> 2) & 0x7FFFF) << 5; // imm19 offset
  instr |= uint32_t(cond);                // branch condition
  return instr;
}

/**
 * This instruction compares the value in a register with zero, and conditionally branches to a label at a PC-relative offset if the comparison is
 * equal. This instruction provides a hint that this is not a subroutine call or return. This instruction does not affect condition flags.
 *
 * `CBZ rt, imm19`
 * @param rt register to be tested
 * @param imm19 offset in bytes from the address of this instruction, in the range +/-1MB
 * @return the encoded instruction
 */
uint32_t encode_cbz(reg_t rt, int32_t imm19, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x34000000, 0xB4000000, "encode_cbz");
  instr |= ((imm19 >> 2) & 0x7FFFF) << 5; // imm19 offset
  instr |= (rt & 0x1F);                   // Rt (register to be tested)
  return instr;
}

void patch_cbz(uint32_t &offset, int32_t imm19) {
  offset &= 0xff00001f;                    // clear current jump offset
  offset |= ((imm19 >> 2) & 0x7FFFF) << 5; // insert new jump offset
}

/**
 * This instruction compares the value in a register with zero, and conditionally branches to a label at a PC-relative offset if the comparison is
 * not equal. This instruction provides a hint that this is not a subroutine call or return. This instruction does not affect condition flags.
 *
 * `CBNZ rt, imm19`
 * @param rt register to be tested
 * @param imm19 offset in bytes from the address of this instruction, in the range +/-1MB
 * @return the encoded instruction
 */
uint32_t encode_cbnz(reg_t rt, int32_t imm19, reg_size_t size) {
  uint32_t instr = select_instruction(size, 0x35000000, 0xB5000000, "encode_cbnz");
  instr |= ((imm19 >> 2) & 0x7FFFF) << 5; // imm19 offset
  instr |= (rt & 0x1F);                   // Rt (register to be tested)
  return instr;
}

} // namespace arm64