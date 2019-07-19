#include "rational.h"
#include <iostream>

int gcd(int a, int b){
	if ( b == 0 ){
		return a;
	}
	return gcd(b, a % b);
}

void Rational::reduce(){
	int gcdRat = gcd(num, den);
	num /= gcdRat;
	den /= gcdRat;
}

// math operators
Rational operator+(const Rational& lhs, const Rational& rhs){
	Rational ret {lhs.num*rhs.den + lhs.den*rhs.num, lhs.den*rhs.den};
	ret.reduce();
	return ret;
}

Rational operator*(const Rational& lhs, const Rational& rhs){
	Rational ret {lhs.num*rhs.num, lhs.den*rhs.den};
	ret.reduce();
	return ret;
}

// io operators
std::ostream& operator<<(std::ostream& out, const Rational& rhs){
	out << rhs.num << "/" << rhs.den;
	return out;
}

std::istream& operator>>(std::istream& in, Rational& rhs){
	std::cout << "Please enter two numbers:" << std::endl;
	in >> rhs.num >> rhs.den;
	if ( rhs.den == 0 ) rhs.den = 1;
	rhs.reduce();
	return in;
}
