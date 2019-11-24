#ifndef STACK_H
#define STACK_H

/************************************************************
* push: Pushes integer onto the stack.                      *
*************************************************************/

void push(int i);

/************************************************************
* pop: Pops integer from the stack.                         *
*************************************************************/

int pop(void);

/************************************************************
* is_full: Returns the constant 1 if the stack is full,     *
*          and the constant 0 otherwise.                    *
*************************************************************/

int is_full(void);

/************************************************************
* is_empty: Returns the constant 1 if the stack is empty,   *
*           and the constant 0 is otherwise.                *
*************************************************************/

int is_empty(void);

/************************************************************
* make_empty: Empties the stack.                            *
*************************************************************/

void make_empty(void);

/************************************************************
* stack_overflow: Prints a message and terminates the       *
*                 the program if the stack overflows.       *
*************************************************************/

void stack_overflow(void);

/************************************************************
* stack_underflow: Prints a message and terminates the      *
*                  program if the stack underflows.         *
*************************************************************/

void stack_underflow(void);

#endif
