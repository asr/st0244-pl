
module HigherOrder where

------------------------------------------------------------------------------
-- Composition examples

add1 :: Int -> Int
add1 n = n + 1

sqr :: Int -> Int
sqr n = n * n

incsqr :: Int -> Int
incsqr = add1 . sqr

sqrinc :: Int -> Int
sqrinc = sqr . add1

------------------------------------------------------------------------------
-- map examples

-- map add1 [1,2,3]
-- [2,3,4]

-- map (\ n -> n * n - 1) [1,2,3,4,5]
-- [0,3,8,15,24]

-- map (\ ls -> "a" : ls ) [["a", "b"], ["c"], ["d", "e", "f"]]
-- [["a","a","b"],["a","c"],["a","d","e","f"]]

------------------------------------------------------------------------------
-- foldr examples

sum1 :: [Int] -> Int
sum1 []       = 0
sum1 (x : xs) = x + sum1 xs

prod1 :: [Int] -> Int
prod1 []       = 1
prod1 (x : xs) = x * prod1 xs

sumF :: [Int] -> Int
sumF xs = foldr (+) 0 xs

prodF :: [Int] -> Int
prodF xs = foldr (*) 1 xs
