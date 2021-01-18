/*
PARTNER 1: Arvind Kumar ID: 20372024
*/

#ifndef BST_NODE_H
#define BST_NODE_H
#include <iostream>
#include <string>

template <typename T>
class BSTNode
{
private:
	T data;
	BSTNode<T> *left;
	BSTNode<T> *right;
	
public:
	// Default Constructor
	BSTNode()
	{
		left = nullptr;
		right = nullptr;
	}

	// Constructor
	BSTNode(T &d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}

	// Constructor 
	BSTNode(T &d , BSTNode<T> *l, BSTNode<T> *r)
	{
		data = d;
		left = l;
		right = r;
	}

	// Destructor 
	virtual ~BSTNode() {}

	//***********************************
	//* Function name : getData
	//* Pre - None 
	//* Pos  - data
	//* Purpose - return data
	//***********************************
	T getData() { return data; }

	//***********************************
	//* Function name : getLeft
	//* Pre - None
	//* Pos - left
	//* Purpose - return left
	//***********************************
	BSTNode<T>* getLeft() { return left; }

	//***********************************
	//* Function name : getRight
	//* Pre - None
	//* Pos - right
	//* Purpose - return right
	//***********************************
	BSTNode<T>* getRight() { return right; }

	//***********************************
	//* Function name : setData
	//* Pre - std::string d 
	//* Pos - None
	//* Purpose - set data to d parameter
	//***********************************
	void setData(T d) { data = d; }

	//***********************************
	//* Function name : setLeft
	//* Pre - std::string* l
	//* Pos - None
	//* Purpose - set left to l parameter
	//***********************************
	void setLeft(BSTNode<T> *l) { left = l; }

	//***********************************
	//* Function name : setRight
	//* Pre - std::string* r
	//* Pos - None 
	//* Purpose - set right to r parameter
	//***********************************
	void setRight(BSTNode<T> *r) { right = r; }
};
#endif
