#include <memory>
#include <iostream>
using namespace std;

// Run with valgrind to see that smart ptrs can leak memory too!

struct MyStruct {
  shared_ptr<MyStruct> other;
};

int main() {
  shared_ptr<MyStruct> c1 = make_shared<MyStruct>();
  shared_ptr<MyStruct> c2 = make_shared<MyStruct>();

  // Make c1 and c2 point at each other to form a cycle.
  // Now c1 and c2 can't be cleaned up...
  // Simple reference counting has its limitations!
  c1->other = c2;
  c2->other = c1;
}
