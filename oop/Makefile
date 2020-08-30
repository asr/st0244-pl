
ifneq ("$(wildcard /usr/bin/g++-9)","")
	CXX := g++-9
else
	CXX := g++
endif

CXXFLAGS   := -Wall -Wextra -Werror
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
	javac $(JAVAFLAGS) $<

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
