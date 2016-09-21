pairs :: Int -> [Int]
pairs n = [1..n] >>= (\x -> map (x*) [1..n])