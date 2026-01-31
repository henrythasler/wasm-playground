(module
  (memory 0)
  (data (i32.const 768) "0123456789ABCDEF")
  ;; (export "load_u8_offset" (func $load_u8_offset))
  (export "load_i64" (func $load_i64))
  (export "load_i32" (func $load_i32))
  ;; (func $load_u8_offset (param $index i32) (result i32)
  ;;   local.get $index
  ;;   i32.load8_u offset=768
  ;; )
  (func $load_i64 (param $index i32) (result i64)
    local.get $index
    i64.load
  )
  (func $load_i32 (param $index i32) (result i64)
    local.get $index
    i32.load
  )  
)