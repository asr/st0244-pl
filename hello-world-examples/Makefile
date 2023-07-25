
file := hello-world

c : $(file).c
	gcc -Wall -Wextra -Werror -o hello-world $<

c-plus-plus : $(file).cc
	g++ -Wall -Wextra -Werror -o hello-world $<

java : HelloWorld.java
	javac -Xlint -Werror $<

python : $(file).py
	python3 -Werror $<

prolog : $(file).pl
	swipl $<

sml : $(file).sml
	mlton $<

##############################################################################

clean very-clean :
	find . -type f -executable -delete
	rm -f *.class

