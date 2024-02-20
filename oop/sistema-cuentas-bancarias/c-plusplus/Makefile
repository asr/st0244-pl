
# You can define "local" variables in the `../mk/config.mk` file which
# is .gitignored.
ifneq ($(wildcard ../../../mk/config.mk),)
include ../../../mk/config.mk
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

scb : scb.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

clean very-clean :
	find . -type f -executable -delete
