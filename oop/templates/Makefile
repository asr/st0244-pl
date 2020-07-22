ifneq ("$(wildcard /usr/bin/g++-9)","")
	CXX := g++-9
else
	CXX := g++
endif

CXXFLAGS := -Wall -Wextra -Werror -std=c++11

.DEFAULT_GOAL := all

all : vector-structure \
      vector-class \
      vector-template

vector-structure : vector-structure.cpp
	$(CXX) $(CXXFLAGS) $<

vector-class : vector-class.cpp
	$(CXX) $(CXXFLAGS) $<

vector-template : vector-template.cpp
	$(CXX) $(CXXFLAGS) $<

clean :
	rm -f a.out
