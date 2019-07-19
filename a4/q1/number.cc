#include "number.h"
#include <string>
#include <iostream>

Number::Number(int i): val{i} {}

Number::~Number() {}

int Number::eval() {
    return val;
}

std::string Number::print() {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

void Number::setvar(string name, int i) {}

void Number::unsetvar(string name) {}





