#include <iostream>
#include <string>
using namespace std;

int main () {
  string s;
  while (cin >> s) {
    try { 
        cout << std::stoi(s) << endl; // C++11 std::stoi
    } catch ( ... ) {
	cerr << "Couldn't convert \"" << s << "\" to an int." << endl;
    }
  }
}
