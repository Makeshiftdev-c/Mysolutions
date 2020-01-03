#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type
{
	Item contents[QUEUE_SIZE];
	int first;
	int last;
	int offset;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

static void reallign(Queue q)
{
	int i = 0;
	
	while (q->first <= q->last)
	{
		q->contents[i++] = q->contents[q->first++];
	}
	q->first = 0;
	q->last -= q->offset;
	q->offset = 0;
}

static bool is_alligned(Queue q)
{
	return q->first == 0;
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
	{
		terminate("Error in create: queue could not be created.");
	}
	q->first = 0;
	q->last = 0;
	q->offset = 0;
	return q;
}

void destroy(Queue q)
{
	free(q);
}

bool is_empty(Queue q)
{
	return q->first == q->last;
}

static bool is_full(Queue q)
{
	return q->last == QUEUE_SIZE;
}

void enqueue(Queue q, Item i)
{
	if (!is_alligned(q))
	{
		reallign(q);
	}
	if (is_full(q))
	{
		terminate("Error in enqueue: queue is full.");
	}
	q->contents[q->last++] = i;
}

Item dequeue(Queue q)
{
	if (is_empty(q))
	{
		terminate("Error in dequeue: queue is empty.");
	}
	q->offset++;
	return q->contents[q->first++];
}

Item peep_first(Queue q)
{
	if (is_empty(q))
	{
		terminate("Error in peep_first: queue is empty.");
	}
	return q->contents[q->first];
}

Item peep_last(Queue q)
{
	if (is_empty(q))
	{
		terminate("Error in peep_last: queue is empty.");
	}
	return q->contents[q->last - 1];
}
