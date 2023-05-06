
module CPS where

-- Length of a list by pattern matching (first version).
len1 :: [a] -> Int
len1 []       = 0
len1 (_ : xs) = 1 + len1 xs

-- GHCi> len1 [3,2,1]
-- 3

-- Length of a list using CPS. The function `Int -> r` is the continuation
-- (first version).
len1CPS :: [a] -> (Int -> r) -> r
len1CPS []       k = k 0
len1CPS (_ : xs) k = len1CPS xs (\v -> k (v + 1))

-- GHCi> len1CPS [3,2,1] id
-- 3

-- len1CPS [3,2,1] id = len1CPS [2,1] (\v -> id (v + 1))
--                    = len1CPS [1] (\v' -> (\v -> id (v + 1)) (v' + 1))
--                    = len1CPS [] (\v'' -> (\v' -> (\v -> id (v + 1)) (v' + 1)) (v'' + 1))
--                    = (\v'' -> (\v' -> (\v -> id (v + 1)) (v' + 1)) (v'' + 1)) 0
--                    = (\v' -> (\v -> id (v + 1)) (v' + 1)) 1
--                    = (\v -> id (v + 1)) 2
--                    = id 3
--                    = 3

-- Length of a list by pattern matching (second version).
len2 :: [a] -> Int
len2 []       = 0
len2 (_ : xs) = succ (len2 xs)

-- GHCi> len2 [3,2,1]
-- 3

-- Length of a list using CPS (second version).
len2CPS :: [a] -> (Int -> r) -> r
len2CPS []       k = k 0
len2CPS (_ : xs) k = len2CPS xs (k . succ)

-- GHCi> len2CPS [3,2,1] id
-- 3

-- len2CPS [3,2,1] id = len2CPS [2,1] (id . succ)
--                    = len2CPS [1] (id . succ . succ)
--                    = len2CPS [] (id . succ . succ . succ)
--                    = (id . succ . succ . succ) 0
--                    = 3

-----------------------------------------------------------------------------
-- Example adapted from https://free.cofree.io/2020/01/02/cps/

-- Left-valued tree data type.
data Tree = Branch Tree Tree | Leaf Int

tree :: Tree
tree = Branch (Branch (Leaf 1) (Leaf 2))
              (Branch (Leaf 6) (Leaf 5))

-- Sums up the leaf values by pattern matching.
leafSum :: Tree -> Int
leafSum (Leaf n)       = n
leafSum (Branch tl tr) = leafSum tl + leafSum tr

-- GHCi> leafSum tree
-- 14

-- Sums up the leaf values by CPS.
leafSumCPS :: Tree -> (Int -> r) -> r
leafSumCPS (Leaf n)       k = k n
leafSumCPS (Branch tl tr) k =
  leafSumCPS tl $ \vl ->
    leafSumCPS tr $ \vr ->
      k (vl + vr)

-- GHCi> leafSumCPS tree id
-- 14

-- If any leaf’s value is 6, return 1000. Otherwise, return the
-- sum of all leaf values.
leafSumCPS6 :: Tree -> (Int -> r) -> r
leafSumCPS6 t k = go t k
  where
  -- go :: Tree -> (Int -> r) -> r
  go (Leaf 6)       _  = k 1000
  go (Leaf n)       k' = k' n
  go (Branch tl tr) k' =
    go tl $ \vl ->
      go tr $ \vr ->
        k' (vl + vr)

-- GHCi> leafSumCPS6 tree id
-- 1000
