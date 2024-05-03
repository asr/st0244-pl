
import Numeric.Natural ( Natural )

-- Very inefficient version.
fib :: Natural -> Natural
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

main :: IO ()
main = print $ fib 42
