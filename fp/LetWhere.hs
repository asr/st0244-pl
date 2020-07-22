
module LetWhere where

-- Adapted from Fig. 5.9 in Kent D. Lee (2017), Foundations of
-- Programming Languages, 2nd ed.

import Numeric.Natural ( Natural )

sumUpTo :: Natural -> Natural
sumUpTo 0 = 0
sumUpTo n = n + sumUpTo (n - 1)

sumUpToL :: Natural -> Natural
sumUpToL 0 = 0
sumUpToL n =
  let sumHelper :: Natural
      sumHelper = sumUpToL (n - 1)
  in n + sumHelper

sumUpToW :: Natural -> Natural
sumUpToW 0 = 0
sumUpToW n = n + sumHelper
  where
    sumHelper :: Natural
    sumHelper = sumUpToW (n - 1)
