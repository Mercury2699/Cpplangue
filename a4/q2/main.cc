#include <iostream>
#include <sstream>
#include <string>
#include "number.h"
#include "variable.h"
#include "binop.h"
#include "unop.h"

using namespace std;

// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).
istream &operator>>(istream &in, Expression *&e) {
    vector<Expression *> stack;
    string s;
    while (in >> s) {
        istringstream ss(s);
        int n;
        if (ss >> n) {
            stack.emplace_back(new Number(n));
        } else if (s == "NEG" || s == "ABS") {
            if (stack.size() < 1) break;
            Expression * operation = new UnOp(s, stack.back());
            stack.pop_back();
            stack.emplace_back(operation);
            operation = nullptr;
        } else if (s == "+" || s == "-" || s == "*" || s == "/") {
            if (stack.size() < 2) break;
            Expression * RHS = stack.back(); 
            stack.pop_back();
            Expression * LHS = stack.back(); 
            stack.pop_back();
            Expression * operation = new BinOp(s, LHS, RHS);
            stack.emplace_back(operation);
            RHS = LHS = nullptr;
            operation = nullptr;
        } else if (s == "done") {
            break;
        } else { 
            stack.emplace_back(new Variable(s));
        }
    }
    if (stack.size() == 1){
        e = stack.back();
        stack.pop_back();
    } else {
        e = stack.front();
        stack[0] = nullptr;
        cerr << "invalid expression, taking the first valid part" << endl;
        for (auto it = stack.begin(); it != stack.end(); ++it) delete *it;
    }
    cout << e->print() << endl;
    return in;
}

int main () {
    string s;
    Expression *e;
    cin >> e;
    // Command interpreter
    while (cin >> s) {
        if (s == "eval") {
            try {
                cout << e->eval() << endl;
            } catch (logic_error e) {
                cout << e.what() << " has no value." << endl;
            }
        } else if (s == "set") {
            int n;
            cin >> s;
            cin >> n;
            e->setvar(s, n);
        } else if (s == "unset") {
            cin >> s;
            e->unsetvar(s);
        } else if (s == "print") {
            cout << e->print() << endl;
        } else if (s == "copy") {
            Expression * theCopy = e->copy();
            cout << theCopy->print() << endl;
            theCopy->setvar("x", 1);
            cout << theCopy->print() << endl;
            try {
                cout << theCopy->eval() << endl;
            } catch (logic_error e) {
                cout << e.what() << " has no value." << endl;
            }
            delete theCopy;
        }
    }
    delete e;
}







