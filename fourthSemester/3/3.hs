maxSum :: (Ord a, Num a) => [a] -> Int
maxSum (x:xs) = fst( head [ z | z <- zip [1..] ( zipWith (+) xs (x:xs) ), snd z == maximum (zipWith (+) xs (x:xs)) ] )