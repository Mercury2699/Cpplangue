#include <string>
#include <iostream>

int main(){
  std::string s{"Hello"};
  std::string f{"Hello to "};

  std::cout << s[2] << s[4] << std::endl;

  std::cout << (s == f) << std::endl;
  std::cout << (s < f) << std::endl;
  std::cout << (s > f) << std::endl;

  f += s;

  std::cout << f << " ";
  std::cout << f.length() << std::endl;
  std::cout << f.substr(4) << std::endl;
  std::cout << s.find('l') << std::endl;
  std::cout << s.substr(1, 3) << std::endl;
}
