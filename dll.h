#ifndef DLL_H
#define DLL_H

#include <stddef.h>

typedef struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

typedef struct {
    DLLNode *head;
    DLLNode *tail;
} DLL;

DLL *dll_create(void);
void dll_destroy(DLL *l);
void dll_insert_front(DLL *l, int value);
void dll_insert_back(DLL *l, int value);
int dll_insert_at(DLL *l, size_t pos, int value);
int dll_remove(DLL *l, int value);
DLLNode *dll_find(DLL *l, int value);
void dll_print_forward(DLL *l);
void dll_print_backward(DLL *l);

#endif
