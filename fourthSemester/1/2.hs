fib' = 1 : zipWith (+) fib' (0 : fib')
fib n = last(take n fib')