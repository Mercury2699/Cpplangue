CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q2
OBJECTS = main.o variable.o number.o binop.o unop.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}




