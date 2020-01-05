#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node
{
	Item data;
	struct node *next;
};

struct queue_type
{
	struct node *first;
	struct node *last;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
	{
		terminate("Error in create: stack could not be created.");
	}
	q->first = NULL;
	return q;
}

void destroy(Queue q)
{
	while (!is_empty(q))
	{
		dequeue(q);
	}
	free(q);
}

bool is_empty(Queue q)
{
	return q->first == NULL;
}

void enqueue(Queue q, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		terminate("Error in enqueue: queue is full.");
	}
	
	new_node->data = i;
	if (is_empty(q))
	{
		new_node->next = q->first;
		q->first = new_node;
		q->last = new_node;
		return;
	}
	new_node->next = q->last->next;
	q->last->next = new_node;
	q->last = new_node;
}

Item dequeue(Queue q)
{
	struct node *old_first;
	Item i;
	
	if (is_empty(q))
	{
		terminate("Error in dequeue: queue is empty.");
	}
	
	old_first = q->first;
	i = old_first->data;
	q->first = old_first->next;
	free(old_first);
	return i;
}

Item peep_first(Queue q)
{
	return q->first->data;
}

Item peep_last(Queue q)
{
	return q->last->data;
}
