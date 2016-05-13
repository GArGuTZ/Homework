checkSequence' :: String -> String -> Bool
checkSequence' [] stack = null stack
checkSequence' (x:seq) stack | x == '(' = checkSequence' seq (x:stack)
                             | x == '[' = checkSequence' seq (x:stack)
                             | x == '{' = checkSequence' seq (x:stack)
                             | x == ')' = not (null stack) && (head stack == '(') && (checkSequence' seq (tail stack))
                             | x == ']' = not (null stack) && (head stack == '[') && (checkSequence' seq (tail stack))
                             | x == '}' = not (null stack) && (head stack == '{') && (checkSequence' seq (tail stack))
                             | otherwise = checkSequence' seq stack 

checkSequence :: String -> Bool
checkSequence seq = checkSequence' seq []