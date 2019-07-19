#include "binop.h"
#include <iostream>
#include <string>

using std::cout;


BinOp::BinOp(string name, Expression * LHS, Expression * RHS) :
    operation{name}, operand1{LHS}, operand2{RHS} {}

BinOp::~BinOp() {
    delete operand1;
    delete operand2;
}

int BinOp::eval() {
    if (operation == "+"){
        return operand1->eval() + operand2->eval();
    } else if (operation == "-"){
        return operand1->eval() - operand2->eval();
    } else if (operation == "*"){
        return operand1->eval() * operand2->eval();
    } else if (operation == "/"){
        return operand1->eval() / operand2->eval();
    }
    return operand1->eval() + operand2->eval();
}

std::string BinOp::print() {
    std::ostringstream oss;
    oss << "(" << operand1->print() << " " << operation << " " << operand2->print() << ")";
    return oss.str();
}

void BinOp::setvar(string name, int i){
    operand1->setvar(name, i);
    operand2->setvar(name, i);
}

void BinOp::unsetvar(string name){
    operand1->unsetvar(name);
    operand2->unsetvar(name);
}

Expression * BinOp::copy(){
    return new BinOp(operation, operand1->copy(), operand2->copy());
}






