
-- Tested QuickCheck 2.13.2 and quickcheck-instances 0.3.22.

import Numeric.Natural ( Natural )

import Test.QuickCheck
  ( classify
  , collect
  , Property
  , quickCheck
  )

import Test.QuickCheck.Instances.Natural ()

-- Non-tail recursive version.
factorial :: Natural -> Natural
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- Tail recursive version. Adapted from Fig. 5.19 in Kent D. Lee
-- (2017), Foundations of Programming Languages, 2nd ed.
factorialTR :: Natural -> Natural
factorialTR n = facHelper n 1
  where
  facHelper :: Natural -> Natural -> Natural
  facHelper 0 prod = prod
  facHelper m prod = facHelper (m - 1) (prod * m)

------------------------------------------------------------------------------
-- QuickCheck tests [1].

-- [1] Koen Claessen and John Hughes. QuickCheck: A lightweight tool
-- for random testing of Haskell Programs. ICFP '00.

-- Properties

prop_p1 :: Natural -> Bool
prop_p1 n = factorial n == factorialTR n

prop_p2 :: Natural -> Property
prop_p2 n = classify (n == 0) "trivial" $ prop_p1 n

prop_p3 :: Natural -> Property
prop_p3 n = collect n $ prop_p1 n

------------------------------------------------------------------------------

main :: IO ()
main = do
  quickCheck prop_p1
  quickCheck prop_p2
  quickCheck prop_p3
