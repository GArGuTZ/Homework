fact' :: Int -> Int -> Int
fact' 0 x = x
fact' n x = fact' (n-1) (n*x)

fact :: Int -> Int
fact n = fact' n 1