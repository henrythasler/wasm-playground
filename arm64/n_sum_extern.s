.global n_sum_extern
.global fib_extern
.type n_sum_extern, "function"
.type fib_extern, "function"
.p2align 4

// see https://github.com/ARM-software/abi-aa/blob/main/aapcs64/aapcs64.rst#68parameter-passing
n_sum_extern:
    mov x1, #0
nsum_loop_start:
    add x1, x1, x0
    sub x0, x0, #1
    cbnz x0, nsum_loop_start
    mov x0, x1
    ret

// returns the n-th Fibonacci number, where fib(0)=0, fib(1)=1, fib(2)=1, fib(3)=2, fib(4)=3, fib(5)=5, ...
fib_extern:
    cmp x0, #1          // if n <= 1
    ble fib_done       //   return n
    mov x1, #0          // a = fib(0) = 0
    mov x2, #1          // b = fib(1) = 1
fib_loop_start:
    add x3, x1, x2      // c = a + b
    mov x1, x2          // a = b
    mov x2, x3          // b = c
    sub x0, x0, #1      // n = n - 1
    cmp x0, #1          // while n > 1
    bgt fib_loop_start
    mov x0, x2          // return b
    ret
fib_done:
    ret
