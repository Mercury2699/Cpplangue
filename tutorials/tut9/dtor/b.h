#ifndef B_H
#define B_H

#include <string>

class B{
	int *b;

	public:
		B(): b{new int} {}
		~B();								// Non-virtual dtor
		virtual std::string hello() = 0;	// This method is virtual, which makes B an abstract class.
};

#endif
