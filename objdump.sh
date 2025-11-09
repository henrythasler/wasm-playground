#!/bin/bash

# exit when any command fails
set -e

for file in ./tests/machinecode/*.bin; do 
    # exit if no files were found
    if [[ ! -e "$file" ]]; then 
        continue
    fi

    # disassemble arm64 binaries and change file extension to asm
    # see https://man.archlinux.org/man/aarch64-linux-gnu-objdump.1
    aarch64-linux-gnu-objdump -D -b binary -m aarch64 $file > ${file%.bin}.asm;
    rm ${file}
done