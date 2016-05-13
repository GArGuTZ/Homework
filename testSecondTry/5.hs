rhomb :: Int -> IO ()
rhomb n = do
        putStrLn (buildRhomb 1 [])
        where
            buildString pos = '\n' : replicate (n - pos) ' ' ++ replicate (2 * pos - 1) '*'
            buildRhomb pos rl | pos == n = buildString pos ++ rl
                              | otherwise = buildString pos ++ buildRhomb (pos + 1) (buildString pos ++ rl)