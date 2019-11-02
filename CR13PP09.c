/************************************************************
* Name: Abdiisak Arr                                        *
* Date: 02/11/2019                                          *
* Description: Modification of Programming Project 10 from  *
*              Chapter 7 so as to include the function:     *
*            int compute_vowel_count(const char *sentence); *
*************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

int read_line(char str[], int n);
int compute_vowel_count(const char *sentence);

int main(void)
{
	char input_str[MAX_LENGTH];
	int num_vowels;
	
	printf("Enter a sentence: ");
	read_line(input_str, MAX_LENGTH);
	
	num_vowels = compute_vowel_count(input_str);
	
	printf("Your sentence contains %d vowels\n", num_vowels);
	
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

int compute_vowel_count(const char *sentence)
{
	int sum = 0;
	
	while (*sentence)
	{
		switch (tolower(*sentence))
		{
			case 'a': case 'e':
			case 'i': case 'o':
			case 'u':
				sum++;
				break;
			default:
				break;
		}
		sentence++;
	}
	return sum;
}
