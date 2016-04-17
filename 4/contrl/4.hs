func' :: [Double] -> [Double] -> Double
func' x [] = func' x (map (cos) x)
func' x y = (foldl (+) 0 x) / (foldl (*) 1 y)

func :: [Double] -> Double
func x = func' x []