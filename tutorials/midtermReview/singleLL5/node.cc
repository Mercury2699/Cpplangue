#include <utility>
#include <iostream>
using std::swap;
using std::cout;
using std::endl;

struct Node{
  int val;
  Node* next;

  Node(int val, Node* next): val{val}, next{next} {
		#ifdef ELIDE
			cout << "basic called" << endl;
		#endif
	}

  // Copy Constructor
  Node(const Node& other):
    val{other.val},
    next{ (other.next != nullptr) ? new Node{*other.next} : nullptr} {
		#ifdef ELIDE
			cout << "copy ctor called" << endl;
		#endif
	}

  // Move ctor
  Node(Node&& other):val{other.val}, next{other.next} {
		other.next = nullptr;
		#ifdef ELIDE
			cout << "move ctor called" << endl;
		#endif
	}

  // Destructor
  ~Node(){delete next;}

#ifndef COPY
  // Copy Ass
  Node& operator=(const Node& other) {
    if(this != &other){
      val = other.val;
      delete next;
      next = (other.next ? new Node{*other.next} : nullptr);
    }
		#ifdef ELIDE
			cout << "copy ass called" << endl;
		#endif
    return *this;
  }

  // Move Ass
 Node& operator=(Node&& other) {
    val = other.val;
    delete next;
    next = other.next;
    other.next = nullptr;
		#ifdef ELIDE
			cout << "move ass called" << endl;
		#endif
    return *this;
  }
#else
  // Copy Ass (copy & swap idiom)
  Node& operator=(const Node& other) {
    // Copy
    Node copy{other};

    // Swap
    swap(copy.val, val);
    swap(copy.next, next);
		#ifdef ELIDE
			cout << "copy swap ass called" << endl;
		#endif
    return *this;
  }

	// Move Ass (copy & swap idiom)
	Node& operator=(Node&& other) {
		swap(other.val, val);
		swap(other.next, next);
		#ifdef ELIDE
			cout << "move swap ass called" << endl;
		#endif
		return *this;
	}
#endif
};

std::ostream& operator<<(std::ostream& out, Node* n) {
	Node* curNode = n;
	Node* nextNode = n->next;
	out <<  "[ ";
	for (; ; curNode = curNode->next, nextNode = nextNode->next) {
		out << curNode->val << " ";
		if (nextNode == nullptr) break;
	}
	out << "]" << endl;
	return out;
}

int main(){
  Node n{1, new Node{2, new Node{3, new Node{4, nullptr}}}};
	cout << "n is: " << &n << endl;
  
	Node m{n}; //Copy ctor
	cout << "copy ctor: m is " << &m << endl;
  
	Node o{Node{5, nullptr}}; //Move ctor
	cout << "move ctor: o is " << &o << endl;
  
	m = o; //Copy Ass
	cout << "copy ass: m is now " << &m << endl;
  
	n = Node{4, nullptr}; //Move Ass
	cout << "move ass: n is now " << &n << endl;
}
