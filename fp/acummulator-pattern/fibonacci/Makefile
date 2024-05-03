
GHC_FLAGS := -Wall -Werror

.DEFAULT_GOAL := all

all : fib1 fib2

fib% : Fib%.hs
	ghc $(GHC_FLAGS) -o fib$* $<

clean very-clean :
	rm -f *.hi
	rm -f *.o
	find . -type f -executable -delete
