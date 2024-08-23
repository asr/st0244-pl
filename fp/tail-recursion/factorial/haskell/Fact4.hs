
{-# LANGUAGE BangPatterns #-}

module Main ( main ) where

import Numeric.Natural ( Natural )

-- Tail recursive and bang patterns.
fact :: Natural -> Natural
fact n = go n 1
  where
  go :: Natural -> Natural -> Natural
  go 0  prod  = prod
  go m  !prod = go (m - 1) (prod * m)

main :: IO ()
main = print $ fact 200000
