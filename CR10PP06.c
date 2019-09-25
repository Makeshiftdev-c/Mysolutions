/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 25/09/2019                                          *
* Description: Evaluates Reverse Polish                     *
*              Notation (RPN) expressions. Where positive   *
*              single digit integers are operands, and      *
*              +, -, *, /, and = are operators. = operator  *
*              outputs the result to console and clears     *
*              the stack Process continues until user       *
*              enters a character that is not a operator    *
*              or operand.                                  *
*************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 10

/* external variables */
int contents[STACK_SIZE];
int top = 0;

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

/************************************************************
* main: Prompts user for input; Utilises stack to help      *
*       evaluate RPN expression and outputs result;         *
*       then clears stack and repeats process until         *
*       invalid input is entered, in which case, the        *
*       program terminates.                                 *
*************************************************************/

int main(void)
{
	char ch = '0';
	int  value, first_operand, second_operand, result;
	bool valid = true;
	
	while (valid)
	{
		printf("Enter an RPN expression: ");
		while (ch != '\n')
		{
			scanf(" %c", &ch);
			if (ch >= '0' && ch <= '9')
			{
				switch (ch)
				{
					case '0':
						value = 0;
						break;
					case '1':
						value = 1;
						break;
					case '2':
						value = 2;
						break;
					case '3':
						value = 3;
						break;
					case '4':
						value = 4;
						break;
					case '5':
						value = 5;
						break;
					case '6':
						value = 6;
						break;
					case '7':
						value = 7;
						break;
					case '8':
						value = 8;
						break;
					case '9':
						value = 9;
						break;
				}
				push(value);
			}
			else if (ch == '+')
			{
				first_operand = pop();
				second_operand = pop();
				result = first_operand + second_operand;
				push(result);
			}
			else if (ch == '-')
			{
				first_operand = pop();
				second_operand = pop();
				result = second_operand - first_operand;
				push(result);
			}
			else if (ch == '*')
			{
				first_operand = pop();
				second_operand = pop();
				result = first_operand * second_operand;
				push(result);
			}
			else if (ch == '/')
			{
				first_operand = pop();
				second_operand = pop();
				result = second_operand / first_operand;
				push(result);
			}
			else if (ch == '=')
			{
				printf("Value of expression: %d", pop());
				make_empty();
				break;
			}
			else
			{
				valid = false;
				break;
			}
		}
		
		printf("\n");
	}
	
	return 0;
}

/************************************************************
*                 Implementation of stack                   *
*************************************************************/

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full())
	{
		stack_overflow();
	}
	else
	{
		contents[top++] = i;
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
		return contents[--top];
	}
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
