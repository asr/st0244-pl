
# You can define "local" variables in the `../../mk/config.mk` file which
# is .gitignored.
ifneq ($(wildcard ../../mk/config.mk),)
include ../../mk/config.mk
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

.DEFAULT_GOAL := all

all : side-effect-state-c-plusplus \
      side-effect-state-pascal \
      side-effect-undefined-operation

side-effect-state-c-plusplus : side-effect-state-c-plusplus.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

side-effect-state-pascal : side-effect-state-pascal.pas
	fpc -vwnh -Sewnh $<

side-effect-undefined-operation : side-effect-undefined-operation.cc
	$(CXX) -o $@ $<

clean very-clean :
	$(MAKE)	-C ../ very-clean
