#include <stdio.h>
#include <stdint.h>

/* compile and run with:
 *  aarch64-linux-gnu-gcc -static -o n_sum n_sum.c && ./n_sum
 */

uint32_t n_sum(uint32_t n) {
    if(n <= 0) return 0;
    return n + n_sum(n - 1);
}

uint32_t add_one(uint32_t value) {
    uint32_t result;
    asm volatile(
        "add %[result], %[value], #1"   // ARM assembly to add 1 
        : [result] "=r" (result)        // output operand, "=r" means write to a register
        : [value] "r" (value)           // input operand, "r" means read from a register
    );
    return result;
}

/** Declaration of the external assembly function defined in n_sum_extern.s */
extern int n_sum_extern(int a);
extern int fib_extern(int a);

int main() {
    int32_t n = 4;
    printf("ARM: n_sum(%d) = %d\n", n, n_sum(n));
    printf("ARM: n_sum_extern(%d) = %d\n", n, n_sum_extern(n));
    printf("ARM: fib_extern(%d) = %d\n", n, fib_extern(n));
    printf("ARM: add_one(%d) = %d\n", n, add_one(n));
    return 0;
}