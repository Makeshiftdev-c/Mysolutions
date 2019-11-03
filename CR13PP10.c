/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 03/11/2019                                          *
* Description: Modification of Programming Project 11 from  *
*              Chapter 7 so as to include the function:     *
*                   void reverse_name(char *name);          *
************************************************************/

#include <stdio.h>

#define MAX_LENGTH 100

int read_line(char str[], int n);
void reverse_name(char *name);

int main(void)
{
	char input[MAX_LENGTH];
	char *p;
	
	printf("Enter a first and last name: ");
	read_line(input, MAX_LENGTH);
	
	reverse_name(input);
	
	for (p = input; *p != '\0'; p++)
	{
		putchar(*p);
	}
	
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

void reverse_name(char *name)
{
	char first_name[MAX_LENGTH];
	char initial;
	char *p = name;
	int i;
	
	for (;;)
	{
		if (*p != ' ')
		{
			break;
		}
		p++;
	}
	
	for (i = 0; *p != ' ';)
	{
		first_name[i++] = *p++;
	}
	first_name[i] = '\0';
	
	for (;;)
	{
		if (*p != ' ')
		{
			break;
		}
		p++;
	}
	initial = *p;
	
	*name++ = initial;
	*name++ = '.';
	*name++ = ',';
	*name++ = ' ';
	for (p = first_name; *p != '\0'; p++)
	{
		*name++ = *p;
	}
	*name = '\0';
}
