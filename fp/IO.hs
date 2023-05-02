
module IO where

-- Adapted from Section 10.1 of "Bird, Richard [1988]
-- (1998). Introduction to Functional Programming. 2nd ed. Prentice
-- Hall Press."

-- The type `IO a` is an abstract type with (at least) the following
-- operations:
--
-- return  :: a —> IO a
-- (>>=)   :: IO a -> (a -> IO b) -> IO b
-- putChar :: Char - IO ()
-- getChar :: IO Char

import Numeric.Natural ( Natural )

-- The funtion `done` does nothing.
done :: IO ()
done = return ()

-- Combine two actions.
-- (>>) :: IO () -> IO () -> IO ()
-- m >> k = m >>= \_ -> k

-- Prints a string (Haskell function `putStr`).
write :: String -> IO ()
write []       = done
write (c : cs) = putChar c >> write cs

-- Prints a string and a newline character after it. (Haskell function
-- `putStrLn`).
writeLn :: String -> IO()
writeLn cs = write cs >> putChar '\n'

-- Read a fixed number of characters from the keyboard.
readn :: Natural -> IO String
readn n = if n == 0
  then return []
  else getChar >>= q
    where
    q :: Char -> IO String
    q c = readn (n - 1) >>= r
      where
      r :: String -> IO String
      r cs = return (c : cs)

-- Read a line from the keyboard (Haskell function `getLine`).
readLn1 :: IO String
readLn1 = getChar >>= q
  where
  q :: Char -> IO String
  q c = if c == '\n'
          then return []
          else readLn1 >>= r
            where
            r :: String -> IO String
            r cs = return (c : cs)
