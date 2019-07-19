#include "a.h"
#include "b.h"
#include "c.h"

int main() {
	// THESE TWO DO NOT WORK!
	// A a{1};
	// a.foo();

	// THE REMAINING DO WORK
	B b{2};
	b.foo();

	C c{1,2};
	c.foo();

	// THIS WORKS EVEN IF A IS ABSTRACT
	A *a = new C{1,2};
	a->foo();
	delete a;
}
