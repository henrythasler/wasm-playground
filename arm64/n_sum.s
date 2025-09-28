.section .text
.global _start

_start:
    adrp x1, msg    // load page (4KiB-aligned) address of msg into x1 (upper 52 bits)
    add x1, x1, :lo12: msg    // add lower 12 bits of address of msg
    ldr x2, =len    // length of message
    bl write

    mov x0, #4
    bl n_sum

    mov x0, #0      // exit code 0
    b exit

n_sum:
    mov x1, #0
n_sum_loop_start:
    add x1, x1, x0
    sub x0, x0, #1
    cbnz x0, n_sum_loop_start
    ret

/* syscall write(int fd, const void *buf, size_t count) */
write:
    mov x0, #1      // file descriptor 1 is stdout
    mov w8, #64     // syscall number for 'write'
    svc #0          // make syscall
    ret

/* syscall exit(int status) */
exit:
    mov w8, #93     // syscall number for 'exit'
    svc #0          // make syscall

msg:
.asciz "Hello, ARM64!\n"
len = . - msg       // calculate length of message by subtracting addresses of msg and current location (.)
