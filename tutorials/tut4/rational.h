#include <iostream>

// Definition for Rational structure
struct Rational{
	int num;
	int den;

	void reduce();
};


// math operators
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);

// io operators
std::ostream& operator<<(std::ostream&, const Rational& rhs);
std::istream& operator>>(std::istream&, Rational& rhs);

