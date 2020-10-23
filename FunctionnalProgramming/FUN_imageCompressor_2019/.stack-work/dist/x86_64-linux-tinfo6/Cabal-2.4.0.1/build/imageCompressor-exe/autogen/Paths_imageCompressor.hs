{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_imageCompressor (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/jean-michel/stock/delivery/tek2/functional_programming/FUN_imageCompressor_2019/.stack-work/install/x86_64-linux-tinfo6/debb26e7f3083491a870c9e13e1b5653fa1f42e3d633c40922c9a507387e3253/8.6.5/bin"
libdir     = "/home/jean-michel/stock/delivery/tek2/functional_programming/FUN_imageCompressor_2019/.stack-work/install/x86_64-linux-tinfo6/debb26e7f3083491a870c9e13e1b5653fa1f42e3d633c40922c9a507387e3253/8.6.5/lib/x86_64-linux-ghc-8.6.5/imageCompressor-0.1.0.0-B1BNViBTqzCdAdU3SAkPm-imageCompressor-exe"
dynlibdir  = "/home/jean-michel/stock/delivery/tek2/functional_programming/FUN_imageCompressor_2019/.stack-work/install/x86_64-linux-tinfo6/debb26e7f3083491a870c9e13e1b5653fa1f42e3d633c40922c9a507387e3253/8.6.5/lib/x86_64-linux-ghc-8.6.5"
datadir    = "/home/jean-michel/stock/delivery/tek2/functional_programming/FUN_imageCompressor_2019/.stack-work/install/x86_64-linux-tinfo6/debb26e7f3083491a870c9e13e1b5653fa1f42e3d633c40922c9a507387e3253/8.6.5/share/x86_64-linux-ghc-8.6.5/imageCompressor-0.1.0.0"
libexecdir = "/home/jean-michel/stock/delivery/tek2/functional_programming/FUN_imageCompressor_2019/.stack-work/install/x86_64-linux-tinfo6/debb26e7f3083491a870c9e13e1b5653fa1f42e3d633c40922c9a507387e3253/8.6.5/libexec/x86_64-linux-ghc-8.6.5/imageCompressor-0.1.0.0"
sysconfdir = "/home/jean-michel/stock/delivery/tek2/functional_programming/FUN_imageCompressor_2019/.stack-work/install/x86_64-linux-tinfo6/debb26e7f3083491a870c9e13e1b5653fa1f42e3d633c40922c9a507387e3253/8.6.5/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "imageCompressor_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "imageCompressor_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "imageCompressor_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "imageCompressor_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "imageCompressor_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "imageCompressor_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
