
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

GHCFLAGS := -Wall -Werror

.DEFAULT_GOAL := all

all : constexpr \
      fibonacci-static \
      fibonacci-dynamic \
      quickcheck-static \
      quickcheck-dynamic \
      side-effect-state-c-plus-plus \
      side-effect-state-pascal \
      side-effect-undefined-operation
	ghc $(GHCFLAGS) AST.hs
	ghc $(GHCFLAGS) CPS.hs
	ghc $(GHCFLAGS) IO.hs
	ghc $(GHCFLAGS) HigherOrder.hs
	ghc $(GHCFLAGS) LetWhere.hs
	ghc $(GHCFLAGS) Reverse.hs
	ghc $(GHCFLAGS) Tuples.hs
	$(MAKE) -C factorial

side-effect-state-c-plus-plus : side-effect-state-c-plus-plus.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

side-effect-state-pascal : side-effect-state-pascal.pas
	fpc -vwnh -Sewnh $<

side-effect-undefined-operation : side-effect-undefined-operation.cc
	$(CXX) -o $@ $<

fibonacci-static : Fibonacci.hs
	ghc -Wall -o fibonacci $<

fibonacci-dynamic : Fibonacci.hs
	ghc -dynamic -Wall -o fibonacci $<

quickcheck-static : QuickCheck.hs
	stack ghc --  $< $(GHCFLAGS) -o quickcheck

quickcheck-dynamic : QuickCheck.hs
	stack ghc -- $< -dynamic $(GHCFLAGS) -o quickcheck

clean very-clean :
	rm -f *.hi
	rm -f *.o
	find . -type f -executable -delete
