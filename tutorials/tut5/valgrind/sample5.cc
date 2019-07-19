#include <iostream>
using namespace std;

struct S {
  int elements[3];
};

int main() {
  S *s = new S;
  delete [] s;
  return 0;
}
