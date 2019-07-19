#include <iostream>
#include <string>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;


int main() {
  Text t1("Programming for Beginners", "Niklaus Wirth", 200, "BASIC");
  Text t2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");

  AbstractBook *pb1 = &t1;
  AbstractBook *pb2 = &t2;
  
  *pb1 = *pb2;  // Prevented by compiler

  t1 = t2;

  cout << "Book 1: " << t1.getTitle() << ", " << t1.getAuthor() << ", "
       << t1.getTopic() << endl;

  cout << "Book 2: " << t2.getTitle() << ", " << t2.getAuthor() << ", "
       << t2.getTopic() << endl;
}
