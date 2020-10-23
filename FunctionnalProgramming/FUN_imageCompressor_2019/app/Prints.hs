--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Prints
--

module Prints where

import System.Exit

import Lib
import Centroides

printEachVals :: [[Int]] -> IO ()
printEachVals [] = putStr ""
printEachVals (x:xs) = do putStr ("(" ++ (show (myNth x 0)) ++ "," ++ (show (myNth x 1)) ++ ") ")
                          putStrLn ("(" ++ (show (myNth x 2)) ++ "," ++ (show (myNth x 3)) ++ "," ++ (show (myNth x 4)) ++ ")")
                          printEachVals xs

sumIndexI :: [[Int]] -> Int -> Int
sumIndexI [] i = 0
sumIndexI (x:xs) i = (myNth x i) + (sumIndexI xs i)

calcColorMean :: [[Int]] -> [Int]
calcColorMean vals = ((sumIndexI vals 2) `div` (length vals)):((sumIndexI vals 3) `div` (length vals)):((sumIndexI vals 4) `div` (length vals)):[]

printThisCluster :: [[Int]] -> IO ()
printThisCluster pts = do putStrLn "--"
                          let colorMean = (calcColorMean pts)
                          putStrLn ("(" ++ (show (myNth colorMean 0)) ++ "," ++ (show (myNth colorMean 1)) ++ "," ++ (show (myNth colorMean 2)) ++ ")")
                          putStrLn "-"
                          printEachVals pts

printResult :: [[Int]] -> [Int] -> Int -> Int -> IO ()
printResult points clusters i n
    | i == n = exitWith (ExitSuccess)
    | otherwise = do printThisCluster (getThosesCentroides points clusters i)
                     printResult points clusters (i + 1) n

