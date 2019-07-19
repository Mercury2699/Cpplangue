#ifndef C_H
#define C_H

#include <iostream>
#include "a.h"

// Is C an abstract or concrete class?
class C : public A{
	int c;

	public:
		C(int a, int c): A{a}, c{c} {}
        void foo() override { std::cout << "Ain't nobody got time for PV methods" << std::endl; }
};

#endif
