--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Clusters
--

module Clusters where

import Lib

distanceCls :: (Int, Int, Int) -> (Double, Double, Double) -> Double
distanceCls (a,b,c) (d,e,f) = sqrt ((myPowD ((fromIntegral a) - d) 2) + (myPowD ((fromIntegral b) - e) 2) + (myPowD ((fromIntegral c) - f) 2))

clusterDistance :: (Int, Int, Int) -> [Double] -> Int -> (Double, Int)
clusterDistance (a,b,c) tab index = (distanceCls (a,b,c) ((myNth tab 2),(myNth tab 3),(myNth tab 4)),index)

isDistLower :: (Double, Int) -> (Double, Int) -> Bool
isDistLower (dOne,iOne) (dTwo,iTwo)
    | dOne < dTwo = True
    | otherwise = False

closestCluster :: (Int, Int, Int) -> [[Double]] -> Int -> (Double, Int) -> Int
closestCluster (a,b,c) [] index (closest,i) = i
closestCluster (a,b,c) (x:xs) index (closest,i) = do let new = clusterDistance (a,b,c) x index
                                                     if (isDistLower new (closest, i)) then closestCluster (a,b,c) xs (index + 1) new else closestCluster (a,b,c) xs (index + 1) (closest,i)

searchClusters :: [[Int]] -> [[Double]] -> [Int]
searchClusters [] centroides = []
searchClusters (x:xs) centroides = do let tmp = (clusterDistance (myNth x 2, myNth x 3, myNth x 4) (head centroides) 0)
                                      (closestCluster (myNth x 2, myNth x 3, myNth x 4) (tail centroides) 1 (tmp)):(searchClusters xs centroides)