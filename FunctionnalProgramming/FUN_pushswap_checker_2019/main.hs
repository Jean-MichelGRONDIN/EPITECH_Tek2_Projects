import System.Environment
import System.Exit

import PushswapChecker
import CheckArgs

main = do args <- getArgs
          if length args /= 0 && checkArgs args == True then pushswapChecker args
          else exitWith (ExitFailure 84)