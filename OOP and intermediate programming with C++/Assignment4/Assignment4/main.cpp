//
//  main.cpp
//  Assignment4
//
//  Created by Arvind Kumar on 2/10/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//
#include <cctype>
#include <iostream>
#include "Password.h"
using namespace std;

int main(int argc, const char * argv[])
{
    //Creating a boolean variable for the while loop
    bool t = true;
    
    //Looping so that the password prompt is repeated until
    //valid password is entered
    while(t)
    {
        //Creating an array of characters for the password to be stored
        char pWord[100];
        cout << "Enter Password: ";
        cin >> pWord;
        //Creating an instance of the Password class with the pWord array
        Password passTest(pWord);
        //Check if it passes all requirements, if it does, accept password
        if(passTest.validPassCheck())
        {
            cout << "Password Accepted" << endl;
            t = false;
        }
    }
    return 0;
}


/*
 Enter Password: arvind!@#
 ERROR! Password should contain at least one uppercase letter!
 Enter Password: ARVIND!23
 ERROR! Password should contain at least one lowercase letter!
 Enter Password: arvind!23
 ERROR! Password should contain at least one uppercase letter!
 Enter Password: Arvind!@#
 ERROR! Password should contain at least one digit!
 Enter Password: Arvind!23
 Password Accepted
 Program ended with exit code: 0
 */
