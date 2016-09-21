module Main where

addValue :: [Int] -> Int -> [Int]
addValue [] y = [y]
addValue (x:xs) y | x < y = x : (addValue xs y)
                  | otherwise = y:x:xs

removeValue :: [Int] -> Int -> [Int]
removeValue [] _ = []
removeValue (x:xs) y | x < y  = x:(removeValue xs y)
                     | x == y = removeValue xs y
                     | x > y  = x:xs

listManagement :: [Int] -> IO ()
listManagement list = do
    putStrLn "Enter command:"
    putStrLn "0 - exit"
    putStrLn "1 - add value to sorted list"
    putStrLn "2 - remove value from list"
    putStrLn "3 - print list"
    command <- getChar 
    getLine
    case command of
        '0' -> return ()
        '1' -> do putStrLn "Enter value to add: "
                  value <- readLn
                  listManagement (addValue list value)
        '2' -> do putStrLn "Enter value to remove: "
                  value <- readLn
                  listManagement (removeValue list value)
        '3' -> do print list
                  listManagement list
        otherwise -> listManagement list

main :: IO ()
main = listManagement []






