main: book.o main.o textbook.o comic.o
	g++-5 -std=c++14 main.o book.o textbook.o comic.o -o main

book.o: book.h book.cc
	g++-5 -std=c++14 -c book.cc

textbook.o: textbook.h textbook.cc book.h
	g++-5 -std=c++14 -c textbook.cc

comic.o: comic.h comic.cc book.h
	g++-5 -std=c++14 -c comic.cc

main.o: main.cc book.h textbook.h comic.h
	g++-5 -std=c++14 -c main.cc
