/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 04/11/2019                                          *
* Description: Modification of Programming Project 13 from  *
*              Chapter 7 so as to include the function:     *
* double compute_average_word_length(const char *sentence); *
*************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

int read_line(char str[], int n);
double compute_average_word_length(const char *sentence);

int main(void)
{
	char input[MAX_LENGTH];
	double average;
	
	printf("Enter a sentence: ");
	read_line(input, MAX_LENGTH);
	
	average = compute_average_word_length(input);
	
	if (average > 0.00)
	{
		printf("Average word length: %.1f", average);
	}
	else
	{
		printf("Invalid input; no words entered");
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

double compute_average_word_length(const char *sentence)
{
	int ch_count = 0;
	int word_count = 1;
	
	while(*sentence)
	{
		if (tolower(*sentence) >= 'a' && tolower(*sentence) <= 'z')
		{
			ch_count++;
		}
		else if (*sentence == ' ')
		{
			word_count++;
		}
		sentence++;
	}
	
	if (ch_count == 0)
	{
		return -1.00;
	}
	else
	{
		return ((double) ch_count / word_count);
	}
}
