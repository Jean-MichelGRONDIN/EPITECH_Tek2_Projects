--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Main
--

module Main where

import System.Environment
import System.Exit

import Lib

import CheckArgs
import LaunchProg


exitUsage :: IO ()
exitUsage = do putStrLn "USAGE: ./imageCompressor n e IN"
               putStrLn ""
               putStrLn "      n       number of colors in the final image"
               putStrLn "      e       convergence limit"
               putStrLn "      IN      path to the file containing the colors of the pixels"
               exitWith (ExitSuccess)

analyseChecks :: Int -> IO ()
analyseChecks code
    | code == 1 = exitUsage
    | otherwise = exitError "An Error as been detected in arguments, please check the usage !"

main :: IO ()
main = do args <- getArgs
          let checks = checkArgs args
          if checks == 0 then launchProg (readInt (myNth args 0)) (readDouble (myNth args 1)) (myNth args 2)
                         else analyseChecks checks

-- main = print (randomNbInt 5 42 10)


-- main = do g <- newStdGen
--           print g
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
--           g <- newStdGen
--           print (randomInt g 10)
