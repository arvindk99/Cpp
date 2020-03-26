/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
#include "LinkedNode.h"
#include <iostream>

template <typename T>
class LinkedList
{
protected:
	int count; //counter attribute
	LinkedNode<T>* head;
	LinkedNode<T>* tail;
	std::string sortType;
public:

	//*******************************************
	//* Default Constructor
	//*******************************************
	LinkedList() : count(0), head(nullptr), tail(nullptr), sortType("")
	{
	}

	//*******************************************
	//* Constructor
	//*******************************************
	LinkedList(int c, LinkedNode<T>* node1, std::string s1)
		: count(c), head(node1), tail(nullptr), sortType(s1)
	{
	}

	//*******************************************
	//* Destructor
	//*******************************************
	virtual ~LinkedList();

	//*******************************************
	//* Function Name: setCount
	//* Pre - counter
	//* Pos - None
	//* Purpose - set count to counter parameter
	//*******************************************
	void setCount(int counter) { count = counter; }

	//*******************************************
	//* Function Name: setHead
	//* Pre - node
	//* Pos - None
	//* Purpose - set head to node parameter
	//*******************************************
	void setHead(LinkedNode<T>* node) { head = node; }

	//*******************************************
	//* Function Name: setSortType
	//* Pre - node
	//* Pos - None
	//* Purpose - set sortType to the corresponding way it has been sorted
	//*******************************************
	void setSortType(std::string sort) { sortType = sort; }

	//*******************************************
	//* Function Name: getCount
	//* Pre - None
	//* Pos - count
	//* Purpose - Return count
	//*******************************************
	int getCount();

	//*******************************************
	//* Function Name: getHead
	//* Pre - None
	//* Pos - head
	//* Purpose - return head pointer
	//*******************************************
	LinkedNode<T>* getHead() { return head; }

	//*******************************************
	//* Function Name: getSortType
	//* Pre - None
	//* Pos - sortType
	//* Purpose - Return the sortType if the 
	//*			  linked list is sorted in 
	//*			  ascending, descending, or none
	//*******************************************
	std::string getSortType() { return sortType; }


	// Linked List behavior

	//*******************************************
	//* Function Name: Add
	//* Pre - value
	//* Pos - None
	//* Purpose -  Add a node 
	//*******************************************
	void Add(T);

	//*******************************************
	//* Function Name: addToFront
	//* Pre - value
	//* Pos - None
	//* Purpose -  Add a node to the beginning of
	//*	           the linked list 
	//*******************************************
	void addToFront(T);

	//*******************************************
	//* Function Name: deleteData
	//* Pre - value
	//* Pos - None
	//* Purpose - Delete a node 
	//*******************************************
	void deleteData(T);

	//*******************************************
	//* Function Name: deletFromFront
	//* Pre - None
	//* Pos - None
	//* Purpose - Delete a node from front of list
	//*******************************************
	void deleteFromFront();

	//*******************************************
	//* Function Name: deleteFromBack
	//* Pre - None
	//* Pos - None
	//* Purpose - Delete a node from end of list
	//*******************************************
	void deleteFromBack();

	//*******************************************
	//* Function Name: Find
	//* Pre - 
	//* Pos - 
	//* Purpose - 
	//*******************************************
	LinkedNode<T> Find(LinkedNode<T>);

	//*******************************************
	//* Function Name: empty
	//* Pre - None
	//* Pos - None
	//* Purpose - empty the linked list
	//*******************************************
	void empty();

	//*******************************************
	//* Function Name: printItems
	//* Pre - None
	//* Pos - None
	//* Purpose - Print all the data of each node
	//*			  in the linked list
	//*******************************************
	void printItems();

	//*******************************************
	//* Function Name: isEmpty
	//* Pre - None
	//* Pos - truth
	//* Purpose - Check if the linked list is empty
	//*           if empty return true, if not 
	//*           return false
	//*******************************************
	bool isEmpty();

	
};


template<typename T>
int LinkedList<T>::getCount()
{
	count = 0;
	// Set the nodePtr to head
	LinkedNode<T>* nodePtr = head;

	// Loop through the list 
	while (nodePtr != tail)
	{
		// Increment count
		count++;
		//Set nodePtr to the next node
		nodePtr = nodePtr->getNext();
	}
	return count;
}


template<typename T>
LinkedList<T>::~LinkedList()
{
	empty();
}


template<typename T>
void LinkedList<T>::Add(T value)
{
	// Declare node pointer
	LinkedNode<T>* nodePtr;

	// Declare a newNode
	LinkedNode<T>* newNode = new LinkedNode<T>;

	// Set data of the newNode to the value
	newNode->setItem(value);

	// Check the head nullptr 
	if (!head)
	{
		// Add newNode to the head
		head = newNode;
	}
	else
	{
		// Set the nodePtr to head
		nodePtr = head;

		// Loop through the linked list until the end
		while (nodePtr->getNext())
		{
			nodePtr = nodePtr->getNext();
		}
		// Set the newNode at the end of the list
		nodePtr->setNext(newNode);
	}
}

template<typename T>
void LinkedList<T>::addToFront(T value)
{
	// Create node
	LinkedNode<T>* tmp = new LinkedNode<T>;
	// Set data to value parameter
	tmp->setItem(value);
	// Set the next to head
	tmp->setNext(head);
	// Set head to the new node
	head = tmp;
}

template<typename T>
void LinkedList<T>::deleteData(T value)
{
	// Declare a nodePtr
	LinkedNode<T>* nodePtr = nullptr;
	// Declare a pointer to previous node 
	LinkedNode<T>* previousNode = nullptr;

	// Check if list is empty
	if (!head)
		return;

	// Check if the first node has the value to delete
	if (head->getItem() == value)
	{
		nodePtr = head->getNext();
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to start of the list
		nodePtr = head;

		// Loop through the linked list and skip the nodes that
		// does not have the value
		while (nodePtr != nullptr && nodePtr->getItem() != value) {
			previousNode = nodePtr;
			nodePtr = nodePtr->getNext();
		}

		// If the node that the user wants to delete is not at the
		// end of the list then set the previousNode pointer to the
		// node after nodePtr
		if (nodePtr)
		{
			previousNode->setNext(nodePtr->getNext());
			delete nodePtr;
		}
	}
}

template<typename T>
void LinkedList<T>::deleteFromFront()
{
	// Check if the list is empty
	if (head == tail)
	{
		std::cout << "List is already empty!" << std::endl;
	}
	else
	{
		//if (head->getNext != nullptr)
		//{
		LinkedNode<T>* temp = head->getNext();
		delete head;
		head = temp;
		//}
	}

}

template<typename T>
void LinkedList<T>::deleteFromBack()
{
	// Create the node pointer and previous node
	LinkedNode<T>* nodePtr = new LinkedNode<T>;
	LinkedNode<T>* previousNode = new LinkedNode<T>;

	// Check if the linked list is empty
	if (head == tail)
	{
		std::cout << "List Empty!" << std::endl;
	}
	else
	{
		// Check if there is only one node
		if (head->getNext() == tail)
		{
			nodePtr = head;
			head = nullptr;
			delete nodePtr;
		}
		else
		{
			nodePtr = head;
			// Loop through the linked list
			while (nodePtr->getNext() != tail)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->getNext();
			}

			previousNode->setNext(tail);
			delete nodePtr;

		}
	}

}

template<typename T>
LinkedNode<T> LinkedList<T>::Find(LinkedNode<T> value)
{
	// Declare pointer
	LinkedNode<T>* point = head;

	// Traverse through Linked List
	while (head != tail)
	{
		// If the data in the node is equal to the value 
		// return the value
		if (value == point->getItem())
		{
			return value;
		}
		//If not then set the point to nullptr and return 
		else
		{
			point = nullptr;
			return point;
		}
	}
}


template<typename T>
void LinkedList<T>::empty()
{
	// Loop through list and deletes all the node
	while (head != tail)
	{
		LinkedNode<T>* delNode = head;
		head = head->getNext();
		delNode->setNext(tail);
		delete delNode;
	}
	count = 0;
}


template<typename T>
void LinkedList<T>::printItems()
{
	// Declare nodePtr
	LinkedNode<T>* nodePtr;

	// Set to beginning to the linked list
	nodePtr = head;

	// Loop through the list
	while (nodePtr)
	{
		// Print the data
		std::cout << nodePtr->getItem() << std::endl;
		// Set nodePtr to next node
		nodePtr = nodePtr->getNext();
	}
}


template <typename T>
bool LinkedList<T>::isEmpty()
{
	bool truth;

	if (!head)
	{
		truth = true;
	}
	else
	{
		truth = false;
	}

	return truth;
}

#endif