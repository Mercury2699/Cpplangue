#include <iostream>
#include <string>
#include "b.h"
using namespace std;

// We need this implementation, even if it's empty.
B::~B() { delete b; cout << "DTOR FTW" << endl; }

// Even if hello is PV, we can still give an implementation.
string B::hello() { return "Guten Tag"; }
