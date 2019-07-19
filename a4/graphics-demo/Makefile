CXX=g++
CXXFLAGS=-std=c++14 -MMD 
OBJECTS=window.o graphicsdemo.o
DEPENDS = ${OBJECTS:.o=.d} 
EXEC=graphicsdemo

.PHONY: clean

${EXEC} : ${OBJECTS} # link step
	${CXX} ${CXXFLAGS} -o $@ -lX11

-include ${DEPENDS} # include *.d files containing program dependences

clean : # remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

