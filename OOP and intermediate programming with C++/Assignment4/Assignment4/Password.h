//
//  Password.h
//  Assignment4
//
//  Created by Arvind Kumar on 2/10/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#ifndef Password_h
#define Password_h
#include <cctype>
#include <string.h>
using namespace std;

class Password
{
private:
    char* password;
    unsigned int length;
public:
    Password(char pw[]);
    bool checkLength();
    bool upperCase();
    bool lowerCase();
    bool checkInt();
    bool checkPunct();
    bool validPassCheck();
    
};

/*
 PRE- collects an array of characters
 POST- nothing
 PURPOSE- Constructor for the Password class
 */
Password::Password(char pw[])
{
    length = strlen(pw);
    password = new char[length];
    for(int i=0; i<length; i++)
    {
        password[i] = pw[i];
    }
}

/*
PRE- nothing
POST- boolean value
PURPOSE- returns a boolean value based on if the c-string
        is between 6 and 20 characters
*/
bool Password::checkLength()
{
    if(length >= 6 && 20 >= length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
PRE- nothing
POST- boolean value
PURPOSE- returns a boolean value based on if the c-string
        contains at least one upper case letter
*/
bool Password::upperCase()
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            count++;
        }
    }
    if(count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
PRE- nothing
POST- boolean value
PURPOSE- returns a boolean value based on if the c-string
        contains at least one lower case letter
*/
bool Password::lowerCase()
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(islower(password[i]))
        {
            count++;
        }
    }
    if(count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
PRE- nothing
POST- boolean value
PURPOSE- returns a boolean value based on if the c-string
        contains at least one digit
*/
bool Password::checkInt()
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(isdigit(password[i]))
        {
            count++;
        }
    }
    if(count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
PRE- nothing
POST- boolean value
PURPOSE- returns a boolean value based on if the c-string
        contains at least one punctuation
*/
bool Password::checkPunct()
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(ispunct(password[i]))
        {
            count++;
        }
    }
    if(count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
PRE- nothing
POST- boolean value
PURPOSE- returns a boolean value based on if the c-string
        meets all requirements
*/
bool Password::validPassCheck()
{
    if(checkLength() == false)
    {
        cout << "ERROR! Password should be between 6 and 20 characters!" << endl;
        return false;
    }
    if(upperCase()== false)
    {
        cout << "ERROR! Password should contain at least one uppercase letter!" << endl;
        return false;
    }
    if(lowerCase()== false)
    {
        cout << "ERROR! Password should contain at least one lowercase letter!" << endl;
        return false;
    }
    if(checkInt()== false)
    {
        cout << "ERROR! Password should contain at least one digit!" << endl;
        return false;
    }
    if(checkPunct() == false)
    {
        cout << "ERROR! Password should contain at least one punctuation character!" << endl;
        return false;
    }
    
    return true;
        
}

#endif /* Password_h */
