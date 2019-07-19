#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "pizza.h"
#include "pizzaFactory.h"

int main() {
  PizzaFactory store;
  Pizza *myPizzaOrder[3];

  // Pizza order comes in:
  cout << "Please write a toppings and extras for your first pizza:" << endl;
  myPizzaOrder[0] = store.makePizza(); 
  cout << "Please write a toppings and extras for your second pizza:" << endl;
  myPizzaOrder[1] = store.makePizza(); 
  cout << "Please write a toppings and extras for your third pizza:" << endl;
  myPizzaOrder[2] = store.makePizza(); 

  float total = 0.0;

  // Prints out the costs.
  for (int i = 0; i < 3; ++i) {
    cout << myPizzaOrder[i]->description()
         << ": " << myPizzaOrder[i]->price() << endl;
    total += myPizzaOrder[i]->price();
  }

  cout << endl << "Total cost: " << total << endl;

  for (int i = 0; i < 3; ++i) {
    delete myPizzaOrder[i];
  }
}
