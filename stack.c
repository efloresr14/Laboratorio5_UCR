#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *stack_create(void) {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void stack_destroy(Stack *s) {
    StackNode *curr = s->top;
    while (curr) {
        StackNode *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(s);
}

int stack_push(Stack *s, int value) {
    StackNode *node = malloc(sizeof(StackNode));
    node->data = value;
    node->next = s->top;
    s->top = node;
    return 1;
}

int stack_pop(Stack *s, int *out) {
    if (!s->top) return 0;

    StackNode *tmp = s->top;
    *out = tmp->data;

    s->top = tmp->next;
    free(tmp);
    return 1;
}

int stack_peek(Stack *s, int *out) {
    if (!s->top) return 0;
    *out = s->top->data;
    return 1;
}

int stack_is_empty(Stack *s) {
    return s->top == NULL;
}
