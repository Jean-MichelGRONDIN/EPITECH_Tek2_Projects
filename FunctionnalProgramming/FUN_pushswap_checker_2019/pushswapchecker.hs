module PushswapChecker where

import System.Environment
import System.Exit
import CheckArgs
import AllCmds

readInt :: [Char] -> Int
readInt s = read s :: Int

getArgsInTuple :: [String] -> ([Int],[Int])
getArgsInTuple (x:xs)
        | length xs == 0 = ([readInt x],[])
        | otherwise = (readInt x:fst (getArgsInTuple xs),[])

isUpper :: Int -> Int -> Bool
isUpper x y = if x < y then True else False

isOrdered :: [Int] -> Bool
isOrdered a
        | length a == 1 = True
        | isUpper (head a) (head (drop 1 a)) == True = isOrdered (drop 1 a)
        | otherwise = False

check_end :: ([Int],[Int]) -> Bool
check_end (a,[]) = if isOrdered a then True else False
check_end (a,b) = False

print_ko :: ([Int],[Int]) -> IO ()
print_ko tabs = do putStr "KO: "
                   print tabs

printBadCmd :: IO ()
printBadCmd = do putStrLn "KO: Bad Argument"
                 exitWith (ExitFailure 84)

onlySpaces :: String -> Bool
onlySpaces "" = True
onlySpaces (x:xs)
        | x == ' ' = onlySpaces xs
        | otherwise = False

doCmds :: String -> ([Int],[Int]) -> IO ()
doCmds s tabs
        | s == "" || onlySpaces s == True = if check_end tabs == True then putStrLn "OK" else print_ko tabs
        | otherwise = case x of
                      "sa" -> doCmds (drop ((length x) + 1) s) (sa tabs)
                      "sb" -> doCmds (drop ((length x) + 1) s) (sb tabs)
                      "sc" -> doCmds (drop ((length x) + 1) s) (sc tabs)
                      "pa" -> doCmds (drop ((length x) + 1) s) (pa tabs)
                      "pb" -> doCmds (drop ((length x) + 1) s) (pb tabs)
                      "ra" -> doCmds (drop ((length x) + 1) s) (ra tabs)
                      "rb" -> doCmds (drop ((length x) + 1) s) (rb tabs)
                      "rr" -> doCmds (drop ((length x) + 1) s) (rr tabs)
                      "rra" -> doCmds (drop ((length x) + 1) s) (rra tabs)
                      "rrb" -> doCmds (drop ((length x) + 1) s) (rrb tabs)
                      "rrr" -> doCmds (drop ((length x) + 1) s) (rrr tabs)
                      _ -> printBadCmd
        where (x:xs) = words s

launchCmds :: ([Int],[Int]) -> IO ()
launchCmds (x,y) = do input <- getLine
                      doCmds (input) (x,y)

pushswapChecker :: [String] -> IO ()
pushswapChecker s = launchCmds (getArgsInTuple s)