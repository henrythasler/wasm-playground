(module
  (memory 0)
  (data (i32.const 768) "0123456789ABCDEF")
  (export "get_byte" (func $get_byte))
  (func $get_byte (param $index i32) (result i32)
    i32.const 42
  )
)