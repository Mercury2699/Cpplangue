#ifndef BINOP_H
#define BINOP_H
#include "expression.h"
#include <string>

using std::string;


class BinOp : public Expression {
    string operation;
    Expression * operand1;
    Expression * operand2;

    public:

    BinOp(string, Expression *, Expression *);
    ~BinOp();

    int eval();
    string print();
    void setvar(string, int);
    void unsetvar(string);
};


#endif





