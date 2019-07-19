#include <iostream>
#include <string>
using namespace std;

int main() {
	string *ps = new string;
	cout << "Please type in a string:" << endl;
	cin >> *ps;
	cout << "The string is: " << *ps << endl;

	int *x = new int[5];
	cout << "Please enter 5 integers:" << endl;
	for(int i = 0; i < 5; ++i) {
		cin >> x[i];
	}
	cout << "The integer array is:";
	for(int i = 0; i < 5; ++i) {
		cout << " " << x[i];
	}
	cout << endl;

	delete ps;
	delete [] x;
}
