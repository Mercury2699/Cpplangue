CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q5
OBJECTS = main.o cell.o grid.o textdisplay.o window.o gui.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}




