#include "fun.h"
#include <iostream>

void fun(int x){
  while(x > 0){
    std::cout << "CS136" << std::endl;
    x -= 2;
  }

  std::cout << "I can't wait for CS246!" << std::endl;
}

void funner(int x){
  int y = 0;
  x /= 2;

  while(y < x){
    std::cout << "CS246" << std::endl;
    ++y;
  }

  std::cout << "I love CS246!" << std::endl;
}
