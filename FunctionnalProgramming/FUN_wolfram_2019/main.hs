--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- main
--

import System.Environment
import System.Exit

import CheckArgsStart

import Launch

print_usage :: IO ()
print_usage = do putStr "./wolfram  -rule rule_number [Option1] [value1] ...\n\n"
                 putStr "OPTIONS:\n"
                 putStr "    -rule : the ruleset to use (no default value, mandatory)\n"
                 putStr "    -start : the generation number at which to start the display. The default value is 0\n"
                 putStr "    -lines : the number of lines to display. When homited, the program never stops\n"
                 putStr "    -window : the number of cells to display on each line (line width). If even,\n"
                 putStr "    -window : the number of cells to display on each line (line width). If even,\n"
                 putStr "    the central cell is display in the next cell on the right. The default value is 80\n"
                 putStr "    -move : a translation to apply on the window. If negative, the window is translated to the left.\n"
                 putStr "    If positive, it’s translated to the right.\n"

main = do args <- getArgs
          if checkArgsStart args == True then launch args (-1) (-1) 1 80 0
          else do putStr "An error happend, check the usage below !\n\n"
                  print_usage
                  exitWith (ExitFailure 84)


-- pas print si on est pas dans l'intervale de la window