JAVAFLAGS := -Xlint -Werror

.DEFAULT_GOAL := all

all : ClassA.java \
      ClassB.java \
      ClassCAdapter.java \
      InterfaceA.java \
      InterfaceB.java \
      InterfaceC.java \
      SuperClass.java \
      WrongClassC.java
	javac $(JAVAFLAGS) $?

clean very-clean :
	rm -f *.class
