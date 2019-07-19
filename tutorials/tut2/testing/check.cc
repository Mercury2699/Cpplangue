#include <sstream>
#include <climits>

using namespace std;

// Tests if all numbers provided are of same parity,
bool test1( string line){
  stringstream ss(line);
  int parity = -1;
  int num;
  while(ss >> num){
    if ( parity == -1 ){
      parity = num % 2;
    } else {
      if ( num % 2 != parity ){
        return false;
      }
    }
  }
  if ( ! ss.eof() ) return false;
  return true;
} 

// Tests if the numbers are in increasing order.
bool test2( string line ){  
  stringstream ss(line);
  int num1, num2;
  num1 = INT_MIN;
  while(ss >> num2){
    if ( num1 > num2 ){
      return false;
    }
    num1 = num2;
  }
  if ( ! ss.eof() ) return false;
  return true;
}

// Tests if there are at most 3 numbers.
bool test3( string line ){
  stringstream ss(line);
  int num;
  int count = 0;
  while(ss >> num){
    ++count;
    if ( count > 4 ){
      return false;
    }
  }
  
	if ( ! ss.eof() ) return false;

  return true;
}

// Tests if the sum of the numbers is at least 25.
bool test4( string line ){
  stringstream ss(line);
  int num;
  int count = 0;
  bool result = true;
  while(ss >> num){
    count += num;
  }
  if ( ! ss.eof() ) result = false;

  if ( count >= 25 ) return true;

  return false;
} 

// Tests if the sum of the numbers is non-negative.
bool test5( string line ){
  stringstream ss(line);
  int num;
  int count = 0;
  bool result = true;
  while(ss >> num){
    count += num;
  }
  if ( ! ss.eof() ) return false;

  if ( count < 0 ) return false;

  return true;
}

// Tests if all numbers are non-negative.
bool test6( string line ){
  stringstream ss(line);
  int num;
  int count = 0;
  while(ss >> num){
    if ( num < 0 ){
      return false;
    }
  }
  if ( ! ss.eof() ) return false;
  return true;
}

// Tests if some subset of the numbers at least sum to 2.
bool test7( string line ){
  stringstream ss(line);
  int num;
  int count = 0;
  while(ss >> num){
    ++count;
    if ( count >= 2  ){
      return true;
    }
  }

  return false;
}

// Tests if the number is not in decreasing order.
bool test8( string line ){
  stringstream ss(line);
  int num;
  int first;
  ss >> first;
  while(ss >> num){}

  if ( first < num ) return true;

  return false;
}
