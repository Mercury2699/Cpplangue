#include <iostream>
#include <vector>
#include <map>
#include "listiter.h"

int main(){
  List list; // My list of integers
  std::vector<int> vec; // Vector of integers
  std::map<int, int> map;

  int input;
  while(std::cin >> input){
   list.addToFront(input);
   vec.push_back(input * -1);
   map[input] = input * 2;
  }

  for(size_t i = 0; i < vec.size(); ++i){
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  for(auto it = vec.rbegin(); it != vec.rend(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  for(auto i : map){
    std::cout << i.first << ": " << i.second << std::endl;
  }
} //end main
