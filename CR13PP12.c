/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 04/11/2019                                          *
* Description: Modification of Programming Project 14 from  *
*              Chapter 8 so that it stores the words in a   *
*              two-dimensional char array as it reads the   *
*              sentence, with each row of the array storing *
*              a single word                                *
*************************************************************/

#include <stdio.h>

#define MAX_WORDS 30
#define MAX_LENGTH 20

int read_word(char str[], int n, char *punctuation);

int main(void)
{
	char words[MAX_WORDS] [MAX_LENGTH];
	int control = 1;
	char punctuation;
	int i, j;
	
	printf("Enter a sentence: ");
	for (i = 0; control != 0 && control != -1; i++)
	{
		control = read_word(words[i], MAX_LENGTH, &punctuation);
	}
	
	printf("Reversal of sentence: ");
	for (j = i - 1; j >= 0; j--)
	{
		printf("%s", words[j]);
		if (j > 0)
		{
			printf(" ");
		}
	}
	if (control == -1)
	{
		printf("%c", punctuation);
	}
	
	return 0;
}

int read_word(char str[], int n, char *punctuation)
{
	int ch, i = 0;
	
	while((ch = getchar()) != ' ')
	{
		if (ch == '\n')
		{
			return 0;
		}
		else if (ch == '.')
		{
			*punctuation = '.';
			return -1;
		}
		else if (ch == '?')
		{
			*punctuation = '?';
			return -1;
		}
		else if (ch == '!')
		{
			*punctuation = '!';
			return -1;
		}
		else if (i < n)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}
