#ifndef NUMBER_H
#define NUMBER_H
#include "expression.h"
#include <string>

using std::string;


class Number : public Expression {
    int val;
    
    public:

    Number(int);
    ~Number();

    int eval();
    std::string print();
    void setvar(string, int);
    void unsetvar(string);
};


#endif





