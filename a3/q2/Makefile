CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = emailgroups
OBJECTS = a3q2.o group.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
