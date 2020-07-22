JFLAGS := -Xlint -Werror

.DEFAULT_GOAL := all

all : ClassA.java \
      ClassB.java \
      ClassCAdapter.java \
      InterfaceA.java \
      InterfaceB.java \
      InterfaceC.java \
      SuperClass.java \
      WrongClassC.java
	javac $(JFLAGS) $?

clean :
	rm -f *.class
