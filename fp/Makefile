
ifneq ("$(wildcard /usr/bin/g++-9)","")
	CXX := g++-9
else
	CXX := g++
endif

CXX_FLAGS   := -Wall -Wextra
CXX11_FLAGS := -Wall -Wextra -std=c++11
GHC_FLAGS   := -Wall -Werror

.DEFAULT_GOAL := all

all : constexpr \
      fibonacci-static \
      fibonacci-dynamic \
      quickcheck-static \
      quickcheck-dynamic \
      side-effects1 \
      side-effects2
	ghc $(GHC_FLAGS) AST.hs
	ghc $(GHC_FLAGS) HigherOrder.hs
	ghc $(GHC_FLAGS) LetWhere.hs
	ghc $(GHC_FLAGS) Tuples.hs
	$(MAKE) -C factorial

side-effects1 : side-effects1.pas
	fpc -vew $<

side-effects2 : side-effects2.cpp
	$(CXX) $<

constexpr : constexpr.cpp
	$(CXX) $(CXX11_FLAGS) $<

fibonacci-static : Fibonacci.hs
	ghc -Wall -o fibonacci $<

fibonacci-dynamic : Fibonacci.hs
	ghc -dynamic -Wall -o fibonacci $<

quickcheck-static : QuickCheck.hs
	ghc $(GHC_FLAGS) -o quickcheck $<

quickcheck-dynamic : QuickCheck.hs
	ghc -dynamic \
            -package QuickCheck \
            -package quickcheck-instances \
            $(GHC_FLAGS) -o quickcheck $<

clean :
	rm -f *.hi
	rm -f *.o
	rm -f a.out
	rm -f fibonacci
	rm -f quickcheck
	rm -f side-effects1
