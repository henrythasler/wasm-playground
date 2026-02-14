(module
  (type $type0 (func))
  (type $type1 (func (result i32)))
  (type $type2 (func (param i32) (result i32)))
  (export "simple" (func $func0))
  (export "simple-br-i32" (func $func1))
  (export "simple-return" (func $func2))
  (export "simple-br_if" (func $func3))
  (export "parameter-br_if" (func $func4))
  (export "parameter-nested-return" (func $func5))
  (export "nested-br_if" (func $func6))
  (func $func0
    block
      i32.const 63
      drop
    end
  )
  (func $func1 (result i32)
    block $label0 (result i32)
      i32.const 42
      br $label0
      drop
      i32.const 11
    end $label0
  )
  (func $func2 (result i32)
    block (result i32)
      i32.const 42
      return
      drop
      i32.const 11
    end
  )
  (func $func3 (result i32)
    block $label0 (result i32)
      i32.const 32
      i32.const 0
      br_if $label0
      drop
      i32.const 42
      i32.const 1
      br_if $label0
      drop
      i32.const 11
    end $label0
  )
  (func $func4 (param $var0 i32) (result i32)
    block $label0 (result i32)
      i32.const 42
      local.get $var0
      br_if $label0
      drop
      i32.const -4
      i32.const -3
      i32.const -2
      i32.const -1
      drop
      drop
      drop
    end $label0
  )
  (func $func5 (param $var0 i32) (result i32)
    block $label0 (result i32)
      i32.const 40
      local.get $var0
      br_if $label0
      drop
      i32.const -4
      return
    end $label0
    i32.const 2
    i32.add
  )
  (func $func6 (result i32)
    block $label1 (result i32)
      block $label0 (result i32)
        i32.const 32
        i32.const 0
        br_if $label0
        drop
        i32.const 42
        i32.const 1
        br_if $label1
        drop
        i32.const 11
      end $label0
      drop
      i32.const 10
      i32.const 0
      br_if $label1
      drop
      i32.const 20
      i32.const 1
      br_if $label1
      drop
      i32.const 30
    end $label1
  )
)