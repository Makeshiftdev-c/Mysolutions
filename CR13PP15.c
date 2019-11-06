/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 06/11/2019                                          *
* Description: Modification of Programming Project 6 from   *
*              Chapter 10 so as to include the function:    *
*      int evaluate_RPN_expression(const char *expression); *
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int *top_ptr = contents;

int pop(void);
void push(int i);
bool is_full(void);
bool is_empty(void);
void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
int read_line(char str[], int n);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
	char expression[STACK_SIZE];
	int result;
	
	for (;;)
	{
		printf("Enter RPN expression: ");
		read_line(expression, STACK_SIZE);
		
		result = evaluate_RPN_expression(expression);
		
		printf("Value of expression: %d\n", result);
	}
	
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	make_empty();
	
	while ((ch = getchar()) != '\n')
	{
		if (ch == 'q')
		{
			exit(EXIT_SUCCESS);
		}
		else if (i < n)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}

int evaluate_RPN_expression(const char *expression)
{
	const char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int result, operand1, operand2;
	int num;
	
	while (*expression)
	{
		if (*expression >= '0' && *expression <= '9')
		{
			for (num = 0; num < 10; num++)
			{
				if (numbers[num] == *expression)
				{
					push(num);
					break;
				}
			}
		}
		else if (*expression == '+')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 + operand2;
			push(result);
		}
		else if (*expression == '-')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 - operand2;
			push(result);
		}
		else if (*expression == '*')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 * operand2;
			push(result);
		}
		else if (*expression == '/')
		{
			operand2 = pop();
			operand1 = pop();
			result = operand1 / operand2;
			push(result);
		}
		else if (*expression == '=')
		{
			return pop();
		}
		expression++;
	}
}

void push(int i)
{
	if (is_full())
	{
		stack_overflow();
	}
	else
	{
		*top_ptr++ = i;
	}
}

int pop(void)
{
	if (is_empty())
	{
		stack_underflow();
	}
	else
	{
		return *--top_ptr;
	}
}

bool is_full(void)
{
	return (top_ptr == contents + STACK_SIZE);
}

bool is_empty(void)
{
	return (top_ptr == contents);
}

void make_empty(void)
{
	top_ptr = contents;
}

void stack_overflow(void)
{
	printf("Expression is too complex");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression");
	exit(EXIT_SUCCESS);
}
