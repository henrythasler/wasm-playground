(module
  (memory 1)
  (export "load_i32" (func $load_i32))
  (export "memory_grow" (func $memory_grow))
  (func $load_i32 (param $index i32) (result i32)
    local.get $index
    i32.load
  )
  (func $memory_grow (param $pages i32) (result i32)
    local.get $pages
    memory.grow
  )
)