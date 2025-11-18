#ifndef SLL_H
#define SLL_H

#include <stddef.h>

typedef struct SLLNode {
    int data;
    struct SLLNode *next;
} SLLNode;

typedef struct {
    SLLNode *head;
} SLL;

SLL *sll_create(void);
void sll_destroy(SLL *l);
void sll_insert_front(SLL *l, int value);
void sll_insert_back(SLL *l, int value);
int sll_insert_at(SLL *l, size_t pos, int value);
int sll_remove(SLL *l, int value);
SLLNode *sll_find(SLL *l, int value);
void sll_print_forward(SLL *l);

#endif
