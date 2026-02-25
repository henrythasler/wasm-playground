(module
  (export "loop_n" (func $func7))
  (export "loop_n2" (func $loop_n2))
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

  (func $loop_n2 (param $low i32) (param $high i32) (result i32)
    block  ;; label = @1
      loop  ;; label = @2
        local.get $low
        local.get $high
        i32.lt_s
        i32.const 1
        i32.and
        i32.eqz
        br_if 1 (;@1;)
        local.get $low
        i32.const 1
        i32.add
        local.set $low
        br 0 (;@2;)
      end
    end
    local.get $low
  )
)