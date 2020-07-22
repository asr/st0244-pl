
module AST where

-- Adapted from Fig. 5.12 in Kent D. Lee (2017), Foundations of
-- Programming Languages, 2nd ed.

-- Abstract syntax trees for expressions in a calculator with one
-- memory location.
data AST = Add AST AST
         | Sub AST AST
         | Prod AST AST
         | Div AST AST
         | Negate AST
         | Integer Int
         | Store AST
         | Recall

-- Examples expressions.
e1 :: AST
e1 = Add (Store (Negate (Integer 6))) Recall

e2 :: AST
e2 = Add (Store $ Negate $ Integer 6) Recall
