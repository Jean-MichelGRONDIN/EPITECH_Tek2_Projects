import System.Environment
import System.Exit

myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n a
       | head a == n = True
       | otherwise = myElem n (tail a)


safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (div x y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] n = Nothing
safeNth a 0 = Just (head a)
safeNth a n
        | n < 0 = Nothing
        | otherwise = safeNth (tail a) (n - 1)


safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc n = fmap sum $ sequence [n, Just 1]


myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup n [] = Nothing
myLookup n a
         | fst (head a) == n = Just (snd (head a))
         | otherwise = myLookup n (tail a)


maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f Nothing b = Nothing
maybeDo f a Nothing = Nothing
maybeDo f a b = do x <- a
                   y <- b
                   return (f x y)


isInteger :: [Char] -> Bool
isInteger s = case reads s :: [(Integer, String)] of
                  [(x,"")] -> True
                  _ -> False


readInt :: [Char] -> Maybe Int
readInt s
        | isInteger s == True = Just (read s :: Int)
        | otherwise = Nothing


getLineLength :: IO Int
getLineLength = do l <- getLine
                   return (length l)


printAndGetLength :: String -> IO Int
printAndGetLength s = do putStrLn s
                         return (length s)


printNbChars :: Char -> Int -> IO ()
printNbChars c 1 = putChar c
printNbChars c nb = do putChar c
                       printNbChars c (nb - 1)

printExtraLine :: Int -> IO ()
printExtraLine n = do putChar '+';
                      printNbChars '-' ((n*2)-2);
                      putChar '+';
                      putChar '\n';


printBoxLine :: Int -> IO ()
printBoxLine n = do putChar '|';
                       printNbChars ' ' ((n*2)-2);
                       putChar '|';
                       putChar '\n';


execNbFunc :: (Int -> IO ()) -> Int -> Int -> IO ()
execNbFunc f n 0 = putChar '\0'
execNbFunc f n 1 = f n
execNbFunc f n i = do f n;
                      execNbFunc f n (i - 1);


printBox :: Int -> IO ()
printBox n
         | n <= 0 = putChar '\0'
         | n == 1 = do printNbChars '+' 2;
                       putChar '\n';
         | otherwise = do printExtraLine n;
                          execNbFunc printBoxLine n (n - 2);
                          printExtraLine n;


concatLines :: Int -> IO String
concatLines 1 = getLine
concatLines n
            | n < 1 = return ""
            | otherwise = do s <- getLine
                             two <- concatLines (n - 1)
                             return (s ++ two)


getInt :: IO (Maybe Int)
getInt = do s <- getLine
            return (readInt s)


main = exitWith (ExitFailure 84)