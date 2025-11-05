for f in ./tests/machinecode/*.bin; do 
    # disassemble arm64 binaries and change file extension to asm
    # see https://man.archlinux.org/man/aarch64-linux-gnu-objdump.1
    aarch64-linux-gnu-objdump -D -b binary -m aarch64 $f > ${f%.bin}.asm;
    rm ${f}
done