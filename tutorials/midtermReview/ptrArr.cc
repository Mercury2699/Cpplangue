#include <iostream>

struct S {
private:
	int x;
public:
	S(int xx): x{xx} {}
	int getX() const {return x;}
};

std::ostream& operator<<(std::ostream& out, const S& s) {
	out << s.getX();
	return out;
}

int main() {
	const int max = 5;
	S** ptrArr = new S*[max];
	
	for (int i=0; i<max; ++i) {
		ptrArr[i] = new S(i);
		std::cout << *ptrArr[i] << std::endl;
	}
	
	for (int i=0; i<max; ++i)
		delete ptrArr[i];
	delete [] ptrArr;
}
