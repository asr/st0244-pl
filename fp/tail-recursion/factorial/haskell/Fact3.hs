
module Main ( main ) where

import Numeric.Natural ( Natural )

-- Tail recursive but not bang patterns.
fact :: Natural -> Natural
fact n = go n 1
  where
  go :: Natural -> Natural -> Natural
  go 0 y = y
  go x y = go (x - 1) (x * y)

main :: IO ()
main = print $ fact 200000
