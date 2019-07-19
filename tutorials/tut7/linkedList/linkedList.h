#ifndef ___LINKED__LIST___
#define ___LINKED__LIST___

#include <iostream>

struct S{
  int x;
 private:
  int c;
};

class LinkedList{
  public:
    // Constructor
    LinkedList();

	// Inserts the Node value to the front of the LL.
    void insertAtFront(int value);
	// Inserts the Node value to the back of the LL.
    void insertAtBack(int value);

	// Remove the Node at index
    void remove(int index);

	// Returns the size of the LL
    int size() const;

	// Pretty prints the LL
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& ll);
    friend S;

	// Copy ctor
    LinkedList( const LinkedList& ll );
	// Move ctor
    LinkedList( LinkedList&& ll );
    // Copy operator=
	LinkedList& operator=( const LinkedList& ll );
    // Move operator=
	LinkedList& operator=( LinkedList&& ll );
    // Destructor
	~LinkedList();

  private:
    int numNodes = 0;

    struct Node; // FORWARD DECLARATION of Node class.
    Node* head = nullptr;
	Node* tail = nullptr;
};

#endif
