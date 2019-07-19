#include <iostream>
using namespace std;

int main() {
  int * elements = new int[3];
  elements[3] = 4;
  cout << elements[3] << endl;
  delete [] elements;
  return 0;
}
