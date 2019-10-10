/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 09/10/2019                                          *
* Description: Reads a message. then prints the reversal of *
*              the message using pointers as opposed to     *
*              array subscripting.                          *
*************************************************************/

#include <stdio.h>

#define MAX_SIZE 100

int read_message(char array[], int array_length);
void print_reverse(char array[], int message_length);

/************************************************************
* main: Declares array for message storage, and variable    *
*       to hold length of user input; provides background   *
*       information to console; calls read_message          *
*       and print_reverse                                   *
*************************************************************/

int main(void)
{
	char sentence[MAX_SIZE];
	int sentence_length;
	
	printf("Enter a message: ");
	sentence_length = read_message(sentence, MAX_SIZE);
	
	printf("Reversal is: ");
	print_reverse(sentence, sentence_length);
	
	return 0;
}

/************************************************************
* read_message: Stores characters into sentence array;      *
*               returns the number of characters.           *
*************************************************************/

int read_message(char array[], int array_length)
{
	char ch;
	char *p = array;
	static int ch_count;
	
	while ((ch = getchar()) != '\n')
	{
		if (ch_count >= array_length - 1)
		{
			break;
		}
		
		*p = ch;
		
		p++;
		ch_count++;
	}
	
	return ch_count;
}

/************************************************************
* print_reverse: Prints sentence array in reverse using     *
*                the sentence_length variable in main.      *
*************************************************************/

void print_reverse(char array[], int message_length)
{
	char *p;
	
	for (p = array + message_length - 1; p >= array; p--)
	{
		putchar(*p);
	}
}
