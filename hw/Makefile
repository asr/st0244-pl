
CFLAGS   := -Wall -Wextra -Werror
CXXFLAGS := $(CFLAGS)

file := hello-world

all : asm c c-plus-plus java python prolog scheme sml

asm : $(file).asm
	nasm -f elf $<
	ld -m elf_i386 -o $(file) $(file).o

c : $(file).c
	clang $(CFLAGS) -fsyntax-only $<
	gcc $(CFLAGS) -o hello-world $<

c-plus-plus : $(file).cc
	clang++ $(CXXFLAGS) -fsyntax-only $<
	g++ $(CXXFLAGS) -o hello-world $<

java : HelloWorld.java
	javac -Xlint -Werror $<

python : $(file).py
	python3 -Werror $<

prolog : $(file).pl
	swipl $<

scheme : $(file).scm
	mit-scheme --quiet < $<

smalltalk : $(file).st
	gst $<

sml : $(file).sml
	mlton $<

##############################################################################

clean very-clean :
	find . -type f -executable -delete
	rm -f *.class
