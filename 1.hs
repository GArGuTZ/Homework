l1 :: [Int]
l1 = [(2 * mod x 2) - 1 | x <- [1..]]

l2 ::[Int]
l2 = zipWith (\x y -> x * y) l1 [1..]