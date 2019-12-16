#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_LINE_LEN 60

struct line
{
	char word[MAX_WORD_LEN];
	struct line *next;
};

struct line *first = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	struct line *cur = first, *prev;
	
	if (cur != NULL)
	{
		for (prev = NULL; cur != NULL; prev = cur, cur = cur->next)
		{
			free(prev);
		}
	}
	first = cur;
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	struct line *new_node, *cur, *prev;
	
	new_node = malloc(sizeof(struct line));
	
	if (new_node != NULL)
	{
		strcpy(new_node->word, "");
		if (num_words > 0)
		{
			strcpy(new_node->word, " ");
			line_len++;
		}
		
		strcat(new_node->word, word);
		line_len += strlen(word);
		num_words++;
		
		for (prev = NULL, cur = first; cur != NULL; prev = cur, cur = cur->next)
		{
			;
		}
		new_node->next = cur;
		if (prev == NULL)
		{
			first = new_node;
		}
		else
		{
			prev->next = new_node;
		}
	}
	else
	{
		printf("Error: malloc failed in add_word\n");
		exit(EXIT_FAILURE);
	}
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, i, j;
	struct line *cur = first;
	
	extra_spaces = MAX_LINE_LEN - line_len;
	while (cur->next != NULL)
	{
		printf("%s", cur->word);
		spaces_to_insert = extra_spaces / (num_words - 1);
		for (j = 1; j < spaces_to_insert + 1; j++)
		{
			putchar(' ');
		}
		extra_spaces -= spaces_to_insert;
		num_words--;
		cur = cur->next;
	}
	printf("%s", cur->word);
	putchar('\n');
}

void flush_line(void)
{
	struct line *cur;
	
	if (line_len > 0)
	{
		for (cur = first; cur->next != NULL; cur = cur->next)
		{
			printf("%s", cur->word);
		}
	}
	clear_line();
}
