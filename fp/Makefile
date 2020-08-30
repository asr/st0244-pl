
ifneq ("$(wildcard /usr/bin/g++-9)","")
	CXX := g++-9
else
	CXX := g++
endif

CXXFLAGS   := -Wall -Wextra
CXX11FLAGS := -Wall -Wextra -std=c++11
GHCFLAGS  := -Wall -Werror

.DEFAULT_GOAL := all

all : constexpr \
      fibonacci-static \
      fibonacci-dynamic \
      quickcheck-static \
      quickcheck-dynamic \
      side-effects1 \
      side-effects2
	ghc $(GHCFLAGS) AST.hs
	ghc $(GHCFLAGS) HigherOrder.hs
	ghc $(GHCFLAGS) LetWhere.hs
	ghc $(GHCFLAGS) Tuples.hs
	$(MAKE) -C factorial

side-effects1 : side-effects1.pas
	fpc -vew $<

side-effects2 : side-effects2.cc
	$(CXX) $<

constexpr : constexpr.cc
	$(CXX) $(CXX11FLAGS) $<

fibonacci-static : Fibonacci.hs
	ghc -Wall -o fibonacci $<

fibonacci-dynamic : Fibonacci.hs
	ghc -dynamic -Wall -o fibonacci $<

quickcheck-static : QuickCheck.hs
	ghc $(GHCFLAGS) -o quickcheck $<

quickcheck-dynamic : QuickCheck.hs
	ghc -dynamic \
            -package QuickCheck \
            -package quickcheck-instances \
            $(GHCFLAGS) -o quickcheck $<

clean :
	rm -f *.hi
	rm -f *.o
	rm -f a.out
	rm -f fibonacci
	rm -f quickcheck
	rm -f side-effects1
