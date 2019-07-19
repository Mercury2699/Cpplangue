#include <iostream>
#include <string>
#include "b.h"
using namespace std;

// Since ~B is not PV, we need to implement it.
B::~B() { delete b; cout << "DTOR FTW" << endl; }

// Even if hello is PV, we can still give an implementation.
string B::hello() { return "Guten Tag"; }
