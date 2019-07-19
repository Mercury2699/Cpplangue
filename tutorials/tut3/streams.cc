#include <iostream>
#include <fstream>
#include <sstream>

using std::endl;

int main(){
  std::string s{"14 32 99 hi 69"};
  std::istringstream iss{s};
  std::ofstream of{"numbers"};

  // Initialize istream
  std::istream &in = std::cin;

  // Initialize ostream
  std::ostream &out = of;

  int x;
  while(1){
    in >> x;
    if(in.fail()){
      out << "Fail" << endl;
      in.clear();
      in.ignore();
    }
    if(in.eof()){
      out << "EOF Reached" << endl;
      break;
    }
    out << x + 1 << endl;
  }
}
