#include <iostream>

int main() {
  int n;

  while(std::cin >> n){
    std::cout << n;
  }
  std::cin.ignore();

  std::cout << "input invalide";
  return 0;
}