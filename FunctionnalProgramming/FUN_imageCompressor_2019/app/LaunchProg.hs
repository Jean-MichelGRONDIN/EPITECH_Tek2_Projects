--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- LaunchProg
--

module LaunchProg where

import Lib
import System.Random

import Clusters
import Algorithme

import Control.Exception

getRandomsVals :: Int -> Double -> [[Int]] -> StdGen -> [[Double]] -> IO ()
getRandomsVals n e tab g centroides
    | length centroides /= n = do g <- newStdGen
                                  let i = randomInt g ((length tab) - 1)
                                  let tmp = myNth tab i
                                  getRandomsVals n e tab g (uniqueTabVal (((fromIntegral (myNth tmp 0)):(fromIntegral (myNth tmp 1)):(fromIntegral (myNth tmp 2)):(fromIntegral (myNth tmp 3)):(fromIntegral (myNth tmp 4)):[]):centroides))
    | otherwise = algorithme n e tab centroides (searchClusters tab centroides)

initSeed :: Int -> Double -> [[Int]] -> IO ()
initSeed n e tab = do g <- newStdGen
                      getRandomsVals n e tab g []

checkColorRange :: [Int] -> IO ()
checkColorRange tab
    | myNth tab 2 < 0 || myNth tab 2 > 255 = exitError "Error in file : colors are from 0 to 255 !"
    | myNth tab 3 < 0 || myNth tab 3 > 255 = exitError "Error in file : colors are from 0 to 255 !"
    | myNth tab 4 < 0 || myNth tab 4 > 255 = exitError "Error in file : colors are from 0 to 255 !"
    | otherwise = putStr ""

linesToInts :: Int -> Double -> [String] -> [[Int]] -> IO ()
linesToInts n e [] res = initSeed n e (reverse res)
linesToInts n e (x:xs) res = do let tmp = strToIntArray x []
                                checkColorRange tmp
                                linesToInts n e xs (tmp:res)

checkFile :: Int -> Double -> [String] -> IO ()
checkFile n e file
    | length file == 0 = exitError "Error file is empty !"
    | length file < n = exitError "Error n is greater than the number of point in the file !"
    | otherwise = linesToInts n e file []

launchProg :: Int -> Double -> String -> IO ()
launchProg n e path = do strOrExc <- try (readFile path) :: IO (Either SomeException String)
                         case strOrExc of
                              Left except -> exitError "Error cannot open file !"
                              Right contents -> do let fileLines = lines contents
                                                   checkFile n e (clearTab fileLines)

