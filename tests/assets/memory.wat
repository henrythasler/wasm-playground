(module
  (memory 0)
  (data (i32.const 767) "\fd0123456789ABCDEF")
  (export "load_i64" (func $load_i64))
  (export "load_i32" (func $load_i32))
  (export "load_u16" (func $load_u16))
  (export "load_u8" (func $load_u8))
  (export "load_i8" (func $load_i8))
  (export "load_u8_offset" (func $load_u8_offset))
  (export "store_i64" (func $store_i64))
  (export "store_i32" (func $store_i32))
  (export "store_i16" (func $store_i16))
  (export "store_i8" (func $store_i8))
  (func $load_i64 (param $index i32) (result i64)
    local.get $index
    i64.load
  )
  (func $load_i32 (param $index i32) (result i32)
    local.get $index
    i32.load
  )
  (func $load_u16 (param $index i32) (result i32)
    local.get $index
    i32.load16_u
  )
  (func $load_u8 (param $index i32) (result i32)
    local.get $index
    i32.load8_u
  )
  (func $load_i8 (param $index i32) (result i32)
    local.get $index
    i32.load8_s
  )
  (func $load_u8_offset (param $index i32) (result i32)
    local.get $index
    i32.load8_u offset=768
  )
  (func $store_i64 (param $index i32) (param $value i64) (result i64)
    local.get $index
    local.get $value
    i64.store
    local.get $index
    i64.load
  )
  (func $store_i32 (param $index i32) (param $value i32) (result i32)
    local.get $index
    local.get $value
    i32.store
    local.get $index
    i32.load
  )
  (func $store_i16 (param $index i32) (param $value i32) (result i32)
    local.get $index
    local.get $value
    i32.store16
    local.get $index
    i32.load16_u
  )
  (func $store_i8 (param $index i32) (param $value i32) (result i32)
    local.get $index
    local.get $value
    i32.store8
    local.get $index
    i32.load8_u
  )
)