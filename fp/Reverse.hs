
module Reverse where

-- Reverse of a list using append.
reverse1 :: [a] -> [a]
reverse1 []       = []
reverse1 (x : xs) = reverse1 xs ++ [x]

-- Reverse of a list using the accumulator pattern.
reverse2 :: [a] -> [a]
reverse2 xs = rev xs []
  where
  rev :: [a] -> [a] -> [a]
  rev []       zs = zs
  rev (y : ys) zs = rev ys (y : zs)
