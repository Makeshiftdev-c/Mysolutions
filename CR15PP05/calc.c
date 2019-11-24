/* Evaluates an RPN expression utilising a stack */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_INPUT 20

int read_line(char str[], int n);
int evaluate_RPN_expression(char *expression);

int main(void)
{
	char input[MAX_INPUT];
	int result;
	
	for (;;)
	{
		printf("Enter an RPN expression: ");
		read_line(input, MAX_INPUT);
		
		result = evaluate_RPN_expression(input);
		
		printf("Value of expression: %d\n", result);
		make_empty();
	}
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		{
			str[i++] = ch;
		}
		if (ch == 'q')
		{
			exit(EXIT_SUCCESS);
		}
	}
	str[i] = '\0';
	return i;
}

int evaluate_RPN_expression(char *expression)
{
	int operand1, operand2, result;
	int integer;
	
	while (*expression)
	{
		if (*expression >= '0' && *expression <= '9')
		{
			integer = *expression - '0';
			expression++;
			while (*expression != ' ' && *expression)
			{
				integer *= 10;
				integer += (*expression - '0');
				expression++;
			}
			push(integer);
		}
		if (*expression == '+')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 + operand2;
			push(result);
		}
		if (*expression == '-')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 - operand2;
			push(result);
		}
		if (*expression == '*')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 * operand2;
			push(result);
		}
		if (*expression == '/')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 / operand2;
			push(result);
		}
		if (*expression == '=')
		{
			return pop();
		}
		expression++;
	}
}
