#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create(int size);
void destroy(Queue q);
bool is_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peep_first(Queue q);
Item peep_last(Queue q);

#endif
