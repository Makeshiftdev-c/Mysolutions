/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 08/11/2019                                          *
* Description: Modification of Programming Project 2 from   *
*              Chapter 12 so as to include the function:    *
*           bool is_palindrome(const char *message);        *
*************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 30

int read_letters_uncap(char str[], int n);
bool is_palindrome(const char *message);

int main(void)
{
	char input_str[MAX_LENGTH];
	
	printf("Enter a message: ");
	read_letters_uncap(input_str, MAX_LENGTH);
	
	if (is_palindrome(input_str))
	{
		printf("Palindrome\n");
	}
	else
	{
		printf("Not a palindrome");
	}
	
	return 0;
}

int read_letters_uncap(char str[], int n)
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		{
			ch = ch - 'A' + 'a';
			if (ch >= 'a' && ch <= 'z')
			{
				str[i++] = ch;
			}
		}
	}
	str[i] = '\0';
	return i;
}

bool is_palindrome(const char *message)
{
	const char *rvrse_parse = message;
	
	while (*rvrse_parse)
	{
		rvrse_parse++;
	}
	rvrse_parse--;
	
	while (*message == *rvrse_parse)
	{
		if (message++ >= rvrse_parse--)
		{
			return true;
		}
	}
	return false;
}
