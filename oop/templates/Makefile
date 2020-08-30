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

vector-structure : vector-structure.cc
	$(CXX) $(CXXFLAGS) $<

vector-class : vector-class.cc
	$(CXX) $(CXXFLAGS) $<

vector-template : vector-template.cc
	$(CXX) $(CXXFLAGS) $<

clean :
	rm -f a.out
