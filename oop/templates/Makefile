
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

CXXFLAGS := $(CXXFLAGS) -std=c++11

.DEFAULT_GOAL := all

all : vector-structure \
      vector-class \
      vector-template

vector-structure : vector-structure.cc
	$(CXX) $(CXXFLAGS) $<

vector-class : vector-class.cc
	$(CXX) $(CXXFLAGS) $<

vector-template : vector-template.cc
	$(CXX) $(CXXFLAGS) $<

clean :
	rm -f a.out
