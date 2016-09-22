data Monom = Monom { factor::Int, 
                     degree::Int }

instance Eq Monom where
    (==) (Monom 0 _) (Monom 0 _) = True
    (==) (Monom 0 _) _ = False
    (==) _ (Monom 0 _) = False
    (==) (Monom _ x) (Monom _ y) = x == y
    
instance Ord Monom where
    (<=) (Monom 0 _) _ = False
    (<=) _ (Monom 0 _) = True
    (<=) (Monom _ x) (Monom _ y) | x == y = True
                                 | otherwise = x <= y

instance Show Monom where
    show (Monom 0 _) = "0"
    show (Monom x 0) | x > 0 = show x
                     | otherwise = "(" ++ show x ++ ")"
    show (Monom 1 1) = "x"
    show (Monom 1 y) = "x^" ++ show y
    show (Monom (-1) y) = "(-" ++ show (Monom 1 y) ++ ")"
    show (Monom x y) | x > 0 = show x ++ show (Monom 1 y)
                     | otherwise = "(" ++ show x ++ show (Monom 1 y) ++ ")"

instance Num Monom where
    (+) (Monom x y) (Monom w z) | y == z = Monom (x + w) y
                                | otherwise = error "Sum error"
    (*) (Monom x y) (Monom w z) = Monom (x * w) (y + z)
    abs (Monom x y) = Monom (abs x) y
    negate (Monom x y) = Monom (negate x) y
    signum (Monom x _) = Monom (signum x) 0
    fromInteger x = Monom (fromInteger x :: Int) 0

derivative :: Monom -> Monom
derivative (Monom 0 _) = (Monom 0 0)
derivative (Monom _ 0) = (Monom 0 0)
derivative (Monom x y) = Monom (x * y) (y - 1)

data Polynom = Polynom [Monom]
organise :: Polynom -> Polynom
organise (Polynom pol) = Polynom (organise' (sort pol))
                       where sort [] = []
                             sort [x] = [x]
                             sort (x:xs) = sort [y | y <- xs, y < x] ++ x : sort [y | y <- xs, y >= x]
                             organise' [Monom 0 _] = []
                             organise' ((Monom 0 _) : xs) = organise' xs
                             organise' (x : []) = [x]
                             organise' (x : (y : xs)) | x == y = organise' ((x + y) : xs)
                                                      | otherwise = x : (organise' (y : xs))

instance Show Polynom where
    show (Polynom []) = "0"
    show (Polynom [x]) = show x
    show (Polynom [x, y]) | x == 0 = show y
                          | otherwise = show x ++ " + " ++ show y
    show (Polynom (x:xs)) = show x ++ " + " ++ show (Polynom (xs))
    
instance Num Polynom where
    (+) (Polynom x) (Polynom y) = organise (Polynom (x ++ y))
    (*) (Polynom x) (Polynom y) = organise (Polynom (x >>= \w -> y >>= \z -> return (w * z)))
    abs (Polynom x) = Polynom (map abs x)
    negate (Polynom x) = Polynom (map negate x)
    signum (Polynom _) = error "No sign"
    fromInteger x = Polynom [fromInteger x :: Monom]

derivative' :: Polynom -> Polynom
derivative' (Polynom x) = organise (Polynom (map derivative x))