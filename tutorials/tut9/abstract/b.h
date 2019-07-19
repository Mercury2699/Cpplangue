#ifndef B_H
#define B_H

#include<iostream>

// Is B an abstract or concrete class?
class B{
	int b;

	public:
		B(int b): b{b} {}
		void foo() { std::cout << "This is not PV" << std::endl; }
};

#endif
