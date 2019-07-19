#include "unop.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;

UnOp::UnOp(string name, Expression * e) : operation{name}, child{e} {}

UnOp::~UnOp() {
    delete child;
}

int UnOp::eval(){
    if (operation == "NEG") {
        return -child->eval();
    } else if (operation == "ABS") {
        return child->eval() > 0 ? child->eval() : -child->eval() ;
    }
    return child->eval();
}

std::string UnOp::print(){
    std::ostringstream oss;
    if (operation == "NEG") {
        oss << "-" << child->print();
    } else if (operation == "ABS") {
        oss << "|" << child->print() << "|";
    }
    return oss.str();
}

void UnOp::setvar(string name, int i){
    child->setvar(name, i);
}

void UnOp::unsetvar(string name){
    child->unsetvar(name);
}









