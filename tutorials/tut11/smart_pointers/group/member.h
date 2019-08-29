#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include <iostream>
struct Member{
  std::string name;
  Member(std::string name): name{name}{}
  ~Member(){std::cout << "Member " << name << " deleted" << std::endl;}
};
#endif
