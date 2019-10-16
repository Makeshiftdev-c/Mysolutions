/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 15/10/2019                                          *
* Description: Simplification of Programming Project 1 Part *
*              (b) from Chapter 12, taking advantage of the *
*              fact that an array name can be used as a     *
*              pointer                                      *
*************************************************************/

#include <stdio.h>

#define MAX_LENGTH 10

int read_message(char array[], int max_length);
void print_reverse(char array[], int message_length);

int main(void)
{
	char sentence[MAX_LENGTH];
	int sentence_length;
	
	printf("Enter a message: ");
	sentence_length = read_message(sentence, MAX_LENGTH);
	
	printf("Reversal is: ");
	print_reverse(sentence, sentence_length);
	
	return 0;
}

/************************************************************
* read_message: Stores characters into array, passed as an  *
*               argument; returns the number of characters. *
*************************************************************/

int read_message(char array[], int max_length)
{
	char ch;
	char *p = array;
	int ch_count = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (ch >= ' ' && ch <= '~')
		{
			if (p >= array + MAX_LENGTH)
			{
				break;
			}
			
			*p++ = ch;
			ch_count++;
		}
	}
	
	return ch_count;
}

/************************************************************
* print_reverse: Prints sentence array in reverse using     *
*                array that contains user input and length  *
*                of user input returned by read_message.    *
*************************************************************/

void print_reverse(char array[], int message_length)
{
	char *p;
	int last_element = message_length - 1;
	
	for (p = array + last_element; p >= array; p--)
	{
		putchar(*p);
	}
}
