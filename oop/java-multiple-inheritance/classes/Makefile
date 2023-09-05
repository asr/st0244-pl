JAVAFLAGS := -Xlint -Werror

.DEFAULT_GOAL := WrongClassC.class

%.class : %.java
	javac $(JAVAFLAGS) $<

WrongClassC.class : ClassA.class \
	            ClassB.class
	javac $(JAVAFLAGS) WrongClassC.java

run : WrongClassC.class
	java WrongClassC

clean very-clean :
	rm -f *.class
