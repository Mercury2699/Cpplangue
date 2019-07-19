#include <iostream>
#include <fstream>
#include <sstream>

using std::endl;

int main(){
  // Initialize istream
  std::istream &in = std::cin;

  // Initialize ostream
  std::ostream &out = std::cout;

  int x;
  int y;
  int z;
  in >> x >> y >> z;
  out << in.fail() << endl;;
}
