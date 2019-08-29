#include <iostream>
#include <string>
#include <memory>
#include "group.h"
#include "member.h"
using namespace std;

// This example shows how to implement overlapping groups for a certain
// members of the group using smart pointers.
//
// Note that Sean, Marie, the ISA are teaching tutorials
// Sean, Ten, the ISA are hosting office hours

void generateGroups(shared_ptr<Member> &isa, weak_ptr<Member> &p){
  Group tutorials;
  {
    auto ia = make_shared<Member>("Marko");
    tutorials.members.emplace_back(make_shared<Member>("Josh"));
    tutorials.members.emplace_back(make_shared<Member>("Zhara"));
    tutorials.members.emplace_back(isa);
    Group officehours;
    officehours.members.emplace_back(tutorials.members[0]);
    officehours.members.emplace_back(ia);
    officehours.members.emplace_back(isa);

    p = tutorials.members[0];

    // trying to convert p to a shared_ptr
    cout << "trying to get " << p.lock()->name << endl;
  } // Ten, Marie are freed here
} // Sean is freed here

int main(){
  auto isa = make_shared<Member>("Luke");
  weak_ptr<Member> p;
  generateGroups(isa,p);

  // p.lock() will give a nullptr since the associated object (Sean)
  // is freed already; all shared_ptr to Josh is deleted
  cout << "trying to get the pointer:" << p.lock() << endl;
}
