#include "sll.h"
#include <stdlib.h>
#include <stdio.h>

SLL *sll_create(void) {
    SLL *l = malloc(sizeof(SLL));
    l->head = NULL;
    return l;
}

void sll_destroy(SLL *l) {
    SLLNode *curr = l->head;
    while (curr) {
        SLLNode *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(l);
}

void sll_insert_front(SLL *l, int value) {
    SLLNode *node = malloc(sizeof(SLLNode));
    node->data = value;
    node->next = l->head;
    l->head = node;
}

void sll_insert_back(SLL *l, int value) {
    SLLNode *node = malloc(sizeof(SLLNode));
    node->data = value;
    node->next = NULL;
    if (!l->head) {
        l->head = node;
        return;
    }
    SLLNode *curr = l->head;
    while (curr->next) curr = curr->next;
    curr->next = node;
}

int sll_insert_at(SLL *l, size_t pos, int value) {
    if (pos == 0) {
        sll_insert_front(l, value);
        return 1;
    }
    SLLNode *curr = l->head;
    for (size_t i = 0; curr && i < pos-1; i++)
        curr = curr->next;
    if (!curr) return 0;

    SLLNode *node = malloc(sizeof(SLLNode));
    node->data = value;
    node->next = curr->next;
    curr->next = node;
    return 1;
}

int sll_remove(SLL *l, int value) {
    SLLNode *curr = l->head;
    SLLNode *prev = NULL;

    while (curr) {
        if (curr->data == value) {
            if (prev) prev->next = curr->next;
            else l->head = curr->next;
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

SLLNode *sll_find(SLL *l, int value) {
    SLLNode *curr = l->head;
    while (curr) {
        if (curr->data == value) return curr;
        curr = curr->next;
    }
    return NULL;
}

void sll_print_forward(SLL *l) {
    SLLNode *curr = l->head;
    printf("SLL: ");
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
