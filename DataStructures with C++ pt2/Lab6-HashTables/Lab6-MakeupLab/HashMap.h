//
//  HashMap.h
//  Lab6-Makeup
//	Arvind Kumar ID:20372024
//
#ifndef HashMap_h
#define HashMap_h
#include "HashNode.h"
#include "Person.h"
#include <iostream>
#include <string>

class HashMap
{
private:
	//initializing array
	HashNode<Person> *table;
	int hashSize;
	int collisions;
	int hashKey;

public:
	//setting a max size
	static const int MAX_SIZE = 100;

	//Constructor
	HashMap()
	{
		collisions = hashSize = 0;
		hashKey = NULL;
		table = new HashNode<Person> [MAX_SIZE];
		//setting the keys to the corresponding i
		for (int i = 0; i < MAX_SIZE; i++)
		{
			table[i].setKey(i);
		}
		
	}

	//setters and getters
	void setHashSize(int a)
	{
		hashSize = a;
	}

	void setCollisions(int c)
	{
		collisions = c;
	}

	void setHashKey(int k)
	{
		hashKey = k;
	}

	//size_of
	int getHashSize()
	{
		return hashSize;
	}

	int getCollisions()
	{
		return collisions;
	}

	int getHashKey()
	{
		return hashKey;
	}

	//Function prototypes

	/*
	PRE- collects an integer version of the bday
	POST- returns an int that is the key
	PURPOSE- calculate the hascode
	*/
	int hashCode(int key);
	/*
	PRE- key - key to be cross referenced, Person to be added as value
	POST- nothing
	PURPOSE- inserts the node to the map
	*/
	void insert(int key, Person value);
	/*
	PRE- key and a string bday to compare to
	POST- nothing
	PURPOSE- searches to see if node is in map, if it is, print the name associated with person
	*/
	void search(int key, std::string bday);
	
	
};

#endif

int HashMap::hashCode(int key)
{
	//initialize sum
	int sum = 0;
	//if key > 0 or sum > 9 exit loop
	while (key > 0 || sum > 9)
	{
		//if key is 0, set sum to 0
		if (key == 0)
		{
			key = sum;
			sum = 0;
		}
		//otherwise, sum the modulus of key and current sum
		sum += key % 10;
		//then divide key by 10 for the next int to add to
		key /= 10;
	}
	//set hashkey as sum and return it
	hashKey = sum;
	return hashKey;
}

void HashMap::insert(int key, Person value)
{
	//set hashValue to the key
	int hashValue = hashCode(key);
	//set i for indexing to the hashVale
	int i = hashValue;
	//h for the number of times rehashed
	int h = 0;

	//new node ptr
	HashNode<Person> *addPtr = new HashNode<Person>;
	//set new node's attributes
	addPtr->setKey(key);
	addPtr->setValue(value);
	//std::cout << "THIS IS KEY: " << table[i].getKey() << std::endl;
	//Looking for an empty spot with the index i
	while (table[i].getValue().getName() != "")
	{
		//if i is the hashvalue and the spot is not empty, perform quadratic probing
		if ((table[i].getKey() == i) && (table[i].getValue().getName() != ""))
		{
			h++;
			i = (hashValue + (h*h)) % MAX_SIZE;
		}
		//std::cout << "COLLISION OCCURRED" << std::endl;
		//increment collisions
		collisions++;
		//if i is the hashvalue and the spot is empty, set add ptr's attributes to that node of the array
		if ((table[i].getKey() == i) && (table[i].getValue().getName() == ""))
		{
			table[i].setKey(i);
			table[i].setValue(addPtr->getValue());
			std::cout << "Key " << i << " has been inserted!" << std::endl;
			hashSize++;
			return;
		}
		//if i goes over 100, or max size of the hash table, say table is full and cannot be added rn
		if (i > 100)
		{
			std::cout << "Table is full!" << std::endl;
		}
	}
	//otherwise simply add and set addptr's valuesto that index of the table
	table[i].setKey(addPtr->getKey());
	table[i].setValue(addPtr->getValue());
	std::cout << "Key " << key << " has been inserted!" << std::endl;
	//increase the count of the size of the map
	hashSize++;	
}

void HashMap::search(int key, std::string bday)
{
	//set hashValue to the key
	int hashValue = hashCode(key);
	//set i for indexing to the hashVale
	int i = hashValue;
	//h for the number of times rehashed
	int h = 0;

	//Looking until an empty spot with the index i is found
	while (table[i].getValue().getName() != "")
	{
		//if the keymatches
		if (table[i].getKey() == i)
		{
			//if the bdays also match
			if (table[i].getValue().getBday() == bday)
			{
				//let the user know and return the name of that Person object at that place
				std::cout << "Node Found" << std::endl;
				std::cout << "Name associated with bday of " << bday << " is " << table[i].getValue().getName() << "." << std::endl;
				return;
			}
			else
			{
				//Otherwise,Quadratically probe and go to next slot for key
				h++;
				i = (hashValue + (h*h)) % MAX_SIZE;
			}

		}
	}
	//otherwise return invalid data.
	std::cout << "Invalid Data" << std::endl;
}