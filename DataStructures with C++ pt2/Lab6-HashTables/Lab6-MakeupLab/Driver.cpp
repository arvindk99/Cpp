//
//  Driver.cpp
//  Lab6-Makeup
//	Arvind Kumar ID:20372024
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "HashNode.h"
#include "Person.h"
#include "HashMap.h"
using namespace std;

//Function prototypes for 
bool validDate(string);
bool validName(string);

int main()
{
	//Necessary attributes for input file recovery
	string inputDirectory;
	ifstream inFile;

	//Necessary attributes for collecting and setting data
	string name;
	string bday;
	char ch = '\n';

	//Misc. data attributes for looping
	int count = 0;
	bool quit = false;

	//Creating an instance of the hashmap
	HashMap hashMap;

	//Collecting input for directory for input file
	cout << "Enter the directory for the file containing the data: " << endl;
	cin >> inputDirectory;

	//open input file
	inFile.open(inputDirectory);
	//If the file doesn't exist, let user know
	if (inFile.fail() == 1)
	{
		cout << "No such file!" << endl;
	}
	else
	{
		//Until the end of the file is reached
		while (!inFile.eof())
		{
			//Create a temporary Person object
			Person tempPerson;
			//Create a temporary bday string object to store stripped bday string
			string tempBday = "";
			//collect name
			getline(inFile, name);
			//collect bday
			inFile >> bday;
			//skip whitespace
			inFile.get(ch);


			//If bday and Name are both valid, move on
			if (validDate(bday) == true && validName(name) == true)
			{
				//set the bday and name attributes of the tempPerson
				tempPerson.setBday(bday);
				tempPerson.setName(name);

				//strip the bday string of the dashes and put it in the new tempbday string
				for (int i = 0; i < bday.length(); i++)
				{
					if (i == 4 || i == 7)
					{
						continue;
					}

					else
					{
						tempBday += bday[i];
					}
				}
				//convert tempBday to int
				int bd = stoi(tempBday);
				//outputting the info of the individual
				cout << "NAME: " << setw(40) << left << name << "BDAY: " << setw(10) << left << bday << endl;
				//get the key using the bday int
				int bdKey = hashMap.hashCode(bd);
				//insert the temp person to the map
				hashMap.insert(bdKey, tempPerson);
			}
		}
		//Print out the size, collisions, and the load factor of the hash Map
		cout << "Size: " << hashMap.getHashSize() << endl;
		cout << "Collisions: " << hashMap.getCollisions() << endl;
		cout << "Load Factor: " << hashMap.getHashSize() << " out of 100 space." << endl;
		
		//Loop for option menu
		while (quit == false)
		{
			//necessary attributes for input and option menu
			string bdaySearch;
			int options = -1;
			string tempBdaySearch;
			//if count is 0, meaning it's the first time running through the loop
			if (count == 0)
			{
				//Prompt user for a bday input
				cout << "Enter a bday to look for! (YYYY-MM-DD)" << endl;
				cin >> bdaySearch;
				//validdate the date
				if (validDate(bdaySearch) == false)
				{
					cout << "INVALID DATE INPUT" << endl;
					//count goes up
					count++;
				}
				//otherwise, manipulate string to int and into key for searching
				else
				{
					for (int i = 0; i < bdaySearch.length(); i++)
					{
						if (i == 4 || i == 7)
						{
							continue;
						}

						else
						{
							tempBdaySearch += bdaySearch[i];
						}
					}
					int bd = stoi(tempBdaySearch);
					int bdKey = hashMap.hashCode(bd);
					//call the search method to look 
					hashMap.search(bdKey, bdaySearch);
					//count goes up
					count++;
				}

			}
			//If not the first time looping through
			else
			{
				//Option menu, 1 to search again, 2 to quit, prompt for options
				cout << "Enter (1) to look again, or (2) to quit!" << endl;
				cin >> options;
				//if 1, do everything in the previous if statement again
				if (options == 1)
				{
					cout << "Enter a bday to look for! (YYYY-MM-DD)" << endl;
					cin >> bdaySearch;
					if (validDate(bdaySearch) == false)
					{
						cout << "INVALID DATE INPUT" << endl;
						count++;
					}
					else
					{
						for (int i = 0; i < bdaySearch.length(); i++)
						{
							if (i == 4 || i == 7)
							{
								continue;
							}

							else
							{
								tempBdaySearch += bdaySearch[i];
							}
						}
						int bd = stoi(tempBdaySearch);
						int bdKey = hashMap.hashCode(bd);
						hashMap.search(bdKey, bdaySearch);
						count++;
					}
				}
				//Otherwise say Goodbye and quit program
				else if (options == 2)
				{
					cout << "GoodBye!" << endl;
					quit = true;
				}

				else
				{
					cout << "Invalid Option!" << endl;
				}
			}

		}
	}



	system("pause");
	return 0;
}



/*
PRE- string name- name to be validated
POST- bool value regarding valid or invalid name
PURPOSE- Checks if string is valid name
*/
bool validName(string name)
{
	int count = 0;
	//check if there are two strings
	for (int i = 0; i < name.length(); i++)
	{
		if (isalpha(name[i]) || name[i] == ' ' || name[i] == '-' || name[i] == '\'')
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	// Makes sure there's two separate strings
	for (int a = 0; a < name.length(); a++)
	{
		if (name[a] == ' ')
		{
			count++;
		}
		else
		{
			continue;
		}
	}
	if (count < 1)
	{
		return false;
	}
	return true;
}



/*
PRE- string date- bday date to be validated
POST- bool value regarding valid or invalid date
PURPOSE- Checks if string is valid date
*/
bool validDate(string date)
{
	int month = 0;
	int year = 0;
	int day = 0;

	//check if there are any invalid variables in the date string
	for (int i = 0; i < date.length(); i++)
	{
		if (isdigit(date[i]) || date[i] == '-')
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	//make sure length of date is the right number of characters
	if (date.length() < 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}
	year = stoi(date.substr(0, 4));
	month = stoi(date.substr(5, 2));
	day = stoi(date.substr(8));

	//make sure year isnt newer than 2019
	if (year > 2019 && month >3 && day > 2)
	{
		return false;
	}
	//make sure month isn't larger than 12
	if (month > 12)
	{
		return false;
	}

	//make sure day isn't larger than 31 or 30 or 28 or 29
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
		{
			return false;
		}
	}
	// Check if it is a leap year
	if (month == 2 && year % 4 == 0)
	{
		if (day > 29)
		{
			return false;
		}
	}
	// If it is not a leap year
	if (month == 2 && year % 4 != 0)
	{
		if (day > 28)
		{
			return false;
		}
	}
	// Check if there's 31 days for these months
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			return false;
		}
	}
	return true;
}
