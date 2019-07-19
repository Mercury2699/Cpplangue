#ifndef ___FACTORY__H__
#define ___FACTORY__H__

#include "pizza.h"

class PizzaFactory{
 public:
	// Create a pizza based on input:
	Pizza* makePizza();
};

#endif
