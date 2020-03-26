/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include "Person.h"
#include "LinkedBST.h"
#include "BSTNode.h"

using namespace std;

bool validDate(string);
bool validName(string);

int main()
{
	//attributes for file manipulation
	string inputDirectory;
	string outputDirectory;
	string outputDirectory1;
	ifstream inFile;
	ofstream nameOut;
	ofstream bdayOut;
	string nameO;
	string bdayO;

	//attributes for reading inputs
	string name;
	string bday;
	char ch = '\n';

	//Misc. attributes
	int count = 0;
	int options = -1;
	bool quit = false;
	int printed = 0;

	//Two trees
	LinkedBST<Person> bdayTree;
	LinkedBST<Person> nameTree;



	//Collect file directory for txt file
	cout << "Enter the directory for the file containing the data: ";
	cin >> inputDirectory;

	cout << "Enter the directory for the file you would like to output your name tree to.";
	cin >> nameO;
	nameOut.open(nameO);

	cout << "Enter the directory for the file you would like to output your bday tree to.";
	cin >> bdayO;
	bdayOut.open(bdayO);

	//open input file
	inFile.open(inputDirectory);

	//Check if the file exists
	if (inFile.fail() == 1)
	{
		cout << "No such File!" << endl;
	}
	else
	{
		while (!inFile.eof())
		{
			//Create Person Objects
			Person tempPerson;

			//collect the input
			getline(inFile, name);
			inFile >> bday;
			inFile.get(ch);

			//name validation
			if (validName(name) == false)
			{
				cout << "\'" << name << "\' WAS AN INVALID INPUT" << endl;
				name = "INVALID NAME";
			}
			//date validation
			if (validDate(bday) == false)
			{
				cout << "\'" << bday << "\' WAS AN INVALID INPUT" << endl;
				bday = "INVALID BDAY";
			}
			string *namePtr = &name;
			string *bdayPtr = &bday;

			tempPerson.setBday(bday);
			tempPerson.setName(name);
			
			//populate Person nodes
			tempPerson.setPkey("name");
			nameTree.insertNode(tempPerson);

			//Create duplicate person nodes	
			tempPerson.setPkey("bday");
			bdayTree.insertNode(tempPerson);
		
		}

		while (quit == false)
		{
			// Print that data has been added 
			// Ask the user for an options
			cout << "Data from " << inputDirectory << " has been added to the trees." << endl
				<< "Choose one of the following options (input number corresponding to the desired option)" << endl
				<< "1.) Add a node" << endl
				<< "2.) Search for a node" << endl
				<< "3.) Delete a node" << endl
				<< "4.) Print out the trees" << endl
				<< "5.) Quit from the program and print current statuses of trees." << endl
				<< "YOUR CHOICE: " << endl;
			cin >> options;

			// If user choose 1
			if (options == 1)
			{
				Person localPerson;
				string fname;
				string lName;
				string totalName;
				string lBday;

				// Ask the user to enter the birthday
				cout << "Enter the bday in yyyy-mm-dd format: ";
				cin >> lBday;

				// Ask the user for the name
				cout << "Enter the first and last name of the Person: ";
				cin >> fname;
				cin >> lName;

				totalName = fname + ' ' + lName;

				// Check if the name is valid
				if (validName(totalName) == false)
				{
					cout << "\'" << totalName << "\' WAS AN INVALID INPUT" << endl;
					lName = "INVALID NAME";
				}
				// Check if the birthday is valid
				if (validDate(lBday) == false)
				{
					cout << "\'" << lBday << "\' WAS AN INVALID INPUT" << endl;
					lBday = "INVALID BDAY";
				}

				// set the birthday and name
				localPerson.setBday(lBday);
				localPerson.setName(totalName);

				// define pointers for name and bday
				string *namePtr = &totalName;
				string *bdayPtr = &lBday;

				// set the pkey pointer
				localPerson.setPkey("name");
				nameTree.insertNode(localPerson);

				//set the pkey pointer 
				localPerson.setPkey("bday");
				bdayTree.insertNode(localPerson);

				cout << totalName << " has been added to the corresponding trees, and OUTPUT FILES HAVE BEEN CLEARED!" << endl;
				printed = 0;
			}
			// If user chooses option 2 
			if (options == 2)
			{
				Person tP;
				string lf;
				string ll;
				string lt;
				string lb;

				// Ask the user for the first and last name 
				cout << "Enter a first and last name for the person you want to look for: ";
				cin >> lf;
				cin >> ll;
				lt = lf + ' ' + ll;

				// Ask the user for the birthdate
				cout << "Enter the bday of the person you want to look for in format yyyy-mm-dd: ";
				cin >> lb;

				// set Bday and name
				tP.setBday(lb);
				tP.setName(lt);

				// create pointers for name and bdat
				string *namePtr = &lt;
				string *bdayPtr = &lb;

				// set the pkey pointer
				tP.setPkey("name");
				
				// check if the value is found in the BST
				if (nameTree.search(tP) == true)
				{
					cout << tP.getName() << " has been found in the name tree!" << endl;
				}
				// if value is not found in the BST
				else
				{
					cout << "Could not find this person in name tree!" << endl;
				}

				tP.setPkey("bday");
				// check if value is found the BST
				if (bdayTree.search(tP) == true)
				{
					cout << tP.getName() << " has been found in the bday tree!" << endl;
				}
				// if value is not found in the BST
				else
				{
					cout << "Could not find this person in bday tree!" << endl;
				}
			}
			// if user chooses option 3
			if (options == 3)
			{
				Person temp;
				string fn;
				string ln;
				string tn;
				string bd;

				// Ask the user for the first and last name 
				cout << "Enter first and last name of the person you want to delete: ";
				cin >> fn;
				cin >> ln;
				tn = fn + ' ' + ln;

				// Ask the user for the birthdate
				cout << "Enter the bday in format yyyy-mm-dd: ";
				cin >> bd;

				// set bday and name
				temp.setBday(bd);
				temp.setName(fn);

				// create the name pointer and bday pointer
				string *namePtr = &tn;
				string *bdayPtr = &bd;

				// set the pkey
				temp.setPkey("name");
				nameTree.remove(temp);

				// set the pkey
				temp.setPkey("bday");
				bdayTree.remove(temp);

				printed = 0;
			}

			// If user chooses option 4
			if (options == 4)
			{
				if (printed > 0)
				{
					continue;
				}
				else
				{
					cout << "Printing to corresponding locations!" << endl;
					cout << "***************NAME TREE IN PREORDER**************" << endl;
					nameOut << "***************NAME TREE IN PREORDER**************" << endl;
					nameTree.preOrder();
					nameTree.print(2, nameOut);
					cout << "***************NAME TREE IN POSTORDER*************" << endl;
					nameOut << "***************NAME TREE IN PREORDER**************" << endl;
					nameTree.postOrder();
					nameTree.print(3, nameOut);


					cout << endl << endl;
					cout << "***************BDAY TREE IN INORDER**************" << endl;
					bdayOut << "*****************BDAY TREE IN INORDER************" << endl;
					bdayTree.inOrder();
					bdayTree.print(1, bdayOut);
					cout << "***************BDAY TREE IN BREADTH FIRST*************" << endl;
					bdayOut << "*****************BDAY TREE IN BREADTH FIRST************" << endl;
					bdayTree.breadthFirst();
					bdayTree.print(4, bdayOut);

					printed++;
				}
				

			}
			// If user chooses option 5
			if (options == 5)
			{
				if (printed > 0)
				{
					quit = true;	
				}
				else
				{
					cout << "Printing to corresponding locations!" << endl;
					cout << "***************NAME TREE IN PREORDER**************" << endl;
					nameOut << "***************NAME TREE IN PREORDER**************" << endl;
					nameTree.preOrder();
					nameTree.print(2, nameOut);
					cout << "***************NAME TREE IN POSTORDER*************" << endl;
					nameOut << "***************NAME TREE IN PREORDER**************" << endl;
					nameTree.postOrder();
					nameTree.print(3, nameOut);

					cout << endl << endl;
					cout << "***************BDAY TREE IN INORDER**************" << endl;
					bdayOut << "*****************BDAY TREE IN INORDER************" << endl;
					bdayTree.inOrder();
					bdayTree.print(1, bdayOut);
					cout << "***************BDAY TREE IN BREADTH FIRST*************" << endl;
					bdayOut << "*****************BDAY TREE IN BREADTH FIRST************" << endl;
					bdayTree.breadthFirst();
					bdayTree.print(4, bdayOut);

					printed++;
					quit = true;
				}
			}
		}
	}

	// Close the output file
	nameOut.close();
	bdayOut.close();
	system("pause");
	return 0;
}

// Check if the name is valid
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

//CHECK FOR VALID DATE METHOD
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
	if (date.length() < 10 || date[4] != '-' || date[7]!='-')
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




