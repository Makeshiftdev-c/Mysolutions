#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int contents[STACK_SIZE];
int *top_ptr = contents;

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

int is_full(void)
{
	return top_ptr == contents + STACK_SIZE;
}

int is_empty(void)
{
	return top_ptr == contents;
}

void make_empty(void)
{
	top_ptr = contents;
}

void stack_overflow(void)
{
	printf("Expression too complex");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression");
	exit(EXIT_SUCCESS);
}
