#INCLUDE "rational.h"
#include <iostream>
using namespace std;

int main(){
	Rational r {1,2};
	cout << r.num << "/" << r.den << endl;

	Rational s;
	cin >> r >> s;
	Rational sum = r + s;
	Rational prod = r * s;
	cout << "Sum is " << sum << " and product is " << prod << endl;
}
