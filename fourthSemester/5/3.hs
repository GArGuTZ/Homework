import Control.Monad

findBig :: [Int] -> Maybe Int
findBig [] = Nothing
findBig [_] = Nothing
findBig [_, _] = Nothing
findBig (x:y:z:xs) | ((x < y) && (y > z)) = Just y
                   | otherwise = mplus Nothing (findBig (y:z:xs))