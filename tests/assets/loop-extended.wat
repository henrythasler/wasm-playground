(module
  (export "loop_n" (func $func7))
  (func $func7 (param $var0 i32) (param $var1 i32) (result i32)
    loop $label1
      local.get $var0
      i32.const 1
      i32.add
      local.set $var0
      local.get $var0
      local.get $var1
      i32.lt_u
      br_if $label1
    end $label1
    local.get $var0
  )  
)