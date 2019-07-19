#include <iostream>

int factorial(const int &n){
  int retval;

  if(n){
    retval = n * factorial(n - 1);
  }else{ // Zero Base Case
    retval = 1;
  }
  return retval;
}

int main(){
  int n;

  std::cout << "Please enter a positive integer: ";
  if(std::cin >> n && n >= 0){
    std::cout << n << "! = " << factorial(n) << std::endl;
  }else{
    std::cout << "That's not a positive integer!" << std::endl;
  }
}
