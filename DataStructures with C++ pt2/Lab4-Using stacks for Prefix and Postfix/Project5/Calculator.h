#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include "Queue.h"
#include "Stack.h"



class Calculator
{
private:
	Stack<char> ch;
	Stack<int> in;
	std::string postfix;
	std::string prefix;

public:


	Calculator() : postfix(""), prefix("")
	{
	}


	~Calculator()
	{
		postfix = "";
		prefix = "";
		ch.empty();
		in.empty();
		
	}


	std::string getPostfix()
	{
		return postfix;
	}

	std::string getPrefix()
	{
		return prefix;
	}

	void setPostfix(std::string po)
	{
		postfix = po;
	}

	void setPrefix(std::string pre)
	{
		prefix = pre;
	}


	/*
	PRE-  char op
	POST- true or false
	PURPOSE - Check if the char parameter is an operator. 
			  If it is an operator, then return true 
			  otherwise it will return false.
 	*/
	bool checkOperator(char op);

	/*
	PRE- char op
	POST- true  or false
	PURPOSE- Check if the char parameter is an operand.
			If it is an operand (digit) then return true
			otherwise it will return false
	*/
	bool checkOperand(char op);

	/*
	PRE-  char c
	POST- valPrecedence
	PURPOSE- Check each operator and assign a value 
			 according to its precedence.
	*/
	int highPrecedence(char c);

	/*
	PRE- a string containing infix expression
	POST- a string containing postfix expression
	PURPOSE- Conver the infix to postfix form.
	*/
	std::string infixToPostfix(std::string infix);
	
	/*
	PRE- a string containing infix expression
	POST- a string containing prefix expression
	PURPOSE- Conver the infix to prefix form.
	*/
	std::string infixToPrefix(std::string infix);

	/*
	PRE- NONE
	POST- an integer containing the result
	PURPOSE- compute the postfix expression
	*/
	int evaluatePostfix();


	/*
	PRE- NONE
	POST- an integer containing the result
	PURPOSE- compute the prefix expression
	*/
	int evaluatePrefix();
};

#endif