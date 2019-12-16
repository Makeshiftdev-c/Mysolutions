#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_WORD_LEN 20

struct node
{
	char word[MAX_WORD_LEN];
	struct node *next;
};

struct node *first = NULL;

int add_word(void);
void print(void);
void clear(void);

int main(void)
{
	int word_len;
	
	for (;;)
	{
		printf("Enter word: ");
		word_len = add_word();
		if (word_len == 0)
		{
			break;
		}
	}
	
	printf("\nIn sorted order: ");
	print();
	
	clear();
	
	return 0;
}

int add_word(void)
{
	struct node *new_node, *prev, *cur;
	int length;
	
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		printf("-- No space left --");
		exit(EXIT_FAILURE);
	}
	
	length = read_line(new_node->word, MAX_WORD_LEN);
	if (length == 0)
	{
		free(new_node);
		return length;
	}
	
	for (prev = NULL, cur = first;
		 cur != NULL && strcmp(new_node->word, cur->word) > 0;
		 prev = cur, cur = cur->next)
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
	return length;
}

void print(void)
{
	struct node *cur;
	
	for (cur = first; cur != NULL; cur = cur->next)
	{
		printf("%s ", cur->word);
	}
}

void clear(void)
{
	struct node *cur, *prev;
	
	for (prev = NULL, cur = first;
		 cur != NULL;
		 prev = cur, cur = cur->next)
		 {
		 	free(prev);
		 }
	first = cur;
}
