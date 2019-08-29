#include "listiter.h"
struct List::Node {
  int data;
  Node *next;

  Node (int data, Node *next): data{data}, next{next} {}
  ~Node() { delete next; }
};

 // Copy Constructor
  Node(const Node& other):
    val{other.val},
    next{ (other.next != nullptr) ? new Node{*other.next} : nullptr} {}

  // Move ctor
  Node(Node&& other):val{other.val}, next{other.next} {
		other.next = nullptr;
  }

  // Destructor
  ~Node(){delete next;}

  // Copy Ass (No Guarantee)
  Node& operator=(const Node& other) {
    if(this != &other){
      auto n = std::make_unique<Node>(*other.next);
      val = other.val;
      delete next;
      next = (other.next ? n.get() : nullptr);
      n.release();
    }
    return *this;
  }

  // Move Ass
 Node& operator=(Node&& other) {
    val = other.val;
    delete next;
    next = other.next;
    other.next = nullptr;
    return *this;
  }

List::Iterator::Iterator(Node *p): p{p} {}

int &List::Iterator::operator*() const { return p->data; }

List::Iterator &List::Iterator::operator++() {
  p = p -> next;
  return *this;
}

bool List::Iterator::operator!=(const Iterator &other) const {
  return p != other.p;
}

List::Iterator List::begin() { return Iterator(theList); }
List::Iterator List::end() {return Iterator(nullptr); }

List::~List() { delete theList; }

void List::addToFront(int n) { theList = new Node(n, theList); }

int List::ith(int i) {
  Node *cur = theList;
  for (int j = 0; j < i && cur; ++j, cur = cur -> next);
  return cur->data;
}

