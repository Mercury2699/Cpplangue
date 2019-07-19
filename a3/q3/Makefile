CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = canvas
OBJECTS = a3q3.o canvas.o rectangle.o point.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
