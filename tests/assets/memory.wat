(module
  (memory 0)
  (export "get_byte" (func $get_byte))
  (func $get_byte (param $index i32) (result i32)
    i32.const 42
  )
)