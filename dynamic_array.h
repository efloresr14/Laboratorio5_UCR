#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynArray;

DynArray *da_create(size_t capacity);
void da_destroy(DynArray *arr);
int da_push(DynArray *arr, int value);
int da_remove_at(DynArray *arr, size_t index);
int da_get(DynArray *arr, size_t index, int *out);
void da_print(DynArray *arr);

#endif
