/*************************************************************
* Name: Abdirisak Arr                                        *
* Date: 16/09/2019                                           *
* Description: Asks user to enter a series of parentheses    *
*              and/or braces, then indicates whether or      *
*              not they're properly nested.                  *
*              Uses modified stack example from section      *
*              10.2.                                         *
**************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* External variables */
char contents[STACK_SIZE];
int top = 0;

/* Prototypes */
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

/************************************************************
* main: Asks user to enter a series of parentheses and/or   *
*       braces, then indicates whether or not the're        *
*       properly nested.                                    *
*************************************************************/

int main(void)
{
	char ch, popped;
	int left_count = 0;
	bool match;
	
	printf("Enter parentheses and/or braces: ");
	while ((ch = getchar()) != '\n')
	{
		if (ch == '(' || ch == '{')
		{
			push(ch);
			left_count++;
		}
		else if (ch == ')' || ch == '}')
		{
			popped = pop();
			if (popped == '(' && ch == ')')
			{
				left_count--;
			}
			else if (popped == '{' && ch == '}')
			{
				left_count--;
			}
		}
	}
	
	if (left_count == 0)
	{
		match = true;
	}
	else
	{
		match = false;
	}
	
	if (is_empty && match)
	{
		printf("Parentheses/braces are nested properly");
	}
	else
	{
		printf("Parentheses/braces aren't properly nested");
	}
	
	exit(EXIT_SUCCESS);
}

/************************************************************
* is_empty: Checks if the stack is empty. Returns true if   *
*           the external variable, top, is zero.            *
*************************************************************/

bool is_empty(void)
{
	return top == 0;
}

/************************************************************
* is_full: Checks if the stack is full. Returns true is if  *
*          the external variable, top, is STACK_SIZE        *
*************************************************************/

bool is_full(void)
{
	return top == STACK_SIZE;
}

/************************************************************
* push: Calls stack_overflow if is_full returns true if     *
*       not, pushes characters (parentheses or braces,      *
*       in this case) onto the stack; increments            *
*       the top of the stack.                               *
*************************************************************/

void push(char ch)
{
	if (is_full())
	{
		stack_overflow();
	}
	else
	{
		contents[top++] = ch;
	}
}

/************************************************************
* pop: Calls stack_underflow if is_empty returns true if    *
*      not, decrements top of stack; pops element out of    *
*      the stack                                            *
*************************************************************/

char pop(void)
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

/************************************************************
* stack_overflow: Prints message in event of overflow;      *
*                 terminates program.                       * 
*************************************************************/

void stack_overflow(void)
{
	printf("\nStack overflow");
	exit(EXIT_SUCCESS);
}

/************************************************************
* stack_underflow: Prints message in case of underflow;     *
*                  terminates program.                      *
*************************************************************/

void stack_underflow(void)
{
	printf("Parentheses/braces aren't properly nested");
	exit(EXIT_SUCCESS);
}

