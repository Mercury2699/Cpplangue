#ifndef B_H
#define B_H

#include <string>

class B{
	int *b;

	public:
		B(): b{new int} {}
		virtual ~B() = 0;					// These two methods are PV, which
		virtual std::string hello() = 0;	// makes B an abstract class.
};

#endif
