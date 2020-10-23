--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- launch
--

module Launch where

import System.Environment
import System.Exit

import Rule30
import Rule90
import Rule110

isInteger :: [Char] -> Bool
isInteger s = case reads s :: [(Integer, String)] of
                  [(x,"")] -> True
                  _ -> False


readInt :: [Char] -> Int
readInt s
        | isInteger s == True = read s :: Int
        | otherwise = error "An argument is not an int !"

choose_rule :: Int -> Int -> Int -> Int -> Int -> IO ()
choose_rule rule line start window move = case rule of
                                   30 -> rule30 1 line start window move []
                                   90 -> rule90 1 line start window move []
                                   110 -> rule110 1 line start window move []
                                   _ -> do putStr "Wrong rule specified !\n"
                                           exitWith (ExitFailure 84)

launch :: [String] -> Int -> Int -> Int -> Int -> Int -> IO ()
launch args rule line start window move
    | length args == 0 = choose_rule rule line start window move
    | otherwise = case x of
                   "--rule" -> launch (tail (tail args)) (readInt (head xs)) line start window move
                   "--start" -> launch (tail (tail args)) rule line (readInt (head xs)) window move
                   "--lines" -> launch (tail (tail args)) rule (readInt (head xs)) start window move
                   "--window" -> launch (tail (tail args)) rule line start (readInt (head xs)) move
                   "--move" -> launch (tail (tail args)) rule line start window (readInt (head xs))
                   _ -> do putStr "wrong option detected !\n"
                           exitWith (ExitFailure 84)
    where (x:xs) = args