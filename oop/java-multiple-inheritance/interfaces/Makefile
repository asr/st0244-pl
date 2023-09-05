JAVAFLAGS := -Xlint -Werror

.DEFAULT_GOAL := InterfacesImpl.class

%.class : %.java
	javac $(JAVAFLAGS) $<

InterfacesImpl.class : InterfaceA.class \
                       InterfaceB.class \
                       InterfaceC.class
	javac $(JAVAFLAGS) InterfacesImpl.java

run : InterfacesImpl.class
	java InterfacesImpl

clean very-clean :
	rm -f *.class
