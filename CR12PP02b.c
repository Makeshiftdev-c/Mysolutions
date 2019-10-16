/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 12/10/2019                                          *
* Description: Reads a message, then checks whether it's a  *
*              palindrome                                   *
*************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 100

int read_alphletters(char array[], int max_elements);
bool is_palindrome(char array[], int input_length);


int main(void)
{
	char sentence[MAX_LENGTH];
	int length;
	
	printf("Enter a message: ");
	length = read_alphaletters(sentence, MAX_LENGTH);
	
	if (is_palindrome(sentence, length))
	{
		printf("Palindrom");
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

int read_alphaletters(char array[], int max_elements)
{
	char ch;
	char *p = array;
	int ch_count = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (ch_count >= max_elements)
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

bool is_palindrome(char array[], int input_length)
{
	char *p, *q;
	int last = input_length - 1;
	int num_matches = 0;
	
	for (p = &array[0], q = &array[last]; p < &array[last], q >= &array[0]; p++, q--)
	{
		if (*p == *q)
		{
			num_matches++;
		}
	}

	if (num_matches == input_length)
	{
		return true;
	}
	else
	{
		return false;
	}
}
