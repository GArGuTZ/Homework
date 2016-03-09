-- func x l = map (\y -> y*x) l
-- func x = map (\y -> y*x)
-- func x = map ((*) x)
-- func = map . (*)

func :: Num a => a -> [a] -> [a]
func = map . (*)