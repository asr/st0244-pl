
import Numeric.Natural ( Natural )

-- Accumulator pattern version. Adapted from Fig. 5.17 in Kent D. Lee
-- (2017), Foundations of Programming Languages, 2nd ed.
fib :: Natural -> Natural
fib n =
  let helper :: Natural -> Natural -> Natural -> Natural
      helper count current previous =
        if count == n then previous
        else helper (count + 1) (current + previous) current
  in  helper 0 1 0

main :: IO ()
main = print $ fib 42
