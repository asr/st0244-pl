
# You can define "local" variables in the `../mk/config.mk` file which
# is .gitignored.
ifneq ($(wildcard ../mk/config.mk),)
include ../mk/config.mk
endif

# We need the auxiliar variable `CXX_AUX` because `CXX` is predefined
# by `make`.
ifdef CXX_AUX
CXX := $(CXX_AUX)
endif

# We need the auxiliar variable `CXXFLAGS_AUX` because `CXXFLAGS` is
# predefined by `make`.
ifdef CXXFLAGS_AUX
CXXFLAGS := $(CXXFLAGS_AUX)
endif

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
	$(CXX) -o $@ $<

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

clean very-clean :
	rm -f *.hi
	rm -f *.o
	find . -type f -executable -delete
