--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Algorithme
--

module Algorithme where

import Lib

import Clusters
import Centroides
import Limits
import Prints


algorithme :: Int -> Double -> [[Int]] -> [[Double]] -> [Int] -> IO ()
algorithme n e points centroides clusters = do let tmpCentroide = (reCenterCentroides points clusters 0 n)
                                               if ((isLimitCrossed centroides tmpCentroide e 0 n) == False ) then printResult points clusters 0 n else putStr ""
                                               let tmpClusters = (searchClusters points centroides)
                                               if (tmpClusters == clusters) then printResult points clusters 0 n else algorithme n e points tmpCentroide tmpClusters
