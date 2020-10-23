--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- rule30
--

module Rule90 where

import Print_that_line

myNth :: [a] -> Int -> a
myNth [] i = error "nth empty tab encountered"
myNth a 0 = head a
myNth a i
    | i < 0 = myNth a (length a + i)
    | i > ((length a) - 1) = myNth a 0
    | otherwise = myNth (tail(a)) (i - 1)

myXor :: Bool -> Bool -> Bool
myXor a b
    | a /= b = True
    | otherwise = False

myOr :: Bool -> Bool -> Bool
myOr a b
    | a == b && a == False = False
    | otherwise = True

get_this_one :: Int -> [Bool] -> Bool
get_this_one x [] = True
get_this_one x tab = myXor (myNth tab (x - 1)) (myNth tab (x + 1))

creat_tab :: Int -> Int -> [Bool] -> [Bool]
creat_tab n x tab
    | x == (1 + 2 * n) = False:[]
    | x == 1 = False:creat_tab n (x + 1) tab
    | otherwise = (get_this_one (x - 2) tab):creat_tab n (x + 1) tab

rule90 :: Int -> Int -> Int -> Int -> Int -> [Bool] -> IO ()
rule90 n linemax start window move tab
    | (n - 2) == (start - 1 + linemax) = (if start > linemax then print_that_line n linemax window move tab else putStr "")
    | otherwise = do if start > linemax then (if (start) <= (n - 2) && (n - 2) <= (start + linemax) then print_that_line n linemax window move tab else putStr "")
                        else (if (n - 1) <= (start + linemax) then print_that_line n linemax window move tab else putStr "")
                     rule90 (n + 1) linemax start window move (creat_tab n 1 tab)

-- rule90 :: Int -> Int -> Int -> Int -> Int -> [Bool] -> IO ()
-- rule90 n linemax start window move tab
--     | n == linemax + 1 = print_that_line n linemax window move tab
--     | otherwise = do if (start - 1) <= (n - 2) then print_that_line n linemax window move tab else putStr ""
--                      rule90 (n + 1) linemax start window move (creat_tab n 1 tab)