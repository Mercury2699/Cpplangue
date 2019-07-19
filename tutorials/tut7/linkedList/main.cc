#include "linkedList.h"
#include <iostream>
using namespace std;

int main(){
	LinkedList list;

	cout << "Size of list: " << list.size() << endl;
    cout << list << endl;

	// Adding elements
	list.insertAtFront(5);
	list.insertAtFront(10);
	list.insertAtBack(15);

	cout << "Size of list: " << list.size() << endl;
	cout << list << endl;

	// Removing an element
	list.remove(1);

	cout << "Size of list: " << list.size() << endl;
    cout << list << endl;
}
