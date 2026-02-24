#!/bin/bash

# exit when any command fails
set -e

for file in ./tests/assets/*.c; do 
    # exit if no files were found
    if [[ ! -e "$file" ]]; then 
        continue
    fi
    /opt/wasi-sdk/bin/clang -O0 -fdata-sections -ffunction-sections -mcpu=mvp -mmutable-globals -Wl,--allow-undefined,--export-table,--gc-sections,--no-entry,--export=_start -lstdc++ -z stack-size=8192 -nostartfiles -o ${file%.c}.wasm ${file}
done