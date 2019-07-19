#include <iostream>
using namespace std;

struct Vec {
  int x;
  int y;
	explicit Vec(int x, int y = 5): x{x}, y{y} {}
};

Vec operator+(const Vec &v1, const Vec &v2) {
  Vec v {v1.x + v2.x, v1.y + v2.y};
  return v;
}

int main () {
  Vec v1{1, 2};
  Vec v2{3, 4};
	Vec v3{v1 + v2};
  //Vec v3 {v1 + 3};

  cout << "v3.x = " << v3.x << "   v3.y = " << v3.y << endl;
}
