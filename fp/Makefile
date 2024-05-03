
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
      side-effect-state-c-plusplus \
      side-effect-state-pascal \
      side-effect-undefined-operation
	ghc $(GHCFLAGS) AST.hs
	ghc $(GHCFLAGS) CPS.hs
	ghc $(GHCFLAGS) IO.hs
	ghc $(GHCFLAGS) HigherOrder.hs
	ghc $(GHCFLAGS) LetWhere.hs
	ghc $(GHCFLAGS) Reverse.hs
	ghc $(GHCFLAGS) Tuples.hs
	$(MAKE) -C acummulator-pattern/fibonacci
	$(MAKE) -C tail-recursion/factorial

side-effect-state-c-plusplus : side-effect-state-c-plusplus.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

side-effect-state-pascal : side-effect-state-pascal.pas
	fpc -vwnh -Sewnh $<

side-effect-undefined-operation : side-effect-undefined-operation.cc
	$(CXX) -o $@ $<

clean very-clean :
	rm -f *.hi
	rm -f *.o
	find . -type f -executable -delete
