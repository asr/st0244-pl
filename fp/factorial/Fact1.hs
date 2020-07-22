module Main ( main ) where

import Numeric.Natural ( Natural )

-- Non-tail recursive version.
fact :: Natural -> Natural
fact 0 = 1
fact n = n * fact (n - 1)

main :: IO ()
main = print $ fact 200000
