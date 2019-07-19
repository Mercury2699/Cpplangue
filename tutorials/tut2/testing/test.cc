#include <iostream>
#include <sstream>
#include <string>
#include "check.h"

using namespace std;

int main(int argc, char* argv[]){
	if ( argc == 1 ){
		cerr << "usage: " << argv[0] << " <testnum>\n";
		cerr << "   where <testnum> is from 1-8" << endl;
		return 1;
	}
	
	// create a variable to store the function pointer in
	bool (*test)(string) = NULL;
	
	// get the test which will be used
	int testNum = 0;
	stringstream ss(argv[1]);
	ss >> testNum;

	// read from ss failed
	if ( !ss || testNum <=0 || testNum > 8 ){	
		cerr << "invalid command line argument" << endl;
		return 1;
	}

	switch (testNum){
		case 1:
			test = test1;
			break;
		case 2:
			test = test2;
			break;
		case 3:
			test = test3;
			break;
		case 4:
			test = test4;
			break;
		case 5:
			test = test5;
			break;
		case 6:
			test = test6;
			break;
		case 7:
			test = test7;
			break;
		case 8:
			test = test8;
			break;
	}
	// boolalpha tells cout to print bools as 'true' or 'false'
  cout << boolalpha;
  
  string line;
	// read each line and run the test on it
	while ( getline(cin, line) ){
    cout << test(line) << endl;
	}
}
