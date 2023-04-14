
import Numeric.Natural ( Natural )

-- Very inefficient version.
fib :: Natural -> Natural
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

-- Accumulator pattern version. Adapted from Fig. 5.17 in Kent D. Lee
-- (2017), Foundations of Programming Languages, 2nd ed.
fibAP :: Natural -> Natural
fibAP n =
  let fibHelper :: Natural -> Natural -> Natural -> Natural
      fibHelper count current previous =
        if count == n then previous
        else fibHelper (count + 1) (previous + current) current
  in  fibHelper 0 1 0

main :: IO ()
main = print $ fibAP 42
