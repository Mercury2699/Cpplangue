CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror -g

main: main.o book.o textbook.o comic.o
	${CXX} ${CXXFLAGS} main.o book.o textbook.o comic.o -o main

main.o: main.cc book.h textbook.h comic.h
	${CXX} ${CXXFLAGS} -c main.cc

book.o: book.h book.cc
	${CXX} ${CXXFLAGS} -c book.cc

textbook.o: textbook.h textbook.cc book.h
	${CXX} ${CXXFLAGS} -c textbook.cc

comic.o: comic.h comic.cc book.h
	${CXX} ${CXXFLAGS} -c comic.cc

.PHONY: clean
clean:
	rm *.o main
