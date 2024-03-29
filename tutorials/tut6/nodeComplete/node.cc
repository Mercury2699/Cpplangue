#include "node.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::ostream;
using std::swap;

// Output operator
ostream& operator<<(ostream& out, const Node& n){
	out << n.value;
	if ( n.next ){
		out << " <-> " << *(n.next);
	} 
	return out;
}

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

// Plus function
Node plus(Node n, int val){
	for ( Node* m = &n; m; m = m->next ){
		m->value += val;
	}
	return n;
}

// One-parameter constructor
Node::Node(int value): value{value} {}

// Copy Constructor
Node::Node(const Node& n): value{n.value}, 
						   next{n.next ? new Node{*(n.next)}: nullptr}{
	if (next){
		next->prev = this;
	}
	cout << "Copy ctor for value = " << value << endl;
}

// Copy Assignment Operator
Node& Node::operator=(const Node &n){
	if (this != &n){
		Node copy = n;

		// swap next nodes
		swap(next, copy.next);

		value = copy.value;
		next->prev = this;
	}
	cout << "copy assignment operator" << endl;
	return *this;
}

// Destructor
Node::~Node(){
	delete next;
}

// Move Constructor
Node::Node(Node &&n): value{n.value},
                      next{n.next} {
    if (next) next->prev = this;
	n.next = nullptr;
    cout << "Move ctor for value = " << value << endl;
}

// Move Assignment Operator
Node &Node::operator=(Node &&n){
	value = n.value;
    swap(next, n.next);
    next->prev = this;
    
	cout << "Move assignment operator" << endl;
    return *this;
}
