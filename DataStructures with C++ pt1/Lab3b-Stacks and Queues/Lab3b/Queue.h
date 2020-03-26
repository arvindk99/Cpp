#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedNode.h"
#include "LinkedList.h"

template<typename T>
class Queue : public LinkedList<T>
{
public:
	//*****************************
	//* Default Constructor
	//*****************************
	Queue() :LinkedList() {};

	//*****************************
	//* Destructor 
	//*****************************
	~Queue()
	{
		while (this->isEmpty() == false)
		{
			dequeue();
		}
	}
	/*
	Function name - enqueue
	PRE- value
	POST- none
	PURPOSE- add value to end of queue
	*/
	void enqueue(T value);

	/*
	Function name - dequeue
	PRE- None
	POST- None
	PURPOSE- remove  value from front
	*/
	void dequeue();

	/*
	Function name - front
	PRE- Non
	POST- node->getItem()
	PURPOSE- return front of queue
	*/
	T front();

	/*
	Function name - rear
	PRE- None
	POST- currentPtr->getItem()
	PURPOSE-return rear of queue
	*/
	T rear();
};

template<typename T>
void Queue<T>::enqueue(T value)
{
	this->Add(value);
}

template<typename T>
void Queue<T>::dequeue()
{
	this->deleteFromFront();
}

template<typename T>
T Queue<T>::front()
{
	LinkedNode<T> *node = this->getHead();
	return node->getItem();
}

template<typename T>
T Queue<T>::rear()
{
	LinkedNode<T>* currentPtr = this->getHead();
	LinkedNode<T>* next = currentPtr->getNext();
	while (next != tail) 
	{
		currentPtr = next;
		next = currentPtr->getNext();
	}
	return currentPtr->getItem();
}



#endif // !QUEUE_H
