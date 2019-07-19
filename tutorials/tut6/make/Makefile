# Change the name of EXEC to your executable
EXEC = main
CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
SOURCES = ${wildcard *.cc}
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

