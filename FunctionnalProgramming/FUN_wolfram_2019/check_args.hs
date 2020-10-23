--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- check_args
--

module CheckArgsStart where

headIsInteger_pttwo :: [String] -> Bool
headIsInteger_pttwo (x:xs) = case reads x :: [(Integer, String)] of
                   [(y,"")] -> True
                   _ -> False

headIsInteger :: [String] -> Bool
headIsInteger tab
        | length tab == 0 = False
        | otherwise = headIsInteger_pttwo tab

checkArgsTwo :: [String] -> Bool
checkArgsTwo (x:xs) = case x of
                   "--rule" -> if headIsInteger xs == True then checkArgsOne (tail xs) else False
                   "--start" -> if headIsInteger xs == True then checkArgsOne (tail xs) else False
                   "--lines" -> if headIsInteger xs == True then checkArgsOne (tail xs) else False
                   "--window" -> if headIsInteger xs == True then checkArgsOne (tail xs) else False
                   "--move" -> if headIsInteger xs == True then checkArgsOne (tail xs) else False
                   _ -> False

checkArgsOne :: [String] -> Bool
checkArgsOne tab
        | length tab == 0 = True
        | otherwise = checkArgsTwo tab

checkArgsStart :: [String] -> Bool
checkArgsStart tab
        | length tab == 0 || length tab `mod` 2 /= 0 = False
        | otherwise = checkArgsTwo tab