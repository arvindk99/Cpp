//
//  main.cpp
//  HW10
//
//  Created by Arvind Kumar on 3/10/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#include <iostream>
#include <string>
#include "StringList.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //Create an instance of the StringList
    StringList strList;
    //instantiate an int for options
    int options = -1;
    //instantiate a bool regarding whether the user has quit or not
    bool quit = false;
    //first name and last name for input
    string fName, lName;
    
    //while the user has not quit
    while(quit == false)
    {
        //prompt and take input for an option
        cout << "Enter (1) to insert to the list, (2) to display List, or (0) to quit: ";
        cin >> options;
        
        //if 1, collect first and last name and then use insertNode to add to the list
        if(options == 1)
        {
            cout << "Enter the First name of the Person: ";
            cin >> fName;
            cout << "Enter the Last name of the Person: ";
            cin >> lName;
            strList.insertNode(fName,lName);
        }
        //if 2, use displayList to print out list
        else if(options == 2)
        {
            cout << "List of people!" << endl;
            strList.displayList();
        }
        //if 3, quit out of loop and say goodbye
        else if(options == 0)
        {
            cout << "GOODBYE!" << endl;
            quit = true;
        }
        //Otherwise inform of invalid option
        else
        {
            cout << "INVALID OPTION!" << endl;
        }
    }

    return 0;
}

/*
 Enter (1) to insert to the list, (2) to display List, or (0) to quit: 1
 Enter the First name of the Person: Eric
 Enter the Last name of the Person: Yu
 Enter (1) to insert to the list, (2) to display List, or (0) to quit: 1
 Enter the First name of the Person: Arvind
 Enter the Last name of the Person: Kumar
 Enter (1) to insert to the list, (2) to display List, or (0) to quit: 1
 Enter the First name of the Person: Gurshaan
 Enter the Last name of the Person: Bariana
 Enter (1) to insert to the list, (2) to display List, or (0) to quit: 1
 Enter the First name of the Person: Seema Kumar
 Enter the Last name of the Person: Enter (1) to insert to the list, (2) to display List, or (0) to quit: 2
 List of people!
 Gurshaan Bariana
 Arvind Kumar
 Seema Kumar
 Eric Yu
 Enter (1) to insert to the list, (2) to display List, or (0) to quit: 0
 GOODBYE!
 Program ended with exit code: 0
 
 */
