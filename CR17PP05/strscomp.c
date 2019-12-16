#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int main(void)
{
	char *words[MAX_WORDS];
	char str[MAX_WORD_LEN];
	int i, j, num_words = 0;
	
	for (;;)
	{
		if (num_words == MAX_WORDS)
		{
			printf("-- No space left --");
			break;
		}
		
		printf("Enter a word: ");
		read_line(str, MAX_WORD_LEN);
		if (str[0] == '\0')
		{
			break;
		}
		
		for (i = 0; i < num_words; i++)
		{
			if (strcmp(str, words[i]) < 0)
			{
				break;
			}
		}
		for (j = num_words; j > i; j--)
		{
			words[j] = words[j - 1];
		}
		
		words[i] = malloc(strlen(str) + 1);
		if (words[i] == NULL)
		{
			printf("-- No space left --");
			break;
		}
		
		strcpy(words[i], str);
		num_words++;
	}
	
	printf("\nIn sorted order: ");
	for (i = 0; i < num_words; i++)
	{
		printf("%s ", words[i]);
	}
	printf("\n");
	
	return 0;
}
