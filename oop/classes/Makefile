ifneq ("$(wildcard /usr/bin/g++-9)","")
	CXX := g++-9
else
	CXX := g++
endif

CXXFLAGS := -Wall -Wextra -Werror -std=c++11

.DEFAULT_GOAL := all

all : vector1 \
      vector2

vector1 : vector1.cpp
	$(CXX) $(CXXFLAGS) $<

vector2 : vector2.cpp
	$(CXX) $(CXXFLAGS) $<

clean :
	rm -f a.out
