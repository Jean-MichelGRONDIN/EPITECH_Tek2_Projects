module CheckArgs where

isInteger :: [Char] -> Bool
isInteger s = case reads s :: [(Integer, String)] of
                   [(x,"")] -> True
                   _ -> False

checkArgs :: [String] -> Bool
checkArgs (x:xs)
        | length xs == 0 && isInteger x == True = True
        | otherwise = if isInteger x == True then checkArgs xs else False