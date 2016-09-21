mod' :: Int -> Int
mod' x | mod x 2 == 0 = 1
       | otherwise = 0

mod'' :: Int -> Bool
mod'' x | mod x 2 == 0 = True
        | otherwise = False

length' :: [Int] -> Int
length' s = foldr (+) 0 (map (const 1) s)


countFirst :: [Int] ->Int
countFirst s =  foldr (+) 0 (map (mod') s)

countSecond :: [Int] -> Int
countSecond s = length' (filter (mod'') s)

countThird :: [Int] -> Int
countThird s = foldr (\x i -> if (mod'' x) then i + 1 else i) 0 s