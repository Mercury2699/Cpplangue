#include <iostream>
using namespace std;

struct IntArray {
  int size; //number of elements the array currently holds
  int capacity; //number of elements the array could hold,
                //given current memory allocation to contents
  int *contents; //the integer array
};

IntArray readIntArray(){
  // struct init
  IntArray ia = IntArray{};
  ia.size = 0;
  ia.capacity = 0;
  ia.contents = nullptr;

  // if any reading 
  int n;

  while(cin >> n){
    // we start by 5 if there's actually int input
    if (!ia.capacity) {
      ia.capacity = 5;
      ia.contents = new int[5];
    }
    // resizing
    if (ia.size >= ia.capacity) {
      ia.capacity *= 2;
      int * newarr = new int[ia.capacity];
      for(int i = 0; i < ia.capacity / 2; i++) {
        newarr[i] = ia.contents[i];
      }
      delete[] ia.contents;
      ia.contents = newarr;
    }
    ia.contents[ia.size++] = n;
  }

  // get rid of the offending char that's not int
  cin.clear();
  cin.ignore();

  return ia;
}

void addToIntArray(IntArray &ia){
  int n;

  while(cin >> n){
    // we start by 5 if there's actually int input
    if (!ia.capacity) {
      ia.capacity = 5;
      ia.contents = new int[5];
    }
    // resizing
    if (ia.size >= ia.capacity) {
      ia.capacity *= 2;
      int * newarr = new int[ia.capacity];
      for(int i = 0; i < ia.capacity / 2; i++) {
        newarr[i] = ia.contents[i];
      }
      delete[] ia.contents;
      ia.contents = newarr;
    }
    ia.contents[ia.size++] = n;
  }

  // get rid of the offending char that's not int
  cin.clear();
  cin.ignore();
}

void printIntArray(const IntArray &ia){
  for (int i = 0; i < ia.size; i++ ){
    cout << ia.contents[i] << " "; 
  }
  cout << endl;
}

// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4]; // 4 element array of IntArrays denoted below as a b c d
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = nullptr;
  // init with empty contents
  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, 
                                 //                  q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents; // orig IA is replaced by new one
        a[which-'a'].contents = nullptr;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
