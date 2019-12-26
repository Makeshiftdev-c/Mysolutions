#include <stdio.h>
#include <stdbool.h>
#include "stackADT.h"

int main(void)
{
	char ch;
	Stack s;
	bool nested = true;
	
	printf("Enter parentheses and/or braces: ");
	ch = getchar();
	while (ch != '\n')
	{
		while (ch != '{' && ch != '}' && ch != '(' && ch != ')')
		{
			ch = getchar();
		}
		
		if (ch == '{')
		{
			push(s, ch);
		}
		else if (ch == '}')
		{
			if (pop(s) != '{')
			{
				nested = false;
				break;
			}
		}
		
		if (ch == '(')
		{
			push(s, ch);
		}
		else if (ch == ')')
		{
			if (pop(s) != '(')
			{
				nested = false;
				break;
			}
		}
		
		ch = getchar();
	}
	
	if (nested)
	{
		printf("Parentheses/braces are nested properly");
	}
	else
	{
		printf("Parentheses/braces are not nested properly");
	}
	printf("\n");
	
	return 0;
}
