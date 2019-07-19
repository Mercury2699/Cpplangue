CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = linkedList
OBJECTS = main.o linkedList.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
