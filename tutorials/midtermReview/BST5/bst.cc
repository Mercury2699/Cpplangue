#include <iostream>

class  BST{
	int data;
	BST* left;
	BST* right; //private
	public:

	//Ctor(s)
	BST(): //Default
		data{0},left{nullptr},right{nullptr}{}

	BST(int data, BST* left, BST* right): //	Basic
		data{data},left{left},right{right}{}
	  //BST n{1,nullptr,nullptr}

	//Dtor
	~BST(){
		delete left;
		delete right;
	}
	
	//Copy Ctor
	BST(const BST& o):
		data{o.data},
		left{o.left ? new BST{*o.left} : nullptr},
		right{o.right ? new BST{*o.right} : nullptr}{}

	//Move Ctor
	BST(BST &&o):
		data{o.data},left{o.left},right{o.right}{
		o.left = nullptr;
		o.right = nullptr;
	}

	//Copy Assn Op
	BST &operator=(const BST& o){
		if(this == &o) return *this;

		BST* tmpL = left;
		BST* tmpR = right;
		left = {o.left ? new BST{*o.left} : nullptr};
		right = {o.right ? new BST{*o.right} : nullptr};
		// ========= EXCEPT
		delete tmpL;
		delete tmpR;
		data = o.data;

		return *this;
	}


	//Move Assn Op
		BST &operator=(BST &&o){

			std::swap(data, o.data);
			delete left;
			delete right;
			data = o.data;
			left = o.left;
			right = o.right;

			o.left = nullptr;
			o.right = nullptr;

			return *this;
		}


	
};

int main(){
}
