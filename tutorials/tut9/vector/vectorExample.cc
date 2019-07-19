#include <iostream>
#include <vector>
using namespace std;

class A {
	int x;

	public:
		A(int x): x{x} {}

		int get_x() const { return x; }
};

int main(){
	// Creating a new vector
    std::vector<A> arr;
	int x;

	// Placing items to the back of the vector
	cout << "Continue to supply numbers to enter into the vector:" << endl;
	while(cin >> x) {
		A a{x};
		arr.emplace_back(x);
	}

	// Iterating through the vector
	cout << "The vector is: [";
	for(auto it : arr) {
		cout << it.get_x();

		//if (it != arr.end() - 1) cout << ",";
	}
	cout << "]" << endl;
}
