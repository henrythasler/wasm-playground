#include <stdio.h>
#include <stdint.h>

extern int32_t asmabs(int32_t a);

/**
 * compile with: aarch64-linux-gnu-gcc -ggdb3 -static -o wrapper wrapper_main.c wrapper_extern.s
 * run with: qemu-aarch64 -L /usr/aarch64-linux-gnu/ -g 1234 ./wrapper
 * debug with: gdb-multiarch -q --nh -ex 'set architecture aarch64' -ex 'file wrapper' -ex 'target remote localhost:1234' -ex 'layout split' -ex 'layout regs'
 */
int main() {
    int32_t n = 10;
    printf("ARM: asmabs(%d) = %d\n", n, asmabs(n));
    return 0;
}