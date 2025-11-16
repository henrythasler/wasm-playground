(module
  (func (export "simple")
    block 
      i32.const 0x3f
      drop
    end
  )

  (func (export "simple-br-i32") (result i32)
    block (result i32)
      i32.const 42
      br 0
      drop
      i32.const 11
    end
  )

  (func (export "simple-br_if") (result i32)
    block (result i32)
      i32.const 32
      i32.const 0
      br_if 0
      drop
      i32.const 42
      i32.const 1
      br_if 0
      drop
      i32.const 11
    end
  )

  (func (export "nested-br_if") (result i32)
    block (result i32)
      block (result i32)
        i32.const 32
        i32.const 0
        br_if 0
        drop
        i32.const 42
        i32.const 1
        br_if 1
        drop
        i32.const 11
      end
      drop
      i32.const 10
      i32.const 0
      br_if 0
      drop
      i32.const 20
      i32.const 1
      br_if 0
      drop
      i32.const 30
    end
  )
)