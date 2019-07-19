#include "variable.h"
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;
using std::logic_error;

Variable::Variable(string name): name{name}, isSet{false} {}

Variable::~Variable() {}

int Variable::eval(){
    if (isSet) {
        return val;
    } else {
        throw (logic_error(name));
    }
    return 0;
}

std::string Variable::print() {
    std::ostringstream oss;
    if (isSet) {
        oss << val;
    } else {
        oss << name;
    }
    return oss.str();
} 

void Variable::setvar(string nam, int i){
    if (name == nam){
        val = i;
        isSet = true;
    }
}

void Variable::unsetvar(string nam){
    if (nam == name) isSet = false;
}








