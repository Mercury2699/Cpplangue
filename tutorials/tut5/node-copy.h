#ifndef NODE_COPY_H
#define NODE_COPY_H
#include <iostream>

struct Node{
	int value;
	Node* next = nullptr;
	Node* prev = nullptr;

	// Constructors
	Node(int value);
	Node(int begin, int end);

	// Copy Constructor
	Node( const Node& n );

	// Copy Assignment Operator
	Node& operator=( const Node& n );

	// Destructor
	~Node();

	// Adds a node to the end of the LL.
	void add( int insert );
};

// Pretty outputs the LL.
std::ostream& operator<<(std::ostream& out, const Node& n);

// Adds the value of val to all nodes.
Node plus(Node n, int val);
#endif
