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
      unreachable
    end
  )
)