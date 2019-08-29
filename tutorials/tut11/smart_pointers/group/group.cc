#include <memory>
#include <vector>
#include <iostream>
#include "member.h"
#include "group.h"
using namespace std;

int Group::nextID = 0;

Group::Group():id{nextID}{nextID++;}

Group::Group(const std::vector<std::shared_ptr<Member>> &members)
  :id{nextID}, members{members}{
  nextID++;
}

// deletating constuctor call: calls the other constructor
// for initalization
Group::Group(const Group &other): Group{other.members}{
}

Group::~Group(){
  cout << "Group " << id << " destroyed" << endl;
}
