--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- checkArgs
--

module CheckArgs where

import Lib

checkArgs :: [String] -> Int
checkArgs tab
    | length tab == 0 = 1
    | length tab == 1 && (myNth tab 0) == "-h" || (myNth tab 0) == "--help" = 1
    | length tab /= 3 = -1
    | isInteger (myNth tab 0) == False || readInt (myNth tab 0) < 1 = -1
    | isDouble (myNth tab 1) == False || readDouble (myNth tab 1) <= 0 = -1
    | otherwise = 0
