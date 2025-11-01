for f in ./tests/machinecode/*.bin; do 
    # disassemble arm64 binaries and change file extension to asm
    aarch64-linux-gnu-objdump -D -b binary -m aarch64 $f > ${f%.bin}.asm;
done