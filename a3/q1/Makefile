CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = plan
OBJECTS = a3q1.o plan.o call.o date.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

