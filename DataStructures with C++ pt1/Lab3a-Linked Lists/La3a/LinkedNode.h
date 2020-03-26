/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#ifndef lINKED_NODE_H
#define LINKED_NODE_H

template <typename T>
class LinkedNode
{
private:
	T data;
	LinkedNode <T> *nextPtr;

public:
	//*******************************************
	//* Default Constructor
	//*******************************************
	LinkedNode();
	//*******************************************
	//* Constructor
	//*******************************************
	LinkedNode(const T &object, LinkedNode<T> next);
	//*******************************************
	//* Destructor
	//*******************************************
	virtual ~LinkedNode() {}
	//*******************************************
	//* Function Name: setItem
	//* Pre - object
	//* Pos - None
	//* Purpose - set data to object
	//*******************************************
	void setItem(const T& object);
	//*******************************************
	//* Function Name: setNext
	//* Pre - next
	//* Pos - None
	//* Purpose - set nextPtr to next
	//*******************************************
	void setNext(LinkedNode <T> *next);
	//*******************************************
	//* Function Name: getItenm
	//* Pre - None
	//* Pos - data
	//* Purpose - return data
	//*******************************************
	T getItem() const;
	//*******************************************
	//* Function Name: getNext
	//* Pre - None
	//* Pos - nextPtr 
	//* Purpose - return nextPtr
	//*******************************************
	LinkedNode<T> *getNext() const;
};

template <typename T>
LinkedNode<T>::LinkedNode()
{
	nextPtr = nullptr;
}

template <typename T>
LinkedNode<T>::LinkedNode(const T &object, LinkedNode<T> next)
{
	data = object;
	nextPtr = next;
}

template <typename T>
void LinkedNode<T>::setItem(const T &object)
{
	data = object;
}

template <typename T>
void LinkedNode<T>::setNext(LinkedNode<T>* next)
{
	nextPtr = next;
}

template <typename T>
T LinkedNode<T>::getItem() const
{
	return data;
}

template <typename T>
LinkedNode<T>* LinkedNode<T>::getNext() const
{
	return nextPtr;
}

#endif