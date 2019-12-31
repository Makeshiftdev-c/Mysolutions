#include <stdio.h>
#include "stackADT.h"

int main(void)
{
	int result, number, operand2;
	Stack s = create();
	char ch, prev_ch;
	
	for (;;)
	{
		printf("Enter a RPN expression: ");
		while ((ch = getchar()) != '\n')
		{
			switch (ch)
			{
				case '0': case'1': case '2': case '3': case '4':
				case '5': case '6': case '7': case '8': case '9':
					if (prev_ch >= '0' && prev_ch <= '9')
					{
						number *= 10;
						number += (ch - 48);
					}
					else
					{
						number = ch - 48;
					}
					push(s, number);
					break;
				case '+':
					result = pop(s) + pop(s);
					push(s, result);
					break;
				case '-':
					operand2 = pop(s);
					result = pop(s) - operand2;
					push(s, result);
					break;
				case '*':
					result = pop(s) * pop(s);
					push(s, result);
					break;
				case '/':
					operand2 = pop(s);
					result = pop(s) / operand2;
					push(s, result);
					break;
				case '=':
					printf("Value of expression: %d\n", pop(s));
					make_empty(s);
					break;
				case 'q':
					destroy(s);
					return 0;
			}
			
			prev_ch = ch;
		}
		prev_ch = '\0';
	}
}
