
module Tuples where

-- Concatenation of lists using currying.
appendC :: [a] -> [a] -> [a]
appendC []       ys = ys
appendC (x : xs) ys = x : appendC xs ys

-- Concatenation of lists using tuples.
appendT :: ([a], [a]) -> [a]
appendT ([], ys)       = ys
appendT ((x : xs), ys) = x : appendT (xs, ys)
