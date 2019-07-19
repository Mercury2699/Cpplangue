#include <iostream>
using namespace std;

// lvalue check
void check(int& value){
  cout << "check called with lvalue " << value << endl;
}

// rvalue check
void check(int&& value){
  cout << "check called with rvalue " << value << endl;
}

int main(){
  int x = 5;
  //int& lref = 7; // Can we do this?
  int& lref2 = x;

  int&& rref = 10;
  //int&& rref2 = x; // Can we do this?

  cout << rref << endl;
  cout << &rref << endl;

  check(lref2); //lvalue
  check(std::move(rref));  //lvalue
  check(17);    //rvalue

}


