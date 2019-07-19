#include "pizzaFactory.h"
#include "crustandsauce.h"
#include "stuffedcrust.h"
#include "dippingsauce.h"
#include "topping.h"

#include <iostream>
#include <sstream>

using namespace std;

// This factory creates pizzas based on input:
Pizza* PizzaFactory::makePizza(){
	string descript;
	getline(cin, descript);

	istringstream ss{descript};

	Pizza* pizza = new CrustAndSauce;
	string topping;
	while ( ss >> topping ){
		if ( "stuffed" == topping ) pizza = new StuffedCrust(pizza);
		else if ( "ranch" == topping ) pizza = new DippingSauce(topping,pizza);
		else if ( "garlic" == topping ) pizza = new DippingSauce(topping,pizza);
		else if ( "cheese" == topping ) pizza = new Topping(topping, pizza);
		else if ( "pepperoni" == topping ) pizza = new Topping(topping, pizza);
		else if ( "mushroom" == topping ) pizza = new Topping(topping, pizza);
		else cerr << topping << " is not an available topping at this time" << endl;
	}
	return pizza;
}
