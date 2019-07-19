CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q3
OBJECTS = main.o exception.o ppm.o image.o basic.o transform.o sepia.o rotate.o flip.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}




