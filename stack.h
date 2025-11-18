#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

Stack *stack_create(void);
void stack_destroy(Stack *s);
int stack_push(Stack *s, int value);
int stack_pop(Stack *s, int *out);
int stack_peek(Stack *s, int *out);
int stack_is_empty(Stack *s);

#endif
