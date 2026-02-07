(module
  (memory 1 16)
  (export "load_i32" (func $load_i32))
  (export "store_i32" (func $store_i32))
  (export "memory_grow" (func $memory_grow))
  (export "memory_size" (func $memory_size))
  (func $load_i32 (param $index i32) (result i32)
    local.get $index
    i32.load
  )
  (func $store_i32 (param $index i32) (param $value i32) (result i32)
    local.get $index
    local.get $value
    i32.store
    local.get $index
    i32.load
  )  
  (func $memory_grow (param $pages i32) (result i32)
    local.get $pages
    memory.grow
  )
  (func $memory_size (result i32)
    memory.size
  )
)