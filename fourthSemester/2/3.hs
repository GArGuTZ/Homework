sumn :: Int -> Int
sumn x | x == 0 = 0
       | x > 0 = sumn (div x 10) + mod x 10