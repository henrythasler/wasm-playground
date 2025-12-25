(module
  ;; Define three functions with different signatures
  (func $add (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.add
  )
  
  (func $multiply (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.mul
  )
  
  (func $square (param i32) (result i32)
    local.get 0
    local.get 0
    i32.mul
  )
  
  ;; Create a table with 5 slots
  (table $funcTable 5 funcref)
  
  ;; Populate the table: put function references at specific indices
  (elem (i32.const 0) $add $multiply $square)
  ;; This puts:
  ;; - $add at index 0
  ;; - $multiply at index 1
  ;; - $square at index 2
  ;; - indices 3 and 4 remain null
  
  ;; Now use call_indirect
  (func $calculate (param i32 i32 i32) (result i32)
    local.get 1    ;; first operand
    local.get 2    ;; second operand
    local.get 0    ;; table index (which operation to perform)
    call_indirect (param i32 i32) (result i32)
  )
  
  (export "calculate" (func $calculate))
)