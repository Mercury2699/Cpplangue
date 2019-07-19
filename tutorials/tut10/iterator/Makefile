CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -MMD
EXEC = Iterator
OBJECTS = main.o listiter.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
