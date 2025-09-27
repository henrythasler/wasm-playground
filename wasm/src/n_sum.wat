(module
    ;; Import the log function from the environment
    (import "env" "log" (func $log (param i32) (result i32)))

    ;; Function to compute the sum of the first n natural numbers
    ;; from 1 to n using recursion
    ;; n_sum(n) = n + n_sum(n-1) with base case n_sum(1) = 1
    ;; Example: n_sum(4) = 4 + 3 + 2 + 1 = 10
    (func $n_sum (param $n i32)
        (result i32)
        local.get $n
        i32.const 1
        i32.eq
        if (result i32)
            i32.const 1
        else
            local.get $n
            local.get $n
            i32.const 1
            i32.sub
            call $n_sum
            i32.add
        end
    )

    ;; main entry point function
    (func $run (param $argument i32) 
        (result i32)
        local.get $argument
        call $n_sum
        call $log
        drop
        i32.const 0
    )

    ;; Export the run function as main entry point
    (export "run" (func $run))
)