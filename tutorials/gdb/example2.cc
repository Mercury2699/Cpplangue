#include <iostream>
#include "black_box.h"

void small(int &a){
  a /= 68;

}

int bar(int &p){
  p *= 3;
  return unknown(p);
}

void oof(int &n){
  n *= n - 20;
  n = n - bar(n);
}

void foo(int &z){
  z = bar(z);
  oof(z);
  unknown(z);
  small(z);
  ++z;
}

int main(){
  int x = 10;
  foo(x);

  if(x == 0){
    std::cerr << "Error: x set to 0" << std::endl;
    return 3;
  }
}
