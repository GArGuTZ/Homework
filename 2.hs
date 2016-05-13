sequ :: Int -> Int -> Int -> [Int]
sequ i x n | i < x = x:(sequ (i + 1) x n)
           | i <= n = i:(sequ (i + 1) x n)
           | otherwise = []

matr' :: Int -> Int -> [[Int]]
matr' i n | i <= n = (sequ 1 i n) : (matr' (i + 1) n)
          | otherwise = []

matrix :: Int -> [[Int]]
matrix n = matr' 1 n