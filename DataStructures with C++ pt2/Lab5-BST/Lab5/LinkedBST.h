/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#ifndef LINKED_BST_H
#define LINKED_BST_H
#include "BSTNode.h"
#include <iostream>
#include <fstream>

template <typename T>
class LinkedBST
{
private:
	BSTNode<T> *root;
	int count = 0;
protected:
	//***********************************
	//* Function name : *insert helper method
	//* Pre - BSTNode<T> *nodePtr, BSTNode<T> *newNode
	//* Pos - newNode
	//* Purpose - insert a node in the binary tree
	//***********************************
	BSTNode<T> *insert(BSTNode<T> *nodePtr, BSTNode<T> *newNode)
	{
		// Check if nodePtr is nullptr
		if (nodePtr == nullptr)
		{
			return newNode;
		}
		// If nodePtr is not nullptr
		else
		{
			// Create instances to left and right pointer
			BSTNode<T> *leftPtr = nodePtr->getLeft();
			BSTNode<T> *rightPtr = nodePtr->getRight();

			// Compare nodePtr to the new node
			if (getHeight(leftPtr) > getHeight(rightPtr))
			{
				rightPtr = insert(rightPtr, newNode);
				nodePtr->setRight(rightPtr);
			}
			else
			{
				leftPtr = insert(leftPtr, newNode);
				nodePtr->setLeft(leftPtr);
			}
			return nodePtr;
		}
	}

	//***********************************
	//* Function name : *deleteNode helper method
	//* Pre - BSTNOde<T> *root, T value, bool &truth
	//* Pos - root 
	//* Purpose - delete node based on the conditions
	//***********************************	
	BSTNode<T> *deleteNode(BSTNode<T> *root, T value, bool &truth)
	{
		// Check if root is nullptr
		if (root == nullptr)
		{
			truth = false;
			return nullptr;
		}
		// Check if data is equal to the value
		else if (root->getData() == value)
		{
			root = removeNode(root);
			truth = true;
			return root;
		}
		// check if data greater than value
		else if (root->getData() > value)
		{
			BSTNode<T> *tempPtr = deleteNode(root->getLeft(), value, truth);
			root->setLeft(tempPtr);
			return root;
		}
		// check if data is less than value
		else
		{
			BSTNode<T> *tempPtr = deleteNode(root->getRight(), value, truth);
			root->setRight(tempPtr);
			return root;
		}
	}

	//***********************************
	//* Function name : *removeNode
	//* Pre - BSTNode<T> *nodePtr
	//* Pos - nodePtr
	//* Purpose - delete node from binary tree
	//***********************************
	BSTNode<T> *removeNode(BSTNode<T> *nodePtr)
	{
		// check if theres no children
		if (nodePtr->getLeft() == nullptr && nodePtr->getRight() == nullptr)
		{
			delete nodePtr;
			BSTNode<T> *nodePtr = nullptr;
			return nodePtr;
		}
		// check if there is at least one child
		else 
		{
			// Checking if node has only one child
			if ((nodePtr->getLeft() == nullptr && nodePtr->getRight() != nullptr) 
				|| (nodePtr->getLeft() != nullptr && nodePtr->getRight() == nullptr))
			{
				// If node has left child
				if (nodePtr->getLeft())
				{
					BSTNode<T> *nodeToConnectPtr = nodePtr->getLeft();
					delete nodePtr;
					BSTNode<T> *nodePtr = nullptr;
					return nodeToConnectPtr;
				}
				// If node has right child
				else
				{
					BSTNode<T> *nodeToConnectPtr = nodePtr->getRight();
					delete nodePtr;
					BSTNode<T> *nodePtr = nullptr;
					return nodeToConnectPtr;
				}
			}
			// Checking if has two children
			else
			{
				BSTNode<T> *tempPtr = removeLeftMostNode(nodePtr->getRight(), nodePtr->getRight()->getData());
				nodePtr->setRight(tempPtr);
				nodePtr->setData(nodePtr->getRight()->getData());
				return nodePtr;
			}
		}
	}
	//***********************************
	//* Function name : *removeLeftMostNode
	//* Pre - *nodePtr, &successor
	//* Pos - removeNode() 
	//* Purpose - remove the left most node of the tree
	//***********************************
	BSTNode<T> *removeLeftMostNode(BSTNode<T> *nodePtr, T &successor)
	{
		// Check if there's no left child
		if (nodePtr->getLeft() == nullptr)
		{
			successor = nodePtr->getData();
			return removeNode(nodePtr);
		}
		// If there's left child
		else
		{
			return removeLeftMostNode(nodePtr->getLeft(), successor);
		}
	}

	//***********************************
	//* Function name : destroySubTree
	//* Pre - *nodePtr
	//* Pos - None 
	//* Purpose - delete a substree
	//***********************************	
	void destroySubTree(BSTNode<T> *nodePtr)
	{
		// check nodePtr exist
		if (nodePtr)
		{
			// check if left child
			if (nodePtr->getLeft())
			{
				destroySubTree(nodePtr->getLeft());
			}
			// check if right child
			if (nodePtr->getRight())
			{
				destroySubTree(nodePtr->getRight());
			}
			delete nodePtr;
		}
	}

	//***********************************
	//* Function name : getHeight
	//* Pre - nodePtr
	//* Pos - height of BST 
	//* Purpose - find the height of BST
	//***********************************
	int getHeight(BSTNode<T> *nodePtr)
	{
		// Check if BST is empty, then return 0
		if (nodePtr == nullptr)
		{
			return 0;
		}
		// If BST is not empty
		else
		{
			int leftHeight = getHeight(nodePtr->getLeft());
			int rightHeight = getHeight(nodePtr->getRight());
			// Check if the left height is greater than right height
			if (leftHeight > rightHeight)
			{
				return (leftHeight + 1);
			}
			// Right height is greater than left height
			else
			{
				return(rightHeight + 1);
			}
		}
	}


	/*******************TRAVERSAL METHODS********************/
	
	//***********************************
	//* Function name : breadthFirst
	//* Pre - *nodePtr
	//* Pos - None 
	//* Purpose - breadth first traversal through BST
	//***********************************
	void breadthFirst(BSTNode<T> *nodePtr)
	{
		// Call the height 
		int h = getHeight(nodePtr);
		// Loop through to print the level
		for (int i = 1; i <= h; i++)
		{
			printLevel(nodePtr, i);
		}
	}

	//***********************************
	//* Function name : printLevel 
	//*                 helper method for breadthFirst helper method
	//* Pre - * root, i (level)
	//* Pos - None 
	//* Purpose - print each level of the BST 
	//***********************************
	void printLevel(BSTNode<T>* root, int i)
	{
		// Check if BST is empty
		if (root == nullptr)
		{
			return;
		}
		// if level 1
		if (i == 1)
		{
			std::cout << root->getData() << " " << endl;
		}
		else if (i > 1)
		{
			printLevel(root->getLeft(), i - 1);
			printLevel(root->getRight(), i - 1);
		}
	}

	//***********************************
	//* Function name : breadthFirstToFile
	//* Pre - *nodePtr, outFile
	//* Pos - None 
	//* Purpose - Breadth first print to file 
	//***********************************
	void breadthFirstToFile(BSTNode<T> *nodePtr, std::ofstream& outFile)
	{
		// Call the getheight 
		int h = getHeight(nodePtr);
		// Print the level to output file
		for (int i = 1; i <= h; i++)
		{
			printLevelToOut(nodePtr, i, outFile);
		}
	}

	//***********************************
	//* Function name : printLevelToOut
	//* Pre - *root,i, outFile
	//* Pos - None 
	//* Purpose - print level to output file 
	//***********************************
	void printLevelToOut(BSTNode<T>* root, int i, std::ofstream& outFile)
	{
		// Check if BST is empty
		if (root == nullptr)
		{
			return;
		}
		// If level 1
		if (i == 1)
		{
			outFile << root->getData() << " " << std::endl;
		}
		// After level 1
		else if (i > 1)
		{
			printLevelToOut(root->getLeft(), i - 1, outFile);
			printLevelToOut(root->getRight(), i - 1, outFile);
		}
	}

	//***********************************
	//* Function name : postOrder
	//* Pre - *nodePtr
	//* Pos - None 
	//* Purpose - postOrder traversal through file 
	//***********************************
	void postOrder(BSTNode<T> *nodePtr) const
	{
		// Check if nodePtr  exists
		if (nodePtr)
		{
			postOrder(nodePtr->getLeft());
			postOrder(nodePtr->getRight());
			std::cout << nodePtr->getData() << std::endl;
		}
	}

	//***********************************
	//* Function name : postOrderToFile
	//* Pre - *nodePtr, outFile
	//* Pos - None 
	//* Purpose - print postOrder traversal 
	//*			  to the file
	//***********************************
	void postOrderToFile(BSTNode<T> *nodePtr, std::ofstream& outFile)
	{
		// Check if nodePtr exists
		if (nodePtr)
		{
			inOrderToFile(nodePtr->getLeft(), outFile);
			inOrderToFile(nodePtr->getRight(), outFile);
			outFile << nodePtr->getData() << std::endl;		
		}
	}

	//***********************************
	//* Function name : preOrder
	//* Pre - *nodePtr
	//* Pos - None 
	//* Purpose - preOrder traversal through BST 
	//***********************************
	void preOrder(BSTNode<T> *nodePtr) const
	{
		// Check if nodePtr exists
		if (nodePtr)
		{
			std::cout << nodePtr->getData() << std::endl;
			preOrder(nodePtr->getLeft());
			preOrder(nodePtr->getRight());
		}
	}

	//***********************************
	//* Function name : preOrderToFile
	//* Pre - *nodePtr, outFile
	//* Pos - None 
	//* Purpose - print preOrder to the file 
	//***********************************
	void preOrderToFile(BSTNode<T> *nodePtr, std::ofstream& outFile)
	{
		// Check if nodePtr exists
		if (nodePtr)
		{
			outFile << nodePtr->getData() << std::endl;
			inOrderToFile(nodePtr->getLeft(), outFile);
			inOrderToFile(nodePtr->getRight(), outFile);
		}
	}

	//***********************************
	//* Function name : inOrder
	//* Pre - *nodePtr
	//* Pos - None 
	//* Purpose - inOrder traversal through BST 
	//***********************************
	void inOrder(BSTNode<T> *nodePtr) const
	{
		// Check if nodePtr exists
		if (nodePtr)
		{
			inOrder(nodePtr->getLeft());
			std::cout << nodePtr->getData() << std::endl;
			inOrder(nodePtr->getRight());
		}
	}

	//***********************************
	//* Function name : inOrderToFile
	//* Pre - *nodePtr, outFile
	//* Pos - None 
	//* Purpose - print inOrder to file 
	//***********************************
	void inOrderToFile(BSTNode<T> *nodePtr, std::ofstream& outFile)
	{
		// Check if nodePtr exists
		if (nodePtr != nullptr)
		{
			inOrderToFile(nodePtr->getLeft(), outFile);
			outFile << nodePtr->getData() << std::endl;
			inOrderToFile(nodePtr->getRight(), outFile);
		}
	}

public:

	//default constructor
	LinkedBST()
	{
		root = nullptr;
	}
	//destructor
	~LinkedBST()
	{
		empty();
	}

	BSTNode<T> *getRoot()
	{
		return root;
	}

	void setRoot(BSTNode<T> *nodePtr)
	{
		root = nodePtr;
	}
 
	//***********************************
	//* Function name : insertNode
	//* Pre - T value
	//* Pos - None 
	//* Purpose - adding to the tree by 
	//*           calling the helping methods
	//***********************************
	void insertNode(T);

	//***********************************
	//* Function name : remove
	//* Pre - T&value
	//* Pos - boolean truth if removed  
	//* Purpose - remove a node from the BST 
	//***********************************
	bool remove(const T&);

	//***********************************
	//* Function name : search
	//* Pre - T value
	//* Pos - true or false if found the node 
	//* Purpose - search the value in the BST 
	//***********************************
	bool search(T);

	//***********************************
	//* Function name : print
	//* Pre - options, outFile
	//* Pos - None 
	//* Purpose - print the BST using the
	//*			  different traversals based
	//*			  on the options
	//***********************************
	void print(int options, std::ofstream& outFile);

	//***********************************
	//* Function name : getCount
	//* Pre - *nodePtr
	//* Pos - number of nodes in BST
	//* Purpose - count the number of node in BST 
	//***********************************
	int getCount(BSTNode<T> *nodePtr);

	//***********************************
	//* Function name : isEmpty()
	//* Pre - None
	//* Pos - true or false if the BST is empty
	//* Purpose - Check if BST is empty 
	//***********************************
	bool isEmpty();

	//***********************************
	//* Function name : empty
	//* Pre - None
	//* Pos - None 
	//* Purpose - Empty the BST by calling 
	//*           destroySubTree
	//***********************************
	void empty() { destroySubTree(root); }

	//***********************************
	//* Function name : inOrder
	//* Pre - None
	//* Pos - None 
	//* Purpose - calls inOrder method 
	//***********************************
	void inOrder() const { inOrder(root); }
	//***********************************
	//* Function name : preOrder
	//* Pre - None
	//* Pos - None 
	//* Purpose - calls the preOrder method 
	//***********************************
	void preOrder() const { preOrder(root); }
	
	//***********************************
	//* Function name : postOrder
	//* Pre - None
	//* Pos - None 
	//* Purpose - calls postOrder 
	//***********************************
	void postOrder() const { postOrder(root); }

	//***********************************
	//* Function name : breadthFirst
	//* Pre - None
	//* Pos - None 
	//* Purpose - calls breadthFirst 
	//***********************************
	void breadthFirst() { breadthFirst(root); }

};
#endif

template <typename T>
void LinkedBST<T>::insertNode(T value)
{
	BSTNode<T> *newNode = new BSTNode<T>(value);
	root = insert(root, newNode);
}


template <typename T>
bool LinkedBST<T>::remove(const T &value)
{
	bool truth = false;
	deleteNode(root, value, truth);

	return truth;
}

template <typename T>
bool LinkedBST<T>::search(T value)
{
	BSTNode<T> *nodePtr = root;

	// Traverse the BST
	while (nodePtr)
	{
		// Check if data is equal to the value
		if (nodePtr->getData() == value)
		{
			return true;
		}
		// Check if the value is less than the data
		else if (value < nodePtr->getData())
		{
			nodePtr = nodePtr->getLeft();
		}
		// Check if the value is greater than the data
		else
		{
			nodePtr = nodePtr->getRight();
		}
	}
	return false;
}

template <typename T>
void LinkedBST<T>::print(int options, std::ofstream& outFile)
{
	// If options is 1 then call inOrderToFile
	if (options == 1)
	{
		inOrderToFile(root, outFile);
	}
	// If 2 then call preOrderToFile
	else if (options == 2)
	{
		preOrderToFile(root,outFile);
	}
	// If 3 then call postOrderToFile
	else if (options == 3)
	{
		postOrderToFile(root,outFile);
	}
	// If 4 then call breadth first
	else
	{
		breadthFirstToFile(root,outFile);
	}
}

template <typename T>
int LinkedBST<T>::getCount(BSTNode<T> *nodePtr)
{
	// If nodePtr doesn't exists 
	if (nodePtr == NULL)
	{
		return count;
	}
	// If there's no children
	if (nodePtr->getLeft() == NULL && nodePtr->getRight() == NULL)
	{
		count = 1;
		return count;
	}
	else
	{
		count += getCount(nodePtr->getLeft());
		count += getCount(nodePtr->getRight());
		return count;
	}
}

template <typename T>
bool LinkedBST<T>::isEmpty()
{
	if (count > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
