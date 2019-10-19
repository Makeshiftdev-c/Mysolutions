/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 17/10/2019                                          *
* Description: Modification of Programming Project 14 from  *
*              Chapter 8, using pointers to keep track of   *
*              array position                               *
*************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

int read_sentence(char array[], int array_length);
void print_reverse_sentence(char array[], int message_length);

int main(void)
{
	char sentence[MAX_LENGTH];
	int length;
	
	printf("Enter a sentence: ");
	length = read_sentence(sentence, MAX_LENGTH);
	
	printf("Reversal of sentence: ");
	print_reverse_sentence(sentence, length);
	
	return 0;
}

/************************************************************
* read_sentence: Reads user input character by character    *
*                into array passed as argument.             *
*************************************************************/

int read_sentence(char array[], int array_length)
{
	char ch, *p = array;
	int ch_count = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (p < array + array_length)
		{
			*p++ = ch;
			ch_count++;
		}
		else
		{
			break;
		}
	}
	
	return ch_count;
}

/************************************************************
*  print_reverse_message: Prints the words of a sentence    *
*                         in reverse order, ignoring        *
*                         mid-sentence puncuation.          *
*************************************************************/

void print_reverse_sentence(char array[], int message_length)
{
	char *p, *q;
	int num_parse = 0, last_element = message_length - 1;
	
	for (p = array + last_element; p >= array; p--)
	{
		if ((tolower(*p) >= 'a' && tolower(*p) <= 'z') || *p == '\'')
		{
			num_parse++;
		}
		
		if (*p == ' ' || p == array)
		{
			if (*p == ' ')
			{
				for (q = p + 1; q <= p + num_parse; q++)
				{
					putchar(*q);
				}
				putchar(' ');
				num_parse = 0;
			}
			else
			{
				for (q = p; q < p + num_parse; q++)
				{
					putchar(*q);
				}
				if (*(p + last_element) == '.' || *(p + last_element) == '?' || *(p + last_element) == '!')
				{
					putchar(*(p + last_element));
				}
			}
		}
	}
}
