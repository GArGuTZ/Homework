data Tree a = Null
            | Leaf a
            | Branch (Tree a) a (Tree a)

maxHeight' :: Tree a -> Int -> Int
maxHeight' Null x = x
maxHeight' (Leaf _) x = x + 1
maxHeight' (Branch left _ right) x = max (maxHeight' right (x + 1)) (maxHeight' left (x + 1))

minHeight' :: Tree a -> Int -> Int
minHeight' Null x = x
minHeight' (Leaf _) x = x + 1
minHeight' (Branch left _ right) x = min (minHeight' right (x + 1)) (minHeight' left (x + 1))

maxHeight :: Tree a -> Int
maxHeight tree = maxHeight' tree 0

minHeight :: Tree a -> Int
minHeight tree = minHeight' tree 0