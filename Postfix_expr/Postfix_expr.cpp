// Postfix_expr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::string expression = "3 4 + 2 3 * +";
	std::stack<int> numbers;
	std::stack<char> op;
	int operand1 = 0;
	int operand2 = 0;
	for (int i = 0; i < expression.size(); ++i)
	{
		if (isdigit(expression[i]))
			numbers.push(expression[i] - 48);
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*')
		{
			op.push(expression[i]);
			operand1 = numbers.top();
			numbers.pop();
			operand2 = numbers.top();
			numbers.pop();
			if (op.top() == '+')
				numbers.push(operand2 + operand1);
			if (op.top() == '-')
				numbers.push(operand2 - operand1);
			if (op.top() == '/')
				numbers.push(operand2 / operand1);
			if (op.top() == '*')
				numbers.push(operand2 * operand1);
		}
		
	}
	std::cout << numbers.top() << std::endl;

    return 0;
}

