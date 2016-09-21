data Tree a = Null
            | Leaf a
            | Branch (Tree a) a (Tree a)

fold :: (a -> a -> a) -> a -> Tree a -> a
fold f x Null = x
fold f x (Leaf y) = f x y
fold f x (Branch l y r) = fold f (fold f (f x y) l) r

search :: Tree a -> (a -> Bool) -> [a]
search Null condition = []
search (Leaf x) condition = if (condition x) then [x] else []
search (Branch l x r) condition = if (condition x) then x:(search l condition) ++ (search r condition)
                                  else (search l condition) ++ (search r condition)