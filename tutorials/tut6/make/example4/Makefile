CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror -g
EXEC = main
OBJECTS = main.o book.o textbook.o comic.o

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

main.o: main.cc book.h textbook.h comic.h

book.o: book.h book.cc

textbook.o: textbook.h textbook.cc book.h

comic.o: comic.h comic.cc book.h

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC}
