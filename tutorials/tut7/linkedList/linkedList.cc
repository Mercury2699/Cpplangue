#include "linkedList.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::ostream;

struct LinkedList::Node{
  int value;
  Node* next = nullptr;

  // Constructors
  Node(int value, Node* next = nullptr);
  Node(int begin, int end);

  // THE BIG 5: Which is which?
  Node( const Node& n );
  Node( Node&& n );
  Node& operator=( const Node& n );
  Node& operator=( Node&& n );
  ~Node();

  // Adds a Node insert at the end of LL.
  void add( int insert );
  // Gets the last Node
  Node* last();
};


// 1. LinkedList Methods

// Default Constructor
LinkedList::LinkedList(){}

// Adds a new node to the front of the LL.
void LinkedList::insertAtFront(int value){
  head = new Node{value, head};
  if ( ! tail ){
    tail = head;
  }
  ++numNodes; 
}

// Adds a new node to the end of the LL.
void LinkedList::insertAtBack(int value){
  Node* temp = new Node{value};

  // if tail exists, make temp the new tail
  if ( tail ){
    tail->next = temp;
    temp = tail;
  } else {
    // otherwise, temp is the only node and should be the head and the tail
    head = tail = temp;
  }
  ++numNodes; 
}

// Remove the index'th element.
void LinkedList::remove(int index){
  if ( index < numNodes ){
    Node* temp = head;
    if ( index == 0 ) { // First element
      head = head->next;
      temp->next = nullptr;
    } else { // Not first element
      int count = 0;
      while ( count + 1 < index ) { // Getting to the index'th element
        temp = temp->next;
        ++count;
      }

	  // Removing the element from the LL.
      Node* cur = temp;
      temp = temp->next;
      cur->next = temp->next;
      temp->next = nullptr;
    }

	// This actually deletes the element.
    delete temp;
    --numNodes;
  }
}

// Returns the size of the LL.
int LinkedList::size() const{
  return numNodes;
}


// 2. LinkedList::Node methods


LinkedList::Node* LinkedList::Node::last(){
  if ( next ) return next->last();
  return this;
}

LinkedList::LinkedList( const LinkedList& ll ): numNodes(ll.numNodes){
  if ( ll.head ){
    head = new Node{*ll.head};
    tail = head->last();
  }	
}

LinkedList::LinkedList( LinkedList&& ll ): numNodes{ll.numNodes},
  head{ll.head}, tail{ll.tail}{
    ll.head = nullptr;
    ll.tail = nullptr;
  }

LinkedList& LinkedList::operator=( const LinkedList& ll ){
  LinkedList copy = ll;

  using std::swap;

  swap(head, copy.head);
  swap(tail, copy.tail);
  swap(numNodes, copy.numNodes);

  return *this;
}

LinkedList& LinkedList::operator=( LinkedList&& ll ){
  using std::swap;

  swap(head, ll.head);
  swap(tail, ll.tail);
  swap(numNodes, ll.numNodes);

  return *this;
}

LinkedList::~LinkedList(){
  delete head;
}

LinkedList::Node& LinkedList::Node::operator=(const LinkedList::Node& other){
  Node copy = other;

  Node* temp = next;
  next = copy.next;
  copy.next = temp;

  value = copy.value;

  return *this;
}

LinkedList::Node::Node(const LinkedList::Node& other):value{other.value}{
  cout << "copying value of " << value << endl;
  if ( other.next != nullptr ){
    next = new Node{*(other.next)};  // copy constructor
  }
}


LinkedList::Node::~Node(){
  delete next;
}

LinkedList::Node::Node(int value, LinkedList::Node* next): value(value), next(next){}

LinkedList::Node::Node(int begin, int end): value(begin){
  // set dir to so that adding it to begin will result in
  //   eventually reaching end
  int dir = 1;
  if ( begin < end ){
    dir = -1;
  }	

  while ( begin != end ){
    next = new Node{end, next};
    end += dir;
  }
}

void LinkedList::Node::add( int insert ){
  if ( next ){
    next->add(insert);
  } else {
    next = new Node{insert};
  }
}


// 3. Other functions


// Prettyprints the LL.
ostream& operator<<(ostream& out, const LinkedList& ll){
  LinkedList::Node *curr = ll.head;
  if ( curr ){
    out << curr->value;
    curr = curr->next;
  }
  while ( curr ){
    out << " -> " << curr->value;
    curr = curr->next;
  }
  return out;
}
