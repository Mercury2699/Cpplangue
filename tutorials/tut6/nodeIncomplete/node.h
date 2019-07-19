#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node{
	int value;
	Node* next = nullptr;
	Node* prev = nullptr;

	// Create a list with one node.
	Node(int value);

	// Create a list with all values from begin to end in order.
	Node(int begin, int end);

	// Add insert as the last node of the list.
	void add(int insert);
};

// Pretty-prints the linked list.
std::ostream& operator<<(std::ostream& out, const Node& n);

// Adds val to all nodes.
Node plus(Node n, int val);

#endif
