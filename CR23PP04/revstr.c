#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_LEN 100

struct node
{
	char *word;
	struct node *next;
};

struct node *add_word(struct node *list, char *word);
void clear_list(struct node *list);

int main(void)
{
	struct node *cur, *reverse = NULL;
	char sentence[MAX_LEN];
	char *word;

	printf("Enter a (space delimited) series of words: ");
	read_line(sentence, MAX_LEN);

	word = strtok(sentence, " ");
	reverse = add_word(reverse, word);
	while ((word = strtok(NULL, " ")) != NULL)
		reverse = add_word(reverse, word);

	printf("The reverse is:");
	for (cur = reverse;
	     cur != NULL;
	     cur = cur->next)
		printf(" %s", cur->word);
	printf("\n");

	clear_list(reverse);
	return 0;
}

struct node *add_word(struct node *list, char *word)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed in add_word\n");
		exit(EXIT_FAILURE);
	}

	new_node->word = word;
	new_node->next = list;
	return new_node;
}

void clear_list(struct node *list)
{
	struct node *cur, *prev;

	for (cur = list, prev = NULL;
	     cur != NULL;
	     prev = cur, cur = cur->next)
		free(prev);
}
