// Debug printing : simple mechanism for generating debug print statements.
//
// Interface :
//   DPRT( title, expr ) - identifying title, expression to be printed
//
//   preprocessor variable "NDEBUG" suppresses all debug printing, e.g., compile with -DNDEBUG
//
// Example : debug printing for entry, intermediate, and exit locations
//
//    #include <iostream>
//    #include "DPRT.h"
//    int test( int a, int b ) {
//        DPRT( ENTER, a << " " << b );
//        if ( a < b ) {
//            DPRT( a < b, a << " " << b );
//        }
//        DPRT( , a + b );    // empty title
//        DPRT( HERE, "" );   // empty expression
//        DPRT( EXIT, a );
//        return a;
//    }
//
// which generates debug output:
//
//    ENTER   "int test(int, int)" 3 4 in test.cc at line 4
//    a < b   "int test(int, int)" 3 4 in test.cc at line 6
//            "int test(int, int)" 7 in test.cc at line 8
//    HERE    "int test(int, int)" in DPRT.cc at line 9
//    EXIT    "int test(int, int)" 3 in test.cc at line 10
//
// Limitations :
//   Must include "iostream"
//   __PRETTY_FUNCTION__ is GNU C/C++ specific; __func__ is supposed to be portable.

#ifdef NDEBUG
#define DPRT( title, expr ) ((void)0)
#else
#define DPRT( title, expr ) \
    { std::cerr << #title "\t\"" << __PRETTY_FUNCTION__ << "\" " << \
      expr << " in " << __FILE__ << " at line " << __LINE__ << std::endl; }
#endif
