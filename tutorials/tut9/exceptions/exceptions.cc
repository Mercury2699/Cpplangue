#include<iostream>
using namespace std;

// One exception class
class BadInput{};

// Another exception class
class BadNumber: public BadInput{
	public:
		string what() { return "no number given"; }
};

int main(){
    try { // Let's try this block:
		int x;
        cin >> x;
		if (x < 50) {
            throw BadNumber{};
        }
    }
	// Which catch block will run?
	catch(BadInput &b) {
		cerr << "This is caught" << endl;
	} catch(BadNumber &b) {
		cerr << b.what() << " is caught" << endl;	// Accessing auxilliary information
													// from object that was caught
	}
}
