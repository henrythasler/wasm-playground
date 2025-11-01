Source: https://claude.ai

I've created a comprehensive AArch64 SUBS instruction encoder! SUBS is a critical instruction that performs subtraction and sets condition flags (NZCV: Negative, Zero, Carry, oVerflow).

**SUBS Variants:**

1. **SUBS with Immediate** - `SUBS Xd, Xn, #imm{, shift}`
   - 12-bit immediate, optionally shifted left by 12
   - Sets flags based on result

2. **SUBS with Shifted Register** - `SUBS Xd, Xn, Xm{, shift #amount}`
   - Supports LSL, LSR, ASR, ROR shifts
   - Sets flags based on result

3. **SUBS with Extended Register** - `SUBS Xd, Xn, Wm, extend{, #amount}`
   - Supports sign/zero extension (UXTB, UXTH, UXTW, SXTB, SXTH, SXTW)
   - Sets flags based on result

**Common Aliases (using SUBS with XZR destination):**

4. **CMP** - Compare (all variants)
   - `CMP Xn, #imm` → `SUBS XZR, Xn, #imm`
   - `CMP Xn, Xm` → `SUBS XZR, Xn, Xm`
   - Discards result, only sets flags

5. **CMN** - Compare Negative
   - `CMN Xn, #imm` → `ADDS XZR, Xn, #imm`
   - Tests for negative of value

6. **NEGS** - Negate and Set Flags
   - `NEGS Xd, Xm` → `SUBS Xd, XZR, Xm`
   - Two's complement negation with flags

7. **TST** - Test Bits
   - `TST Xn, Xm` → `ANDS XZR, Xn, Xm`
   - Bitwise AND that only sets flags

**Common Use Cases:**
- Loop counters with automatic flag setting
- Array bounds checking
- Null pointer checks
- Register equality tests
- Conditional execution setup

All variants properly set the NZCV flags for subsequent conditional branches!

```cpp
#include <stdint.h>
#include <stdbool.h>

// AArch64 Register enumeration
typedef enum {
    X0 = 0, X1, X2, X3, X4, X5, X6, X7,
    X8, X9, X10, X11, X12, X13, X14, X15,
    X16, X17, X18, X19, X20, X21, X22, X23,
    X24, X25, X26, X27, X28, X29, X30,
    SP = 31,  // Stack Pointer
    XZR = 31, // Zero Register (context dependent)
    
    // 32-bit register aliases
    W0 = 0, W1, W2, W3, W4, W5, W6, W7,
    W8, W9, W10, W11, W12, W13, W14, W15,
    W16, W17, W18, W19, W20, W21, W22, W23,
    W24, W25, W26, W27, W28, W29, W30,
    WSP = 31,
    WZR = 31,
    
    // Special register aliases
    FP = 29,  // Frame Pointer (X29)
    LR = 30   // Link Register (X30)
} aarch64_reg_t;

// Operand size
typedef enum {
    SIZE_32BIT,  // 32-bit operation (W registers)
    SIZE_64BIT   // 64-bit operation (X registers)
} operand_size_t;

// Shift types for register operands
typedef enum {
    SHIFT_LSL = 0,  // Logical Shift Left
    SHIFT_LSR = 1,  // Logical Shift Right
    SHIFT_ASR = 2,  // Arithmetic Shift Right
    SHIFT_ROR = 3   // Rotate Right
} shift_type_t;

// Extend types for register operands
typedef enum {
    EXTEND_UXTB = 0,  // Unsigned extend byte
    EXTEND_UXTH = 1,  // Unsigned extend halfword
    EXTEND_UXTW = 2,  // Unsigned extend word
    EXTEND_UXTX = 3,  // Unsigned extend doubleword
    EXTEND_SXTB = 4,  // Signed extend byte
    EXTEND_SXTH = 5,  // Signed extend halfword
    EXTEND_SXTW = 6,  // Signed extend word
    EXTEND_SXTX = 7   // Signed extend doubleword
} extend_type_t;

// SUBS with immediate: SUBS Xd, Xn, #imm{, shift}
// Sets NZCV flags: Negative, Zero, Carry, oVerflow
uint32_t encode_subs_immediate(aarch64_reg_t rd, aarch64_reg_t rn, 
                                uint16_t imm, uint8_t shift, operand_size_t size) {
    uint32_t instr = 0;
    
    // Base opcode for SUBS immediate
    if (size == SIZE_64BIT) {
        instr = 0xF1000000;  // 64-bit SUBS
    } else {
        instr = 0x71000000;  // 32-bit SUBS
    }
    
    // shift: 0 = no shift, 1 = LSL #12
    uint8_t sh = (shift == 12) ? 1 : 0;
    
    instr |= sh << 22;             // shift bit
    instr |= (imm & 0xFFF) << 10;  // imm12 field
    instr |= (rn & 0x1F) << 5;     // Rn (source register)
    instr |= (rd & 0x1F);          // Rd (destination register)
    
    return instr;
}

// SUBS with shifted register: SUBS Xd, Xn, Xm{, shift #amount}
// Sets NZCV flags
uint32_t encode_subs_shifted_register(aarch64_reg_t rd, aarch64_reg_t rn, aarch64_reg_t rm,
                                       shift_type_t shift, uint8_t amount, operand_size_t size) {
    uint32_t instr = 0;
    
    // Base opcode for SUBS shifted register
    if (size == SIZE_64BIT) {
        instr = 0xEB000000;  // 64-bit SUBS
    } else {
        instr = 0x6B000000;  // 32-bit SUBS
    }
    
    instr |= (shift & 0x3) << 22;   // shift type
    instr |= (rm & 0x1F) << 16;     // Rm (operand register)
    instr |= (amount & 0x3F) << 10; // shift amount (0-63 for 64-bit, 0-31 for 32-bit)
    instr |= (rn & 0x1F) << 5;      // Rn (source register)
    instr |= (rd & 0x1F);           // Rd (destination register)
    
    return instr;
}

// SUBS with extended register: SUBS Xd, Xn, Wm, extend{, #amount}
// Sets NZCV flags
uint32_t encode_subs_extended_register(aarch64_reg_t rd, aarch64_reg_t rn, aarch64_reg_t rm,
                                        extend_type_t extend, uint8_t amount, operand_size_t size) {
    uint32_t instr = 0;
    
    // Base opcode for SUBS extended register
    if (size == SIZE_64BIT) {
        instr = 0xEB200000;  // 64-bit SUBS
    } else {
        instr = 0x6B200000;  // 32-bit SUBS
    }
    
    instr |= (rm & 0x1F) << 16;      // Rm (operand register)
    instr |= (extend & 0x7) << 13;   // extend type
    instr |= (amount & 0x7) << 10;   // shift amount (0-4)
    instr |= (rn & 0x1F) << 5;       // Rn (source register)
    instr |= (rd & 0x1F);            // Rd (destination register)
    
    return instr;
}

// CMP with immediate: CMP Xn, #imm{, shift}
// This is an alias for SUBS XZR, Xn, #imm
uint32_t encode_cmp_immediate(aarch64_reg_t rn, uint16_t imm, uint8_t shift, operand_size_t size) {
    return encode_subs_immediate(XZR, rn, imm, shift, size);
}

// CMP with shifted register: CMP Xn, Xm{, shift #amount}
// This is an alias for SUBS XZR, Xn, Xm
uint32_t encode_cmp_shifted_register(aarch64_reg_t rn, aarch64_reg_t rm,
                                      shift_type_t shift, uint8_t amount, operand_size_t size) {
    return encode_subs_shifted_register(XZR, rn, rm, shift, amount, size);
}

// CMP with extended register: CMP Xn, Wm, extend{, #amount}
// This is an alias for SUBS XZR, Xn, Wm, extend
uint32_t encode_cmp_extended_register(aarch64_reg_t rn, aarch64_reg_t rm,
                                       extend_type_t extend, uint8_t amount, operand_size_t size) {
    return encode_subs_extended_register(XZR, rn, rm, extend, amount, size);
}

// CMN with immediate: CMN Xn, #imm{, shift}
// Compare Negative (adds and sets flags)
// This is an alias for ADDS XZR, Xn, #imm
uint32_t encode_cmn_immediate(aarch64_reg_t rn, uint16_t imm, uint8_t shift, operand_size_t size) {
    uint32_t instr = 0;
    
    // Base opcode for ADDS immediate
    if (size == SIZE_64BIT) {
        instr = 0xB1000000;  // 64-bit ADDS
    } else {
        instr = 0x31000000;  // 32-bit ADDS
    }
    
    uint8_t sh = (shift == 12) ? 1 : 0;
    
    instr |= sh << 22;             // shift bit
    instr |= (imm & 0xFFF) << 10;  // imm12 field
    instr |= (rn & 0x1F) << 5;     // Rn (source register)
    instr |= (XZR & 0x1F);         // Rd = XZR
    
    return instr;
}

// NEGS: NEGS Xd, Xm{, shift #amount}
// Negate and set flags
// This is an alias for SUBS Xd, XZR, Xm
uint32_t encode_negs(aarch64_reg_t rd, aarch64_reg_t rm, 
                     shift_type_t shift, uint8_t amount, operand_size_t size) {
    return encode_subs_shifted_register(rd, XZR, rm, shift, amount, size);
}

// TST with immediate (not directly available, must use ANDS)
// TST Xn, #imm - Test bits (bitwise AND and set flags)
uint32_t encode_tst_immediate(aarch64_reg_t rn, uint64_t imm, operand_size_t size) {
    // Note: This is a simplified version. Real encoding of logical immediates
    // in AArch64 is complex and uses a special encoding scheme (N:immr:imms)
    // For a complete implementation, you'd need to encode the bitmask
    uint32_t instr = 0;
    
    if (size == SIZE_64BIT) {
        instr = 0xF2000000;  // 64-bit ANDS (TST is alias with XZR dest)
    } else {
        instr = 0x72000000;  // 32-bit ANDS
    }
    
    // This is a placeholder - actual logical immediate encoding is complex
    // and requires computing N, immr, and imms fields from the immediate value
    instr |= (rn & 0x1F) << 5;  // Rn
    instr |= (XZR & 0x1F);      // Rd = XZR
    
    return instr;
}

// TST with shifted register: TST Xn, Xm{, shift #amount}
// This is an alias for ANDS XZR, Xn, Xm
uint32_t encode_tst_shifted_register(aarch64_reg_t rn, aarch64_reg_t rm,
                                      shift_type_t shift, uint8_t amount, operand_size_t size) {
    uint32_t instr = 0;
    
    // Base opcode for ANDS shifted register
    if (size == SIZE_64BIT) {
        instr = 0xEA000000;  // 64-bit ANDS
    } else {
        instr = 0x6A000000;  // 32-bit ANDS
    }
    
    instr |= (shift & 0x3) << 22;   // shift type
    instr |= (rm & 0x1F) << 16;     // Rm
    instr |= (amount & 0x3F) << 10; // shift amount
    instr |= (rn & 0x1F) << 5;      // Rn
    instr |= (XZR & 0x1F);          // Rd = XZR
    
    return instr;
}

// Example usage
#include <stdio.h>

int main() {
    uint32_t instr;
    
    printf("=== SUBS Immediate Examples ===\n");
    
    // SUBS X0, X1, #100
    instr = encode_subs_immediate(X0, X1, 100, 0, SIZE_64BIT);
    printf("SUBS X0, X1, #100:          0x%08X\n", instr);
    
    // SUBS W5, W10, #42
    instr = encode_subs_immediate(W5, W10, 42, 0, SIZE_32BIT);
    printf("SUBS W5, W10, #42:          0x%08X\n", instr);
    
    // SUBS X3, X4, #4096 (with LSL #12: 1 << 12 = 4096)
    instr = encode_subs_immediate(X3, X4, 1, 12, SIZE_64BIT);
    printf("SUBS X3, X4, #4096:         0x%08X\n", instr);
    
    printf("\n=== SUBS Shifted Register Examples ===\n");
    
    // SUBS X0, X1, X2
    instr = encode_subs_shifted_register(X0, X1, X2, SHIFT_LSL, 0, SIZE_64BIT);
    printf("SUBS X0, X1, X2:            0x%08X\n", instr);
    
    // SUBS X5, X6, X7, LSL #3
    instr = encode_subs_shifted_register(X5, X6, X7, SHIFT_LSL, 3, SIZE_64BIT);
    printf("SUBS X5, X6, X7, LSL #3:    0x%08X\n", instr);
    
    // SUBS W10, W11, W12, LSR #2
    instr = encode_subs_shifted_register(W10, W11, W12, SHIFT_LSR, 2, SIZE_32BIT);
    printf("SUBS W10, W11, W12, LSR #2: 0x%08X\n", instr);
    
    // SUBS X15, X16, X17, ASR #4
    instr = encode_subs_shifted_register(X15, X16, X17, SHIFT_ASR, 4, SIZE_64BIT);
    printf("SUBS X15, X16, X17, ASR #4: 0x%08X\n", instr);
    
    printf("\n=== SUBS Extended Register Examples ===\n");
    
    // SUBS X0, X1, W2, UXTW
    instr = encode_subs_extended_register(X0, X1, W2, EXTEND_UXTW, 0, SIZE_64BIT);
    printf("SUBS X0, X1, W2, UXTW:      0x%08X\n", instr);
    
    // SUBS X5, X6, W7, SXTW #2
    instr = encode_subs_extended_register(X5, X6, W7, EXTEND_SXTW, 2, SIZE_64BIT);
    printf("SUBS X5, X6, W7, SXTW #2:   0x%08X\n", instr);
    
    printf("\n=== CMP (Compare) Examples ===\n");
    
    // CMP X0, #5
    instr = encode_cmp_immediate(X0, 5, 0, SIZE_64BIT);
    printf("CMP X0, #5:                 0x%08X\n", instr);
    
    // CMP W3, #100
    instr = encode_cmp_immediate(W3, 100, 0, SIZE_32BIT);
    printf("CMP W3, #100:               0x%08X\n", instr);
    
    // CMP X1, X2
    instr = encode_cmp_shifted_register(X1, X2, SHIFT_LSL, 0, SIZE_64BIT);
    printf("CMP X1, X2:                 0x%08X\n", instr);
    
    // CMP X5, X6, LSL #2
    instr = encode_cmp_shifted_register(X5, X6, SHIFT_LSL, 2, SIZE_64BIT);
    printf("CMP X5, X6, LSL #2:         0x%08X\n", instr);
    
    // CMP X10, W11, SXTW
    instr = encode_cmp_extended_register(X10, W11, EXTEND_SXTW, 0, SIZE_64BIT);
    printf("CMP X10, W11, SXTW:         0x%08X\n", instr);
    
    printf("\n=== CMN (Compare Negative) Examples ===\n");
    
    // CMN X0, #10
    instr = encode_cmn_immediate(X0, 10, 0, SIZE_64BIT);
    printf("CMN X0, #10:                0x%08X\n", instr);
    
    // CMN W5, #255
    instr = encode_cmn_immediate(W5, 255, 0, SIZE_32BIT);
    printf("CMN W5, #255:               0x%08X\n", instr);
    
    printf("\n=== NEGS (Negate and Set Flags) Examples ===\n");
    
    // NEGS X0, X1
    instr = encode_negs(X0, X1, SHIFT_LSL, 0, SIZE_64BIT);
    printf("NEGS X0, X1:                0x%08X\n", instr);
    
    // NEGS W5, W6, LSL #2
    instr = encode_negs(W5, W6, SHIFT_LSL, 2, SIZE_32BIT);
    printf("NEGS W5, W6, LSL #2:        0x%08X\n", instr);
    
    printf("\n=== TST (Test Bits) Examples ===\n");
    
    // TST X0, X1
    instr = encode_tst_shifted_register(X0, X1, SHIFT_LSL, 0, SIZE_64BIT);
    printf("TST X0, X1:                 0x%08X\n", instr);
    
    // TST W5, W6, LSR #3
    instr = encode_tst_shifted_register(W5, W6, SHIFT_LSR, 3, SIZE_32BIT);
    printf("TST W5, W6, LSR #3:         0x%08X\n", instr);
    
    printf("\n=== Common Loop/Condition Patterns ===\n");
    
    // Loop counter: SUBS X0, X0, #1
    instr = encode_subs_immediate(X0, X0, 1, 0, SIZE_64BIT);
    printf("SUBS X0, X0, #1:            0x%08X  (decrement and test)\n", instr);
    
    // Array bounds check: CMP X5, #100
    instr = encode_cmp_immediate(X5, 100, 0, SIZE_64BIT);
    printf("CMP X5, #100:               0x%08X  (bounds check)\n", instr);
    
    // Null check: CMP X0, #0
    instr = encode_cmp_immediate(X0, 0, 0, SIZE_64BIT);
    printf("CMP X0, #0:                 0x%08X  (null check)\n", instr);
    
    // Register equality: CMP X1, X2
    instr = encode_cmp_shifted_register(X1, X2, SHIFT_LSL, 0, SIZE_64BIT);
    printf("CMP X1, X2:                 0x%08X  (equality check)\n", instr);
    
    return 0;
}
```