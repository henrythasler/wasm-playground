(module
    ;; Import the log function from the environment
    (import "env" "log" (func $env.log (param i32)))

    ;; Function to compute the sum of the first n natural numbers from 1 to n using recursion
    ;; n_sum(n) = n + n_sum(n-1) with base case n_sum(1) = 1
    ;; Example: n_sum(4) = 4 + 3 + 2 + 1 = 10
    (func $n_sum (param $n i32) (result i32)
        local.get $n
        i32.const 1
        i32.le_s
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


    ;; Function to compute Fibonacci numbers up to n using Space Optimized Approach
    ;; see https://www.geeksforgeeks.org/dsa/program-for-nth-fibonacci-number/ 
    (func $fib (param $n i32) (result i32)
        (local $i i32)
        (local $curr i32)
        (local $prev1 i32)
        (local $prev2 i32)

        local.get $n
        i32.const 1
        i32.le_s
        if 
            i32.const 1
            call $env.log
        else
            (local.set $curr (i32.const 0))
            (local.set $prev1 (i32.const 1))
            (local.set $prev2 (i32.const 0))

            i32.const 0
            call $env.log

            i32.const 1
            call $env.log

            ;; initialize i to 2
            (local.set $i (i32.const 2))

            (loop $iterate
                local.get $prev1
                local.get $prev2
                i32.add
                local.set $curr

                local.get $curr
                call $env.log

                (local.set $prev2 (local.get $prev1))
                (local.set $prev1 (local.get $curr))

                ;; increment i
                local.get $i
                i32.const 1
                i32.add
                local.set $i

                ;; check if i < n
                local.get $i
                local.get $n
                i32.lt_s
                br_if $iterate ;; continue loop if true
            )
        end
        i32.const 0
    )

    ;; main entry point function
    (func $run (param $argument i32) 
        (result i32)
        local.get $argument
        call $n_sum
        call $env.log

        local.get $argument
        call $fib
        drop
        i32.const 0
    )

    ;; Export the run function as main entry point
    (export "run" (func $run))
)