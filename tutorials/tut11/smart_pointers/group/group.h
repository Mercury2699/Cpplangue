#ifndef GROUP_H
#define GROUP_H
#include <memory>
#include <vector>
#include <iostream>

class Member;

struct Group{
  static int nextID;
  int id;
  // using a shared pointer; member will freed when a member
  // does not exist in any of the groups (and there is no 
  // shared_ptrs to member outside this class).
  std::vector<std::shared_ptr<Member>> members;
  Group();
  Group(const std::vector<std::shared_ptr<Member>> &members);
  Group(const Group &other);
  ~Group();
};
#endif
