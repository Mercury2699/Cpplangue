#ifndef VARIABLE_H
#define VARIABLE_H
#include "expression.h"
#include <string>

using std::string;


class Variable : public Expression {
    string name;
    int val;
    bool isSet;
    
    public:

    Variable(string);
    Variable(string,int,bool);
    ~Variable();

    int eval();
    std::string print();
    void setvar(string, int);
    void unsetvar(string);

    Expression * copy();
};


#endif









