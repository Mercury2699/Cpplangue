#include <iostream>
#include "DPRT.h"
int test( int a, int b ) {
    DPRT( ENTER, a << " " << b );
    if ( a < b ) {
        DPRT( a < b, a << " " << b );
    }
    DPRT( , a + b );    // empty title
    DPRT( HERE, "" );   // empty expression
    DPRT( EXIT, a );
    return a;
}

int main() {
    test( 3, 4 );
}
