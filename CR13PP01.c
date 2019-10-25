/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 24/10/2019                                          *
* Description: Finds the "smallest" and "largest" in a      *
*              series of words, in terms of alphabetic      *
*              order. Terminates when user enters a         *
*              four-letter word                             *
*************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 20
#define MAX_WORDS 7

int read_line(char str[], int n);

int main(void)
{
	char largest[MAX_LETTERS], smallest[MAX_LETTERS];
	char wrd_str[MAX_LETTERS];
	int wrd_count = 0;
	
	for (;;)
	{
		if (wrd_count == MAX_WORDS)
		{
			break;
		}
		
		printf("Enter a word: ");
		read_line(wrd_str, MAX_LETTERS);
		
		if (wrd_count == 0)
		{
			strcpy(smallest, strcpy(largest, wrd_str));
		}
		else
		{
			if (strcmp(wrd_str, largest) > 0)
			{
				strcpy(largest, wrd_str);
			}
			
			if (strcmp(wrd_str, smallest) < 0)
			{
				strcpy(smallest, wrd_str);
			}
		}
		
		wrd_count++;
		
		if (strlen(wrd_str) == 4)
		{
			break;
		}
	}
	
	printf("\nSmallest word: %s\n", smallest);
	printf("Largest word: %s\n", largest);
	
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
