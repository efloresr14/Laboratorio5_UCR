#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

DLL *dll_create(void) {
    DLL *l = malloc(sizeof(DLL));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void dll_destroy(DLL *l) {
    DLLNode *curr = l->head;
    while (curr) {
        DLLNode *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(l);
}

void dll_insert_front(DLL *l, int value) {
    DLLNode *node = malloc(sizeof(DLLNode));
    node->data = value;
    node->prev = NULL;
    node->next = l->head;

    if (l->head) l->head->prev = node;
    else l->tail = node;

    l->head = node;
}

void dll_insert_back(DLL *l, int value) {
    DLLNode *node = malloc(sizeof(DLLNode));
    node->data = value;
    node->next = NULL;
    node->prev = l->tail;

    if (l->tail) l->tail->next = node;
    else l->head = node;

    l->tail = node;
}

int dll_insert_at(DLL *l, size_t pos, int value) {
    if (pos == 0) {
        dll_insert_front(l, value);
        return 1;
    }

    DLLNode *curr = l->head;
    for (size_t i = 0; curr && i < pos - 1; i++)
        curr = curr->next;

    if (!curr) return 0;

    if (!curr->next) {
        dll_insert_back(l, value);
        return 1;
    }

    DLLNode *node = malloc(sizeof(DLLNode));
    node->data = value;

    node->next = curr->next;
    node->prev = curr;

    curr->next->prev = node;
    curr->next = node;

    return 1;
}

int dll_remove(DLL *l, int value) {
    DLLNode *curr = l->head;

    while (curr) {
        if (curr->data == value) {

            if (curr->prev) curr->prev->next = curr->next;
            else l->head = curr->next;

            if (curr->next) curr->next->prev = curr->prev;
            else l->tail = curr->prev;

            free(curr);
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

DLLNode *dll_find(DLL *l, int value) {
    DLLNode *curr = l->head;
    while (curr) {
        if (curr->data == value) return curr;
        curr = curr->next;
    }
    return NULL;
}

void dll_print_forward(DLL *l) {
    DLLNode *curr = l->head;
    printf("DLL forward: ");
    while (curr) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void dll_print_backward(DLL *l) {
    DLLNode *curr = l->tail;
    printf("DLL backward: ");
    while (curr) {
        printf("%d <-> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}
