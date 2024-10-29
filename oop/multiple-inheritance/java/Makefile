JAVAFLAGS := -Xlint -Werror

.DEFAULT_GOAL := ClassD.class

%.class : %.java
	javac $(JAVAFLAGS) $<

ClassD.class : ClassD.java \
               InterfaceA.class \
               InterfaceB.class \
               InterfaceC.class \
               InterfaceD.class
	javac $(JAVAFLAGS) $<

run : ClassD.class
	java ClassD

clean very-clean :
	rm -f *.class
