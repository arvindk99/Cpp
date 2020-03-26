#include <iostream>
#include <fstream>
#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H

template <class U> class TemplateClass;
template <class T >
class TemplateClass
{
private:
	int numElement;
	T* pointerArr;

public:
	// Default Constructor
	TemplateClass();

	// Constructor
	TemplateClass(int);

	// Destructor
	~TemplateClass();

	// Accessor  
	int getNumElement();

	// Operator Overloading
	T& operator[](int index);

	//******************************************************** 
	//* Erase 
	//******************************************************** 
	void Erase();

	//******************************************************** 
	//* Operator<
	//******************************************************** 
	bool operator<(TemplateClass& tempArr);

	//******************************************************** 
	//* Operator <<
	//******************************************************** 
	template <class U>
	friend std::ostream& operator<<(std::ostream&, TemplateClass<U>&);

	//******************************************************** 
	//* Operator <<
	//******************************************************** 
	template <class U>
	friend std::istream& operator>>(std::istream&, TemplateClass<U>&);
};
#endif

//******************************************************************
// Default Constructor
//******************************************************************
template <class T>
TemplateClass<T>::TemplateClass()
{
	pointerArr = 0;
	numElement = 0;
}

//******************************************************************
// Constructor 
//******************************************************************
template <class T>
TemplateClass<T>::TemplateClass(int numElem)
{
	pointerArr = new T[numElem];
	numElement = numElem;
}

//******************************************************************
//* Destructor
//******************************************************************
template <class T>
TemplateClass<T>::~TemplateClass()
{
	delete[] pointerArr;
}

//******************************************************************
//* Accessor
//******************************************************************
template <class T>
int TemplateClass<T>::getNumElement()
{
	return numElement;
}

//******************************************************************
//* Overloaded Operator
//******************************************************************
template <class T>
T& TemplateClass<T>::operator[](int index)
{
	if (index >= 0 && index < numElement)
	{
		return pointerArr[index];
	}
}

//******************************************************************
//* Erase method
//******************************************************************
template <class T>
void TemplateClass<T>::Erase()
{
	delete[] pointerArr;
	pointerArr = 0;
	numElement = 0;
}

//******************************************************************
//* Compare Overloaded Operator
//******************************************************************
template <class T>
bool TemplateClass<T>::operator<(TemplateClass& tempArr)
{
	bool cmp;
	if (tempClass.pointerArr < pointerArr)
	{
		cmp = true;
	}
	else
	{
		cmp = false;
	}
	return cmp;
}

//******************************************************************
//* Output Overloaded Operator
//******************************************************************
template <class U>
std::ostream& operator<<(std::ostream& out, TemplateClass<U>& tempArr)
{
	for (int index = 0; index < tempArr.getNumElement(); index++)
	{
		out << tempArr.pointerArr[index] << " ";
	}

	out << endl;
	return out;
}


//******************************************************************
//* Input Overloaded Operator
//******************************************************************
template <class U>
std::istream& operator>>(std::istream& in, TemplateClass<U>& tempArr)
{
	for (int index = 0; index < tempArr.getNumElement(); index++)
	{
		cout << "Enter a value: ";
		in >> tempArr.pointerArr[index];
	}
	return in;
}