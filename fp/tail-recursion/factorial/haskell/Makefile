
GHC_FLAGS := -Wall -Werror

.DEFAULT_GOAL := all

all : fact1 fact2 fact3 fact4

fact% : Fact%.hs
	ghc $(GHC_FLAGS) -o fact$* $<

clean very-clean :
	rm -f *.hi
	rm -f *.o
	find . -type f -executable -delete
