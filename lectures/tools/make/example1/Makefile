myprogram: main.o list.o iter.o node.o
	g++ -std=c++14 main.o list.o iter.o node.o -o myprogram

list.o: list.cc list.h node.h
	g++ -std=c++14 -c list.cc

node.o: node.cc node.h list.h
	g++ -std=c++14 -c node.cc

iter.o: iter.cc list.h node.h
	g++ -std=c++14 -c iter.cc

main.o: main.cc list.h
	g++ -std=c++14 -c main.cc
