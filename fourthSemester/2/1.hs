_reverse :: [a] -> [a] -> [a]
_reverse x [] = x
_reverse x (y:ys) = _reverse (y:x) ys

reverse' = _reverse []