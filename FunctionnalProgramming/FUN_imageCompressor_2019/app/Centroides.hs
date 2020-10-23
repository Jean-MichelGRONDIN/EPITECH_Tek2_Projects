--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Centroides
--

module Centroides where

import Lib

sumIndex :: [[Int]] -> Int -> Double
sumIndex [] i = 0
sumIndex (x:xs) i = (fromIntegral (myNth x i)) + (sumIndex xs i)

calcThisCentroide :: [[Int]] -> Int -> Double -> [Double]
calcThisCentroide vals i n = ((sumIndex vals 0) / (fromIntegral (length vals))):((sumIndex vals 1) / (fromIntegral (length vals))):((sumIndex vals 2) / (fromIntegral (length vals))):((sumIndex vals 3) / (fromIntegral (length vals))):((sumIndex vals 4) / (fromIntegral (length vals))):[]

getThosesCentroides :: [[Int]] -> [Int] -> Int -> [[Int]]
getThosesCentroides points [] i = []
getThosesCentroides []  clusters i = []
getThosesCentroides (t:ts) (x:xs) i
    | x == i = t:(getThosesCentroides ts xs i)
    | otherwise = getThosesCentroides ts xs i

reCenterCentroides :: [[Int]] -> [Int] -> Int -> Int -> [[Double]]
reCenterCentroides points clusters i n
    | i == n = []
    | otherwise = (calcThisCentroide (getThosesCentroides points clusters i) i (fromIntegral n)):(reCenterCentroides points clusters (i + 1) n)

