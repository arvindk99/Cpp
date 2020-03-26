#include "Calculator.h"


bool Calculator::checkOperator(char op)
{
	//check if it is one of the binary operators
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
	{
		//if so true
		return true;
	}
	//otherwise false
	return false;
}

bool Calculator::checkOperand(char op)
{
	//check if op is an integer
	if (isdigit(op))
	{
		//if so true
		return true;
	}
	//else false
	return false;
}

int Calculator::highPrecedence(char op)
{
	int valPrecedence;
	//check if op is *, /, or %
	if (op == '*' || op == '/' || op == '%')
	{
		//if so set valPrecedence to 2
		valPrecedence = 2;
	}
	//Check if op is + or -
	else if (op == '+' || op == '-')
	{
		//if so set valPrecedence to 1
		valPrecedence = 1;
	}
	else
	{
		//Anything else is 0
		valPrecedence = 0;
	}

	return valPrecedence;
}

std::string Calculator::infixToPostfix(std::string infix)
{
	//set postfix to empty string
	postfix = "";
	//iterate through the string
	for (int index = 0; index < infix.length(); index++)
	{
		//if operator
		if (checkOperator(infix[index]) == true)
		{
			//check precedence
			while (ch.isEmpty() != true && highPrecedence(infix[index]) <= highPrecedence(ch.peek()))
			{
				//add the top value to postfix
				char c = ch.peek();
				ch.pop();
				postfix = postfix + c + ' ';
			}
			//push rest to stack
			ch.push(infix[index]);
		}

		// If an opening parenthesis then push it onto the stack
		else if (infix[index] == '(')
		{
			ch.push(infix[index]);
		}

		//check if it's an int
		else if (checkOperand(infix[index]))
		{
			//check if the next one is also an int, if it is add current value to postfix
			if (isdigit(infix[index + 1]))
			{
				postfix += infix[index];
			}
			//if not add current value and a space at the end of postfix
			else
			{
				postfix = postfix + infix[index] + ' ';
			}
		}

		//if a closig paranthesis then pop and add to postfix until '(' or stack is empty
		else if (infix[index] == ')')
		{
			while (!ch.isEmpty() && ch.peek() != '(')
			{
				char c = ch.peek();
				ch.pop();
				postfix = postfix + c + ' ';
			}
			//pop out '('
			if (ch.peek() == '(')
			{
				char c = ch.peek();
				ch.pop();
			}
		}

		//skip over spaces and commas
		else if (infix[index] == ' ' || infix[index] == ',')
		{
			continue;
		}
	}
	//pop everything else out
	while (ch.isEmpty() == false)
	{
		postfix += ch.peek();
		ch.pop();
	}
	//return postfix
	return postfix;
}


std::string Calculator::infixToPrefix(std::string infix)
{
	prefix = "";
	// Reverse the infix expression
	int len = infix.length();
	int endIndex = len - 1;
	for (int index = 0; index < len; index++)
	{
		if (infix[index] == '(')
		{
			infix[index] = ')';
		}
		else if (infix[index] == ')')
		{
			infix[index] = '(';
		}
	}
	for (int index = 0; index < len / 2; index++)
	{
		std::swap(infix[index], infix[endIndex]);
		endIndex--;
	}

	//call convert t o postfix method on inverted infix expression
	prefix = infixToPostfix(infix);

	//reverse back for prefix expression
	int newLength = prefix.length();
	int newEnd = newLength - 1;
	for (int index = 0; index < newLength / 2; index++)
	{
		std::swap(prefix[index], prefix[newEnd]);
		newEnd--;
	}

	return prefix;
}




int Calculator::evaluatePostfix()
{
	// Loop throught the expression
	int len = postfix.length();
	std::string longInt = "";
	for (int index = 0; index < len; index++)
	{
		// Check if it is an operand 
		if (checkOperand(postfix[index]))
		{
			//if next is also an int, add the int to the string
			if (isdigit(postfix[index + 1]))
			{
				longInt += postfix[index];
			}
			//otherwise add current to string and convert to int, then push into int stack
			else
			{
				longInt += postfix[index];
				int temp = stoi(longInt);
				in.push(temp);
				longInt = "";
			}
		}
		//pass over spaces
		else if (postfix[index] == ' ')
		{
			continue;
		}

		// if it is an operator
		else
		{
			//Pop operands from the operator and do proper operation and push abck into stack 

			int operand1 = in.peek();
			in.pop();
			int operand2 = in.peek();
			in.pop();

			int result = 0;

			if (postfix[index] == '+')
			{
				result = operand2 + operand1;
			}
			else if (postfix[index] == '-')
			{
				result = operand2 - operand1;
			}
			else if (postfix[index] == '*')
			{
				result = operand2 * operand1;
			}
			else if (postfix[index] == '%')
			{
				result = operand2 % operand1;
			}
			else
			{
				if (operand1 == 0)
				{
					std::cout << "CANNOT DIVIDE BY 0" << std::endl;
				}
				else
				{
					result = operand2 / operand1;
				}
			}
			in.push(result);
		}
	}

	//return top value of stack (which should be results)
	return in.peek();
}


int Calculator::evaluatePrefix()
{
	// Start at the end of the prefix expression and loop through
	in.empty();
	std::string longInt = "";
	for (int index = prefix.length() - 1; index >= 0; index--)
	{
		// Check if it is an operand 
		if (checkOperand(prefix[index]))
		{
			//if next is also an int, add the int to the string
			if (isdigit(prefix[index - 1]))
			{
				longInt += prefix[index];
			}
			//otherwise add current to string and convert to int, then push into int stack
			else
			{
				longInt += prefix[index];
				int temp = stoi(longInt);
				in.push(temp);
				longInt = "";
			}
		}
		//pass over spaces
		else if (prefix[index] == ' ')
		{
			continue;
		}

		// if it is an operator
		else
		{
			//Pop operands from the operator and do proper operation and push abck into stack 

			int operand1 = in.peek();
			in.pop();
			int operand2 = in.peek();
			in.pop();

			int result = 0;

			if (prefix[index] == '+')
			{
				result = operand1 + operand2;
			}
			else if (prefix[index] == '-')
			{
				result = operand1 - operand2;
			}
			else if (prefix[index] == '*')
			{
				result = operand1*operand2;
			}
			else if (prefix[index] == '%')
			{
				result = operand1%operand2;
			}
			else
			{
				if (operand2 == 0)
				{
					std::cout << "CANNOT DIVIDE BY 0!" << std::endl;
				}
				else
				{
					result = operand1 / operand2;
				}
			}
			in.push(result);
		}
	}
	//return the top of the stack (which should be the result)
	return in.peek();
}