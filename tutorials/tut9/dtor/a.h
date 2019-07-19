#ifndef A_H
#define A_H

#include <string>
#include "b.h"

class A : public B{
	// Inherits its fields from B
	int *arr;

	public:
		A(): arr{new int[5]} {}
		~A() { delete [] arr; }  // Non-virtual dtor
		std::string hello() override { return B::hello()+" og God morgen"; }
};

#endif
