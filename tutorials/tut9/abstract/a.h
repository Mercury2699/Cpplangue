#ifndef A_H
#define A_H

// Is A an abstract or concrete class?
class A{
	int a;

	public:
		A(int a): a{a} {}
		virtual void foo() = 0;
};

#endif
