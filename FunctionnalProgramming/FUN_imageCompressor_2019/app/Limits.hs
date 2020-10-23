--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Limits
--

module Limits where

import Lib

centroideDistance :: [Double] -> [Double] -> Double
centroideDistance oldC newC = sqrt ((myPowD ((myNth oldC 2) - (myNth newC 2)) 2) + (myPowD ((myNth oldC 3) - (myNth newC 3)) 2) + (myPowD ((myNth oldC 4) - (myNth newC 4)) 2))

isLimitCrossed :: [[Double]] -> [[Double]] -> Double -> Int -> Int -> Bool
isLimitCrossed [] newTab e i n = False
isLimitCrossed tab [] e i n = False
isLimitCrossed (x:xs) (w:ws) e i n
    | i == n = False
    | (centroideDistance x w) > e = True
    | otherwise = isLimitCrossed xs ws e (i + 1) n