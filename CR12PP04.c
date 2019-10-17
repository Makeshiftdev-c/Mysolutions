/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 16/10/2019                                          *
* Description: Simplification of Programming Project 2 Part *
*              (b) from Chapter 12, taking advantage of the *
*              fact that an array name can used as a pointer*
*************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int read_message(char array[], int array_length);
bool is_palindrome(char array[], int message_length);

int main(void)
{
	char message[MAX_LENGTH];
	int length;
	
	printf("Enter a message: ");
	length = read_message(message, MAX_LENGTH);
	
	if (is_palindrome(message, length))
	{
		printf("Palindrome");
	}
	else
	{
		printf("Not a palindrome");
	}
	
	return 0;
}

/****************************************************************
* read_alphaletters: Reads characters of the alphabet input     *
*                    by the user into an array; records and     *
*                    returns the number of characters entered   *
*                    by the user, ignoring non-valid characters *
*****************************************************************/

int read_message(char array[], int array_length)
{
	char ch, *p = array;
	int ch_count = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (p >= array + array_length)
		{
			break;
		}
		else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			*p++ = tolower(ch);
			ch_count++;
		}
	}
	
	return ch_count;
}

/************************************************************
* is_palindrome: Checks if the message entered by user is   *
*                a palindrome, returns true if so or false  *
*                otherwise.                                 *
*************************************************************/

bool is_palindrome(char array[], int message_length)
{
	char *p, *q;
	int num_matches = 0;
	int last_element = message_length - 1;
	
	for (p = array, q = p + last_element; p <= array + last_element, q >= array; p++, q--)
	{
		if (*p == *q)
		{
			num_matches++;
		}
	}
	
	if (num_matches == message_length)
	{
		return true;
	}
	else
	{
		return false;
	}
}
