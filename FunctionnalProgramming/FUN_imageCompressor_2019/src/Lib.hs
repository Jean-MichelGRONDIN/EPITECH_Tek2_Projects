--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Lib
--

module Lib
    ( exitError,
      isInteger,
      readInt,
      isDouble,
      readDouble,
      myNth,
      isDigit,
      countTillNotDigit,
      countTillDigit,
      readFirstInt,
      strToIntArray,
      clearTab,
      randomNbInt,
      randomInt,
      isThisInTab,
      uniqueTabVal,
      getThisIndexMax,
      myPowD
    ) where

import System.Exit
import System.Random

exitError :: String -> IO ()
exitError str = do putStrLn str
                   exitWith (ExitFailure 84)

isInteger :: [Char] -> Bool
isInteger s = case reads s :: [(Integer, String)] of
                  [(x,"")] -> True
                  _ -> False

readInt :: [Char] -> Int
readInt s
        | isInteger s == True = read s :: Int
        | otherwise = error "An argument is not an int !"

isDouble :: [Char] -> Bool
isDouble s = case reads s :: [(Double, String)] of
                  [(x,"")] -> True
                  _ -> False

readDouble :: [Char] -> Double
readDouble s
        | isDouble s == True = read s :: Double
        | otherwise = error "An argument is not a Double !"

myNth :: [a] -> Int -> a
myNth [] i = error "nth empty tab encountered"
myNth a 0 = head a
myNth a i
    | i < 0 = myNth a (length a + i)
    | i > ((length a) - 1) = myNth a (abs (length a - i))
    | otherwise = myNth (tail(a)) (i - 1)

isDigit :: Char -> Bool
isDigit c
    | c >= '0' && c <= '9' || c == '-' = True
    | otherwise = False

countTillNotDigit :: String -> String
countTillNotDigit "" = ""
countTillNotDigit (x:xs)
    | isDigit x == False = (x:xs)
    | otherwise = countTillNotDigit xs

countTillDigit :: String -> String
countTillDigit "" = ""
countTillDigit (x:xs)
    | isDigit x == True = (x:xs)
    | otherwise = countTillDigit xs

readFirstInt :: [Char] -> Int
readFirstInt s = case reads s :: [(Int, String)] of
                  [(x,s)] -> x
                  _ -> error "No int to read"

strToIntArray :: String -> [Int] -> [Int]
strToIntArray "" res = reverse res
strToIntArray str res = do let tmp = countTillDigit str
                           if length tmp > 0 then strToIntArray (countTillNotDigit(tmp)) ((readFirstInt (tmp)):res)
                                             else reverse res

clearTab :: [[a]] -> [[a]]
clearTab [] = []
clearTab (x:xs)
    | length x == 0 = clearTab xs
    | otherwise = x:(clearTab xs)

randomNbInt :: Int -> StdGen -> Int -> [Int]
randomNbInt nb seed max = map (\x -> x `mod` (max + 1)) (map abs (take nb (randoms seed :: [Int])))

randomInt :: StdGen -> Int -> Int
randomInt seed max = (abs (head (take 1 (randoms seed :: [Int])))) `mod` (max + 1)

isThisInTab :: [Double] -> [[Double]] -> Bool
isThisInTab v [] = False
isThisInTab v (x:xs)
    | v == x = True
    | otherwise = isThisInTab v xs

uniqueTabVal :: [[Double]] -> [[Double]]
uniqueTabVal [] = []
uniqueTabVal (x:xs)
    | isThisInTab x xs == True = uniqueTabVal xs
    | otherwise = x:(uniqueTabVal xs)

getThisIndexMax :: [[Int]] -> Int -> Int -> Int
getThisIndexMax [] i max = max
getThisIndexMax (x:xs) i max
    | (myNth x i) > max = getThisIndexMax xs i (myNth x i)
    | otherwise = getThisIndexMax xs i max

myPowD :: Double -> Int -> Double
myPowD x 1 = x
myPowD x n = x * (myPowD x (n - 1))