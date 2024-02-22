
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

JAVAFLAGS := -Xlint -Werror

.DEFAULT_GOAL := all

all : BoxingUnboxing \
      CLI \
      cli \
      exceptions \
      function-overloading \
      multiple-inheritance \
      pointers-and-references \
      polymorphism \
      signal-handling \
      vector
	$(MAKE) -C java-multiple-inheritance/interfaces
	$(MAKE) -C java-multiple-inheritance/classes
	$(MAKE) -C sistema-cuentas-bancarias/c-plusplus
	ant -buildfile sistema-cuentas-bancarias/java/build.xml compile
	$(MAKE) -C templates

##############################################################################
# C++

cli : cli.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

exceptions : exceptions.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

function-overloading : function-overloading.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

multiple-inheritance : multiple-inheritance.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

pointers-and-references : pointers-and-references.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

polymorphism : polymorphism.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

signal-handling : signal-handling.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

toy-accounting-system : toy-accounting-system.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

vector : vector.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

# Generate two warnings.
warning : warning.cc
	$(CXX) $(CXXFLAGS) \
        -Wno-error=unused-parameter -Wno-error=uninitialized \
        -o $@ $<

##############################################################################
# Java

CLI : CLI.java
	javac $(JAVAFLAGS) $<

# Generate a warning.
BoxingUnboxing : BoxingUnboxing.java
	javac $<

Polymorphism : Polymorphism.java
	javac $(JAVAFLAGS) $<

# Generate a warning.
Warning : Warning.java
	javac -Xlint $<

##############################################################################

clean very-clean :
	find . -type f -executable -delete
	rm -f *.class
	$(MAKE) -C java-multiple-inheritance/interfaces very-clean
	$(MAKE) -C java-multiple-inheritance/classes very-clean
	$(MAKE) -C sistema-cuentas-bancarias/c-plusplus very-clean
	ant -buildfile sistema-cuentas-bancarias/java/build.xml clean
	$(MAKE) -C templates very-clean
