/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 05/11/2019                                          *
* Description: Modification of Programming Project 16 from  *
*              Chapter 8 so as to include the function:     *
*    bool are_anagrams(const char *word1, const char *word2 *
*************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 20

int read_line(char str[], int n);
bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char first_word[MAX_LENGTH], second_word[MAX_LENGTH];
	
	printf("Enter first word: ");
	read_line(first_word, MAX_LENGTH);
	
	printf("Enter second word: ");
	read_line(second_word, MAX_LENGTH);
	
	printf("The words are ");
	if (are_anagrams(first_word, second_word))
	{
		printf("anagrams");
	}
	else
	{
		printf("not anagrams");
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

bool are_anagrams(const char *word1, const char *word2)
{
	const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'
	,                        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'
	,                        'w', 'x', 'y', 'z'};
	int incidence_count[26] = {0};
	int i;
	
	while (*word1)
	{
		for (i = 0; i < 26; i++)
		{
			if (tolower(*word1) == alphabet[i])
			{
				incidence_count[i]++;
			}
		}
		word1++;
	}
	
	while (*word2)
	{
		for (i = 0; i < 26; i++)
		{
			if (tolower(*word2) == alphabet[i])
			{
				incidence_count[i]--;
			}
		}
		word2++;
	}
	
	for (i = 0; i < 26; i++)
	{
		if (incidence_count[i] != 0)
		{
			return false;
		}
	}
	return true;
}
