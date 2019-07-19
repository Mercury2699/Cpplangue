#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


class Expression{
    // no fields
    public:
    // Creates an initially empty Expression.
	// virtual Expression() = 0; // ctor
	// virtual Expression(const Expression & other) = 0; // copy ctor
	// virtual Expression(Expression && other) = 0; // move ctor: copy other and destroy it
	virtual ~Expression() = 0; // dtor
	// virtual Expression & operator=(const Expression & other) = 0; // copy assignment 
	// virtual Expression & operator=(Expression && other) = 0; // move assignment 

    virtual int eval() = 0;
    virtual std::string print() = 0;
    virtual void setvar(std::string, int) = 0;
    virtual void unsetvar(std::string) = 0;
};

// virtual std::istream &operator>>(std::istream &in, Expression *&e) = 0;


#endif






