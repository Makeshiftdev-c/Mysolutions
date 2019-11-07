/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 07/11/2019                                          *
* Description: Modification of Programming Project 1 from   *
*              Chapter 12 so as to include the function:    *
*                  void reverse(char *message);             *
*************************************************************/

#include <stdio.h>

#define MAX_LENGTH 50

int read_line(char str[], int n);
void reverse(char *message);

int main(void)
{
	char input_str[MAX_LENGTH];
	
	printf("Enter a sentence: ");
	read_line(input_str, MAX_LENGTH);
	
	reverse(input_str);
	
	printf("The reverse is: %s\n", input_str);
	
	return 0;
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
	}
	str[i] = '\0';
	return i;
}

void reverse(char *message)
{
	char *back_parse, placehold;
	
	for (back_parse = message; *back_parse != '\0'; back_parse++)
	{
		;
	}
	
	back_parse--;
	while (message <= back_parse)
	{
		placehold = *message;
		*message++ = *back_parse;
		*back_parse-- = placehold;
	}
}
