#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int compare_parts(const void *p, const void *q);

int main(void)
{
	char *words[MAX_WORDS];
	char word[MAX_WORD_LEN];
	int i, num_words = 0;
	
	for (;;)
	{
		if (num_words == MAX_WORDS)
		{
			printf("-- No space left --");
			break;
		}
		
		printf("Enter word: ");
		read_line(word, MAX_WORD_LEN);
		if (strlen(word) == 0)
		{
			break;
		}
		
		
		words[num_words] = malloc(strlen(word) + 1);
		if (words[num_words] == NULL)
		{
			printf("-- No space left --");
			break;
		}
		
		strcpy(words[num_words], word);
		num_words++;
	}
	
	qsort(words, num_words, sizeof(char *), compare_parts);
	
	printf("\nIn sorted order: ");
	for (i = 0; i < num_words; i++)
	{
		printf("%s ", words[i]);
	}
	
	return 0;
}

int compare_parts(const void *p, const void *q)
{
	return strcmp(*(const char **)p, *(const char **)q);
}
