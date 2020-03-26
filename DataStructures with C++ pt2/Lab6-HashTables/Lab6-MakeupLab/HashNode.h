#pragma once
//
//  HashNode.h
//  Lab6-Makeup
//	Arvind Kumar ID:20372024
//

#ifndef HashNode_h
#define HashNode_h
#include <iostream>
#include <string>

template<typename V>
class HashNode
{
private:
	int key;
	V value;
	HashNode *next;
public:
	//Default constructor	
	HashNode() : key(NULL), next(nullptr)
	{
	}
	//Copy Constructor 1
	HashNode(int k, V v) : key(k), value(v), next(nullptr)
	{
	}
	//Copy Constructor 2
	HashNode(int k, V v, HashNode<V> *n) :key(k), value(v), next(n)
	{
	}

	//Getters and Setters for attributes
	int getKey() {
		return key;
	}

	void setKey(int k)
	{
		key = k;
	}

	V getValue() {
		return value;
	}

	void setValue(V v) {
		value = v;
	}

	HashNode *getNext() const {
		return next;
	}

	void setNext(HashNode *n) {
		next = n;
	}

};

#endif
