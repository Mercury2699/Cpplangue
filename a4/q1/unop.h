#ifndef UNOP_H
#define UNOP_H
#include "expression.h"
#include <string>

using std::string;


class UnOp : public Expression {
    string operation;
    Expression * child;

    public:

    UnOp(string, Expression *);
    ~UnOp();

    int eval();
    std::string print();
    void setvar(string, int);
    void unsetvar(string);
};


#endif






