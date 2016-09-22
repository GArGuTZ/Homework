verifyUniqueness :: [Int] -> Bool
verifyUniqueness [] = True
verifyUniqueness (x:xs) = notElem x xs && verifyUniqueness xs