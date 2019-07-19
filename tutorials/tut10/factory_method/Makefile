CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = pizza
OBJECTS = main.o pizza.o crustandsauce.o topping.o dippingsauce.o stuffedcrust.o decorator.o pizzaFactory.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
