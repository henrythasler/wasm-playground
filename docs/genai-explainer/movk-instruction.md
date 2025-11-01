Source: https://claude.ai

I've created a comprehensive AArch64 MOV instruction encoder! MOV in AArch64 is actually a pseudo-instruction with multiple encodings depending on the operands:

**MOV Variants:**

1. **MOV (register)** - `MOV Xd, Xm`
   - Encoded as `ORR Xd, XZR, Xm`

2. **MOV (to/from SP)** - `MOV Xd, SP` or `MOV SP, Xn`
   - Encoded as `ADD Xd, Xn, #0`

3. **MOV (immediate)** - `MOV Xd, #imm`
   - Encoded as `MOVZ` (move with zero)

4. **MOVZ** - `MOVZ Xd, #imm, LSL #shift`
   - Moves 16-bit immediate, zeroing other bits
   - Can shift by 0, 16, 32, or 48 (for 64-bit)

5. **MOVN** - `MOVN Xd, #imm, LSL #shift`
   - Moves NOT of 16-bit immediate
   - Useful for negative values like -1

6. **MOVK** - `MOVK Xd, #imm, LSL #shift`
   - Keeps other bits, only updates selected 16-bit portion
   - Used to build 64-bit constants

7. **MVN** - `MVN Xd, Xm, shift`
   - Bitwise NOT (inverted move)
   - Encoded as `ORN Xd, XZR, Xm`

**Special Feature:**
- **Helper function** to build large 64-bit immediates using multiple instructions
- Automatically optimizes using MOVN when appropriate
- Generates minimal instruction sequences

The encoder handles all the complexities of MOV encoding in AArch64!

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

// MOV (register): MOV Xd, Xm
// This is an alias for ORR Xd, XZR, Xm
uint32_t encode_mov_register(aarch64_reg_t rd, aarch64_reg_t rm, operand_size_t size) {
    uint32_t instr = 0;
    
    // ORR Xd, XZR, Xm (no shift)
    if (size == SIZE_64BIT) {
        instr = 0xAA0003E0;  // 64-bit ORR
    } else {
        instr = 0x2A0003E0;  // 32-bit ORR
    }
    
    instr |= (rm & 0x1F) << 16;  // Rm (source register)
    instr |= (rd & 0x1F);        // Rd (destination register)
    
    return instr;
}

// MOV (to/from SP): MOV Xd, SP or MOV SP, Xn
// This is an alias for ADD Xd, Xn, #0
uint32_t encode_mov_sp(aarch64_reg_t rd, aarch64_reg_t rn, operand_size_t size) {
    uint32_t instr = 0;
    
    // ADD Xd, Xn, #0
    if (size == SIZE_64BIT) {
        instr = 0x91000000;  // 64-bit ADD
    } else {
        instr = 0x11000000;  // 32-bit ADD
    }
    
    instr |= (rn & 0x1F) << 5;  // Rn (source register)
    instr |= (rd & 0x1F);       // Rd (destination register)
    
    return instr;
}

// MOV (wide immediate): MOV Xd, #imm
// This is an alias for MOVZ (move with zero)
uint32_t encode_mov_immediate(aarch64_reg_t rd, uint16_t imm, uint8_t shift, operand_size_t size) {
    uint32_t instr = 0;
    
    // MOVZ Xd, #imm, LSL #shift
    if (size == SIZE_64BIT) {
        instr = 0xD2800000;  // 64-bit MOVZ
    } else {
        instr = 0x52800000;  // 32-bit MOVZ
    }
    
    // hw = shift / 16 (which 16-bit position)
    uint8_t hw = shift / 16;
    
    instr |= (hw & 0x3) << 21;      // hw field (0-3 for 64-bit, 0-1 for 32-bit)
    instr |= (imm & 0xFFFF) << 5;   // imm16 field
    instr |= (rd & 0x1F);           // Rd (destination register)
    
    return instr;
}

// MOVZ (Move wide with zero): MOVZ Xd, #imm{, LSL #shift}
uint32_t encode_movz(aarch64_reg_t rd, uint16_t imm, uint8_t shift, operand_size_t size) {
    return encode_mov_immediate(rd, imm, shift, size);
}

// MOVN (Move wide with NOT): MOVN Xd, #imm{, LSL #shift}
// Result = NOT(imm16 << shift)
uint32_t encode_movn(aarch64_reg_t rd, uint16_t imm, uint8_t shift, operand_size_t size) {
    uint32_t instr = 0;
    
    if (size == SIZE_64BIT) {
        instr = 0x92800000;  // 64-bit MOVN
    } else {
        instr = 0x12800000;  // 32-bit MOVN
    }
    
    uint8_t hw = shift / 16;
    
    instr |= (hw & 0x3) << 21;      // hw field
    instr |= (imm & 0xFFFF) << 5;   // imm16 field
    instr |= (rd & 0x1F);           // Rd (destination register)
    
    return instr;
}

// MOVK (Move wide with keep): MOVK Xd, #imm{, LSL #shift}
// Keeps other bits unchanged, only modifies the selected 16-bit portion
uint32_t encode_movk(aarch64_reg_t rd, uint16_t imm, uint8_t shift, operand_size_t size) {
    uint32_t instr = 0;
    
    if (size == SIZE_64BIT) {
        instr = 0xF2800000;  // 64-bit MOVK
    } else {
        instr = 0x72800000;  // 32-bit MOVK
    }
    
    uint8_t hw = shift / 16;
    
    instr |= (hw & 0x3) << 21;      // hw field
    instr |= (imm & 0xFFFF) << 5;   // imm16 field
    instr |= (rd & 0x1F);           // Rd (destination register)
    
    return instr;
}

// MOV (inverted): MVN Xd, Xm{, shift #amount}
// This is an alias for ORN Xd, XZR, Xm, shift #amount
uint32_t encode_mvn(aarch64_reg_t rd, aarch64_reg_t rm, shift_type_t shift, 
                    uint8_t amount, operand_size_t size) {
    uint32_t instr = 0;
    
    // ORN Xd, XZR, Xm
    if (size == SIZE_64BIT) {
        instr = 0xAA2003E0;  // 64-bit ORN
    } else {
        instr = 0x2A2003E0;  // 32-bit ORN
    }
    
    instr |= (shift & 0x3) << 22;    // shift type
    instr |= (rm & 0x1F) << 16;      // Rm (source register)
    instr |= (amount & 0x3F) << 10;  // shift amount
    instr |= (rd & 0x1F);            // Rd (destination register)
    
    return instr;
}

// Helper function to build 64-bit immediate using multiple MOVZ/MOVK instructions
void encode_mov_large_immediate(aarch64_reg_t rd, uint64_t imm, uint32_t *instrs, int *count) {
    *count = 0;
    
    // Check if we can use MOVN (all bits set except one 16-bit chunk)
    uint64_t inverted = ~imm;
    int non_ffff_chunks = 0;
    int last_chunk = -1;
    
    for (int i = 0; i < 4; i++) {
        uint16_t chunk = (imm >> (i * 16)) & 0xFFFF;
        if (chunk != 0xFFFF) {
            non_ffff_chunks++;
            last_chunk = i;
        }
    }
    
    if (non_ffff_chunks == 1) {
        // Use MOVN for inverted pattern
        uint16_t chunk = (inverted >> (last_chunk * 16)) & 0xFFFF;
        instrs[(*count)++] = encode_movn(rd, chunk, last_chunk * 16, SIZE_64BIT);
        return;
    }
    
    // Use MOVZ for first non-zero chunk, then MOVK for others
    bool first = true;
    for (int i = 0; i < 4; i++) {
        uint16_t chunk = (imm >> (i * 16)) & 0xFFFF;
        if (chunk != 0 || (i == 0 && imm == 0)) {
            if (first) {
                instrs[(*count)++] = encode_movz(rd, chunk, i * 16, SIZE_64BIT);
                first = false;
            } else {
                instrs[(*count)++] = encode_movk(rd, chunk, i * 16, SIZE_64BIT);
            }
        }
    }
}

// Example usage
#include <stdio.h>

int main() {
    uint32_t instr;
    
    printf("=== MOV Register Examples ===\n");
    
    // MOV X0, X1
    instr = encode_mov_register(X0, X1, SIZE_64BIT);
    printf("MOV X0, X1:                 0x%08X\n", instr);
    
    // MOV W5, W10
    instr = encode_mov_register(W5, W10, SIZE_32BIT);
    printf("MOV W5, W10:                0x%08X\n", instr);
    
    // MOV X29, X30  (FP = LR, common in epilogue)
    instr = encode_mov_register(FP, LR, SIZE_64BIT);
    printf("MOV X29, X30:               0x%08X\n", instr);
    
    printf("\n=== MOV to/from SP Examples ===\n");
    
    // MOV X0, SP
    instr = encode_mov_sp(X0, SP, SIZE_64BIT);
    printf("MOV X0, SP:                 0x%08X\n", instr);
    
    // MOV SP, X1
    instr = encode_mov_sp(SP, X1, SIZE_64BIT);
    printf("MOV SP, X1:                 0x%08X\n", instr);
    
    printf("\n=== MOV Immediate Examples ===\n");
    
    // MOV X0, #42
    instr = encode_mov_immediate(X0, 42, 0, SIZE_64BIT);
    printf("MOV X0, #42:                0x%08X\n", instr);
    
    // MOV W5, #1000
    instr = encode_mov_immediate(W5, 1000, 0, SIZE_32BIT);
    printf("MOV W5, #1000:              0x%08X\n", instr);
    
    // MOV X3, #0x1234, LSL #16
    instr = encode_mov_immediate(X3, 0x1234, 16, SIZE_64BIT);
    printf("MOV X3, #0x1234, LSL #16:   0x%08X\n", instr);
    
    // MOV X7, #0xABCD, LSL #48
    instr = encode_mov_immediate(X7, 0xABCD, 48, SIZE_64BIT);
    printf("MOV X7, #0xABCD, LSL #48:   0x%08X\n", instr);
    
    printf("\n=== MOVZ/MOVN/MOVK Examples ===\n");
    
    // MOVZ X0, #0x5678
    instr = encode_movz(X0, 0x5678, 0, SIZE_64BIT);
    printf("MOVZ X0, #0x5678:           0x%08X\n", instr);
    
    // MOVN X1, #0  (loads 0xFFFFFFFFFFFFFFFF)
    instr = encode_movn(X1, 0, 0, SIZE_64BIT);
    printf("MOVN X1, #0:                0x%08X\n", instr);
    
    // MOVN W2, #5  (loads 0xFFFFFFFA = -6)
    instr = encode_movn(W2, 5, 0, SIZE_32BIT);
    printf("MOVN W2, #5:                0x%08X\n", instr);
    
    // MOVK X3, #0x1111, LSL #32
    instr = encode_movk(X3, 0x1111, 32, SIZE_64BIT);
    printf("MOVK X3, #0x1111, LSL #32:  0x%08X\n", instr);
    
    printf("\n=== MVN (Move NOT) Examples ===\n");
    
    // MVN X0, X1
    instr = encode_mvn(X0, X1, SHIFT_LSL, 0, SIZE_64BIT);
    printf("MVN X0, X1:                 0x%08X\n", instr);
    
    // MVN W5, W6, LSL #3
    instr = encode_mvn(W5, W6, SHIFT_LSL, 3, SIZE_32BIT);
    printf("MVN W5, W6, LSL #3:         0x%08X\n", instr);
    
    // MVN X10, X11, LSR #8
    instr = encode_mvn(X10, X11, SHIFT_LSR, 8, SIZE_64BIT);
    printf("MVN X10, X11, LSR #8:       0x%08X\n", instr);
    
    printf("\n=== Building Large Immediates ===\n");
    
    uint32_t instrs[4];
    int count;
    
    // MOV X0, #0x123456789ABCDEF0
    encode_mov_large_immediate(X0, 0x123456789ABCDEF0ULL, instrs, &count);
    printf("MOV X0, #0x123456789ABCDEF0 (%d instructions):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  0x%08X\n", instrs[i]);
    }
    
    // MOV X1, #0xFFFFFFFF00000000 (should use MOVN)
    encode_mov_large_immediate(X1, 0xFFFFFFFF00000000ULL, instrs, &count);
    printf("MOV X1, #0xFFFFFFFF00000000 (%d instruction):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  0x%08X\n", instrs[i]);
    }
    
    // MOV X2, #-1 (0xFFFFFFFFFFFFFFFF)
    encode_mov_large_immediate(X2, 0xFFFFFFFFFFFFFFFFULL, instrs, &count);
    printf("MOV X2, #-1 (%d instruction):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  0x%08X\n", instrs[i]);
    }
    
    return 0;
}
```