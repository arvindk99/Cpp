// Kevin Lam 
// Arvind Kumar 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "TemplateClass.h"

using namespace std;

// Function prototype
template <class T >
void RecurSelectionSort(TemplateClass<T>, int, int);

template <class T >
void swap(T*, T*);


int main()
{
	// Max size of array constant
	const int SORT_MAX_SIZE = 16;

	// Declare variables
	int numElement;
	string typeData;

	bool valid = false;
	while (!valid)
	{
		try
		{
			// Ask the user for number of elements
			cout << "Enter the number the elements you want to input (Max is 16): ";
			cin >> numElement;

			// If user input exceed max size throw exception
			if (numElement > SORT_MAX_SIZE)
			{
				string error = "Number of elements exceeds the max size!";
				throw error;
			}
			// If user input is less than 0
			else if (numElement < 0)
			{
				string error = "Number of element can't be less than 0";
				throw error;
			}
			// If user input is valid exit the loop
			else
			{
				valid = true;
			}
		}
		catch (string error)
		{
			cout << error << endl;
		}
	}

	valid = false;
	while (!valid)
	{
		try {
			// Ask the user for type of data
			cout << "Enter the type of data (int, string, Dollar): ";
			cin >> typeData;

			// Lowercase the user input
			for (int index = 0; index < typeData.length(); index++)
			{
				typeData[index] = tolower(typeData[index]);
			}

			// If user input is valid exit
			if (typeData == "int" || typeData == "string" || typeData == "dollar")
			{
				valid = true;
			}

			// If user input is not one of the three options throw exception
			else
			{
				string error = "Invalid input. Please enter one of the options";
				throw error;
			}
		}
		catch (string error)
		{
			cout << error << endl;
		}
	}

	// User inputs int for dataType 
	if (typeData == "int")
	{
		TemplateClass<int> arr(numElement);
		cin >> arr;
		RecurSelectionSort(arr, 0, numElement);
	}
	else if (typeData == "string")
	{
		TemplateClass<string> arr(numElement);
		cin >> arr;
		RecurSelectionSort(arr, 0, numElement);
	}

	// User inputs Dollar for dataType
	system("pause");
	return 0;
}


//******************************************************************
//* PRE - Collects two pointers to two template arrays
//* POST - None
//* PURPOSE - swaps the values of the array of the index
//******************************************************************
template <class T >
void swap(T* arrayElem1, T* arrayElem2)
{
	T temp = *arrayElem1;
	*arrayElem1 = *arrayElem2;
	*arrayElem2 = temp;
}


//******************************************************************
//* PRE - Collects a template array, and two integers, marking the 
//* starting index, and the size of the array
//*
//* POST - None, prints out the sorted array after each step
//*
//* PURPOSE - Recursively sort the array that the user has inputted
//******************************************************************

template <class T >
void RecurSelectionSort(TemplateClass<T> arr, int index, int size)
{
	fstream outFile;
	outFile.open("log.txt", ios::out);

	cout << arr;
	outFile << arr;

	int min = index;
	for (int j = index + 1; j < size; j++)
	{
		if (arr[j] < arr[min])
			min = j;
	}

	swap(arr[min], arr[index]);

	if (index + 1 < size) {
		//printing each step
		// PRINT OUT to FILE
		//cout << arr << endl;

		RecurSelectionSort(arr, index + 1, size);
	}

	outFile.close();
}