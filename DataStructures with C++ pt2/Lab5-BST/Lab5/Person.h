/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <string>

class Person
{
private:
	std::string name;
	std::string bday;
	std::string* pkey;
public:
	// Default Constructor 
	Person() : name(""), bday(""), pkey(nullptr)
	{}

	// Argument Constructor
	Person(std::string n, std::string b, std::string type)
		: name(n), bday(b)
	{
		// If person is created for name
		if (type =="name")
		{
			pkey = new std::string(name);
		}

		// If person is created for bday
		else
		{
			pkey = new std::string(bday);
		}		
	}


	//*********************************
	//* Function name: setName
	//* Pre - std::string n
	//* Pos - None
	//* Purpose - set name to n
	//*********************************
	void setName(std::string n) { name = n; }

	//*********************************
	//* Function name: setBday
	//* Pre - std::string b
	//* Pos - return
	//* Purpose - set bday to b
	//*********************************
	void setBday(std::string b) { bday = b; }

	//*********************************
	//* Function name: setPkey
	//* Pre - std::string* p
	//* Pos - None
	//* Purpose - set pkey to p parameter
	//*********************************
	void setPkey(std::string p)
	{
		if (p == "name")
		{
			pkey = new std::string(name);
		}

		else
		{
			pkey = new std::string(bday);
		}
	}

	//*********************************
	//* Function name: getName
	//* Pre - None
	//* Pos - name
	//* Purpose - return name
	//*********************************
	std::string getName() { return name; }

	//*********************************
	//* Function name: getBday
	//* Pre - None
	//* Pos - bday
	//* Purpose = return bday
	//*********************************
	std::string getBday() { return bday; }

	//*********************************
	//* Function name: getPkey
	//* Pre - None
	//* Pos - pkey
	//* Purpose - return pkey
	//*********************************
	std::string* getPkey() { return pkey; }

	//*********************************
	//* Function name: operator>
	//* Pre - const Person& p
	//* Pos - 
	//* Purpose - compares data based on
	//*           pkey if greater than
	//*********************************
	bool operator>(const Person &p)
	{
		if (*pkey > *p.pkey)
			return true;
		return false;
	}

	//*********************************
	//* Function name: operator<
	//* Pre - const Person& p
	//* Pos - name
	//* Purpose - compare data based on pkey
	//*			  if less than
	//*********************************
	bool operator<(const Person& p) 
	{
		if ( *pkey < *p.pkey)
			return true;
		return false;
	}

	//*********************************
	//* Function name: operator==
	//* Pre - const Person& p
	//* Pos - name
	//* Purpose - compare data based on pkey
	//*           if equal
	//*********************************
	bool operator==(const Person& p)
	{
		if (*pkey == *(p.pkey))
			return true;
		return false;
	}

	//*********************************
	//* Function name: operator>>
	//* Pre - std::istream &in, Person& p
	//* Pos - in
	//* Purpose - Ask the user for the name
	//*           and birthday
	//*********************************
	friend std::istream& operator>>(std::istream &in, Person& p)
	{
		//Prompt user for name
		std::cout << "Enter the first and last name of the Person: ";
		std::getline(in, p.name);

		//Prompt user for bday
		std::cout << "Enter the bday in the format yyyy-mm-dd: ";
		in >> p.bday;

		return in;
	}

	//*********************************
	//* Function name: operator<<
	//* Pre - std::ostream &out, Person& p
	//* Pos - out
	//* Purpose - output name and bday
	//*********************************
	friend std::ostream& operator<<(std::ostream &out, Person& p)
	{
		out << std::left << std::setw(60) << p.name
			<< std::right << std::setw(20) << p.bday << std::endl;
		return out;
		// print to console and file 
	}
};

#endif 