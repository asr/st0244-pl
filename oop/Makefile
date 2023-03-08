
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

CXX11FLAGS := $(CXXFLAGS) -std=c++11
JAVAFLAGS  := -Xlint -Werror

.DEFAULT_GOAL := all

all : BoxingUnboxing \
      exceptions \
      function-overloading \
      pointers-and-references \
      polymorphism \
      signal-handling
	$(MAKE) -C classes
	$(MAKE) -C interfaces
	$(MAKE) -C templates

BoxingUnboxing : BoxingUnboxing.java
	javac $<

exceptions : exceptions.cc
	$(CXX) $(CXX11FLAGS) $<

function-overloading : function-overloading.cc
	$(CXX) $(CXXFLAGS) $<

pointers-and-references : pointers-and-references.cc
	$(CXX) $(CXX11FLAGS) $<

polymorphism : polymorphism.cc
	$(CXX) $(CXXFLAGS) $<

signal-handling : signal-handling.cc
	$(CXX) $(CXXFLAGS) $<

clean :
	rm -f a.out
