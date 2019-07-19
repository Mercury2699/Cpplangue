#include "node.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::ostream;

// Output operator
ostream& operator<<(ostream& out, const Node& n){
	out << n.value;
	if ( n.next ){
		out << " <-> " << *(n.next);
	}
	return out;
}

// One-parameter constructor
Node::Node(int value): value{value} {}

// Two-parameter constructor
Node::Node(int begin, int end): value(begin){
	// Set dir to so that adding it to begin will result in
	// eventually reaching end
	int dir = 1;
	if ( begin > end ){
		dir = -1;
	}	
	
	while ( begin != end ){
		begin += dir;
		add(begin);
	}
}

// Add method
void Node::add( int insert ){
	if ( next ){
		next->add(insert);
	} else {
		next = new Node{insert};
		next->prev = this;
	}
}

// Plus method
Node plus(Node n, int val){
	for ( Node* m = &n; m; m = m->next ){
		m->value += val;
	}
	return n;
}
