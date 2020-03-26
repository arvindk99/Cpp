#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "LinkedNode.h"
#include "LinkedList.h"

template<typename T>
class Stack : public LinkedList<T>
{
public:
	//*****************************
	//* Default Constructor
	//*****************************
	Stack() : LinkedList(){}


	//*****************************
	//* Destructor
	//*****************************
	~Stack()
	{
		while (this->isEmpty() == false)
		{
			pop();
		}
	}

	/*
	Function name - push
	PRE- value
	POST- none
	PURPOSE- push a value onto the stack
	*/
	void push(T value); 

	/*
	Function name - pop
	PRE- None
	POST- None
	PURPOSE- pops or remove the top value from the stack
	*/
	void pop();

	/*
	Function name - peek
	PRE- None
	POST- node->getItem()
	PURPOSE- return the top of the stack
	*/
	T peek();


};

template <typename T>
void Stack<T> ::push(T value)
{
	this->addToFront(value);
}


template <typename T>
void Stack<T> ::pop()
{ 
	this->deleteFromFront(); 
}


template<typename T>
T Stack<T>::peek()
{
	LinkedNode<T> *node = this->getHead();
	return node->getItem();
	
}


#endif 
