_searchNumber :: Int -> [Int] -> Int -> Int
_searchNumber _ [] _ = 0
_searchNumber x (y:ys) i | x == y = i
                         | x /= y = _searchNumber x ys (i + 1)

searchNumber :: Int -> [Int] -> Int
searchNumber x y = _searchNumber x y 1