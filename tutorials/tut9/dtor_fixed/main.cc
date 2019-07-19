#include <iostream>
#include <string>
#include "a.h"
#include "b.h"
using namespace std;

int main() {
	// Will this compile and work now that B's dtor is virtual?

	B *b = new A();
	cout << b->hello() << endl;
	delete b;

	A *a = new A();
	cout << a->hello() << endl;
	delete a;
}
