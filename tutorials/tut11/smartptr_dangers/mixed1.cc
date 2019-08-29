#include <iostream>
#include <memory>
using namespace std;

void f(int *p) {
	shared_ptr<int> s{p};
}


int main() {
	int *p = new int{2};

	// Here, since f creates a shared_ptr to p
	// and it goes out of scope at the end of f,
	// the heap memory pointed to by p is FREED by
	// this point!
	f(p);

	cout << *p << endl;	// What does this print out?
	// delete p;		// Double free?
}
