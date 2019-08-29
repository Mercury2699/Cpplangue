#include <memory>
#include <iostream>
using namespace std;

// Example of mixing raw pointers and shared pointers...
// Example of what NOT TO DO!

struct MyClass {
  int *data;
  MyClass(int x) : data{new int(x)} {}
  ~MyClass() {
    delete data;
    cout << "MyClass Dtor called" << endl;
  }
};


int main () {
  MyClass *x = new MyClass(5);
  shared_ptr<MyClass> sp(x);
  
  // Defining new scope
  {
    cout << "Making a duplicate shared_ptr with raw pointer...also bad!" << endl;
    shared_ptr<MyClass> sp2(x);
    cout << "x's data is: " <<x->data<< endl;
  }

  // Arguably worse than first example because now we have a double free
  // at the end of our program. Although some may say this is better
  // as it's more clear we have a problem and less likely to be a bug
  // that makes it to production!
  cout << "Now my memory accesible through sp is gone!" << endl;
  cout << sp->data << endl;
}
