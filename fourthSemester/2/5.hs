palindrom :: String -> Bool
palindrom [] = True
palindrom [_] = True
palindrom s = head s == last s && (palindrom . init . tail) s