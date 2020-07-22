
ifneq ("$(wildcard /usr/bin/g++-9)","")
	CXX := g++-9
else
	CXX := g++
endif

CXX_FLAGS   := -Wall -Wextra -Werror
CXX11_FLAGS := $(CXX_FLAGS) -std=c++11
JAVA_FLAGS  := -Xlint -Werror

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
	javac $(JAVA_FLAGS) $<

exceptions : exceptions.cpp
	$(CXX) $(CXX11_FLAGS) $<

function-overloading : function-overloading.cpp
	$(CXX) $(CXX_FLAGS) $<

pointers-and-references : pointers-and-references.cpp
	$(CXX) $(CXX11_FLAGS) $<

polymorphism : polymorphism.cpp
	$(CXX) $(CXX_FLAGS) $<

signal-handling : signal-handling.cpp
	$(CXX) $(CXX_FLAGS) $<

clean :
	rm -f a.out
