--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- print_lines
--

module Print_that_line where

putChar_if_can :: Char -> Int -> IO ()
putChar_if_can c window = putChar c

print_n_time :: Int -> Char -> Int -> IO ()
print_n_time 1 c window = putChar_if_can c window
print_n_time nb c window
    | nb > 1 = do putChar_if_can c window
                  print_n_time (nb - 1) c window
    | otherwise = putStr ""

print_tab :: [Bool] -> Int -> IO ()
print_tab tab window
    | length tab == 1  = if (head tab) == True then putChar_if_can '*' window else putChar_if_can ' ' window
    | otherwise = do if (head tab) == True then putChar_if_can '*' window else putChar_if_can ' ' window
                     print_tab (tail tab) window

-- shrink_tab :: [Bool] -> Int -> [Bool]
-- shrink_tab tab n = do

print_that_line :: Int -> Int -> Int -> Int -> [Bool] -> IO ()
print_that_line 1 linemax window move tab = putStr ""
print_that_line n linemax window move tab = do if ((((window) + 2 - ((1 + 2 * n))) `div` 2) + 1) > 0 then print_n_time ((((window) + 2 - ((1 + 2 * n))) `div` 2) + move + 1) ' ' window else putStr""
                                               if (length tab - window) <= 0 then print_tab tab window else print_tab (reverse (drop ((length tab - window) `div` 2 + 1) (reverse (drop ((length tab - window) `div` 2) tab)))) window
                                               if ((((window) + 2 - ((1 + 2 * n))) `div` 2)) > 0 then print_n_time ((((window) + 2 - ((1 + 2 * n))) `div` 2) + move) ' ' window else putStr ""
                                               putChar '\n'