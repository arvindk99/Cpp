#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Stack.h"
#include "Calculator.h"
using namespace std;

bool checkFirstChar(string);
bool checkLengthofExpression(string);
bool validCharacter(string);
bool checkNumOp(string);
bool parenthesisMatch(string);
bool separatedBySpaces(string);


int main()
{
	//necessary variables for user interface
	string userInput;
	bool truth = false;
	bool exit = false;
	int options = 100;
	
	//instance of calculator class
	Calculator calc;

	//check the user inputted expression is a valid infix expression
	while (truth == false)
	{
		cout << "Enter a mathematical expression in INFIX format: ";
		getline(cin, userInput);
	
		if (checkFirstChar(userInput) == false)
		{
			cout << "The first character should be a '(' or an int value" << endl;
		}
		else if (checkLengthofExpression(userInput) == false)
		{
			cout << "The expression should contain at least 2 operands, 2 spaces, and 1 operator (5 characters)." << endl;
		}
		else if (validCharacter(userInput) == false)
		{
			cout << "You have entered an invalid character!" << endl;
		}
		else if (checkNumOp(userInput) == false)
		{
			cout << "You have put too many operators" << endl;
		}
		else if (parenthesisMatch(userInput) == false) 
		{
			cout << "There is a mismatching parenthesis" << endl;
		}
		else if (separatedBySpaces(userInput) == false) 
		{
			cout << "Remember to put a space after each operator and operand!" << endl;
		}
		else 
		{
			cout << "Expression Accepted!" << endl;
			truth = true;
		}
	}

	// Convert infix form to postfix form
	while (exit == false)
	{
		cout << "Enter 1 for Postfix, 2 for Prefix, or 0 to QUIT: ";
		cin >> options;

		if (options == 1)
		{
			// Convert infix form to postfix form and output the result
			calc.infixToPostfix(userInput);
			cout << "Postfix Form: " << calc.getPostfix() << endl;
			cout << "RESULT: " << calc.evaluatePostfix() << endl;
		}
		else if (options == 2)
		{
			// Convert infix form to prefix form and output the result
			calc.infixToPrefix(userInput);
			cout << "Prefix Form: " << calc.getPrefix() << endl;
			cout << "RESULT: " << calc.evaluatePrefix() << endl;
		}
		else if (options == 0)
		{
			//if chosen 0, just quit
			cout << "GOODBYE!!" << endl;
			exit = true;
		}
		else
		{
			cout << "Invalid choice!" << endl;
		}
	}

	system("pause");
	return 0;
}



/*
Pre - string input
Post - true or false
Purpose - Check if there  are spaces between each operator and operand
*/
bool separatedBySpaces(string input)
{
	int iterator = 0;
	// iterate through string
	while (iterator < input.length())
	{
		//when iterator reaches the end, return true
		if (iterator + 1 == input.length())
		{
			return true;
		}
		else
		{
			//check if it's an int, and what the following character is, if it's another int, or space, continue, otherwise false
			if (isdigit(input[iterator]))
			{
				if (isdigit(input[iterator + 1]))
				{
					iterator++;

				}
				else if (input[iterator + 1] == ' ' || input[iterator + 1] == '(' || input[iterator + 1] == ')')
				{
					iterator++;
				}

				else if (input[iterator + 1] == '+' || input[iterator + 1] == '-' || input[iterator + 1] == '*' || input[iterator + 1] == '/' || input[iterator + 1] == '%')
				{
					return false;
				}
			}
			//check if it's an operator, and what the following character is, if it's a space, continue, otherwise false
			else if (input[iterator] == '+' || input[iterator] == '-' || input[iterator] == '*' || input[iterator] == '/' || input[iterator] == '%')
			{
				if (isdigit(input[iterator + 1]))
				{
					return false;
				}
				else if (input[iterator + 1] == ' ' || input[iterator + 1] == '(' || input[iterator + 1] == ')')
				{
					iterator++;
				}
				else if(input[iterator + 1] == '+' || input[iterator + 1] == '-' || input[iterator + 1] == '*' || input[iterator + 1] == '/' || input[iterator + 1] == '%')
				{
					return false;
				}
			}
			//continue to the next character in string
			else
			{
				iterator++;
			}
		}
	}
	return true;
}


/*
Pre - string with the user input
Post - true or false
Purpose - CHECK IF THE CHAACTERS ARE VALID
*/
bool validCharacter(string input)
{
	//iterate through whole string input and make sure if it's a binary operator or an int, otherwise false
	for (int i = 0; i < input.length(); i++)
	{

		if (isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '(' || input[i] == ')')
		{
			continue;
		}
		else if (input[i] == ' ')
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	return true;
}


/*
Pre - string with the user input
Post - true or false
Purpose - check if there are at least three characters
*/
bool checkLengthofExpression(string input)
{
	//make sure the length of the string is at least 5 characters
	if (input.length() < 5)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*
Pre - string with the user input
Post - true or false
Purpose - CHeck if open parenthesis and close parenthesis match
*/
bool parenthesisMatch(string input)
{
	//create a local stack for parantheses
	Stack<char> parenthesesStack;
	//iterate through string
	for (int i = 0; i < input.length(); i++)
	{
		//everytime we have a open parantheses ===> push
		if (input[i] == '(')
		{
			parenthesesStack.push(input[i]);
		}
		//everytime we have a close parantheses ===> pop until stack.peek() == '(';
		else if (input[i] == ')')
		{
			//if at anytime the count of closed parantheses>open parantheses
			if (parenthesesStack.isEmpty())
			{
				return false;
			}
			parenthesesStack.pop();
		}
		//continue if operand or operator
		else
		{
			continue;
		}
	}

	//at the end if there are any characters left in stack return false
	if (!parenthesesStack.isEmpty())
	{
		return false;
	}
	//else true
	return true;
		
}



/*
Pre - string with the user input
Post - true or false
Purpose - check if number of operators < number of operands
*/
bool checkNumOp(string input)
{
	//two int variables corresponding to the number of operators and operands
	int numOperator = 0, numOperands = 0;
	//iterate through the string
	for(int i = 0; i < input.length(); i ++)
	{
		//if it's an int, increment numOperands
		if (isdigit(input[i])) 
		{
			numOperands++;
		}
		//if it's an operator, then increment numOperator
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%')
		{
			numOperator++;
		}
		//if it's a space, just continue past it
		else if (input[i] == ' ')
		{
			continue;
		}
	}
	//if the number of operators are greater than the number of int, return false
	if (numOperator >= numOperands)
	{
		return false;
	}
	return true;
}


/*
Pre - string with the user input
Post - true or false
Purpose - check if first character is an integer or a open parantheses
*/
bool checkFirstChar(string input) 
{
	//return true if the first character is an opening paranthesis or an int
	if (isdigit(input[0]) || input[0] == '(') 
	{
		return true;
	}
	//Give them a warning if they added an extra space at the beginning, then continue over it
	else if (input[0] == ' ')
	{
		cout << "WARNING: Started expression with space!" << endl;
		if (isdigit(input[1]) || input[1] == '(')
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}
