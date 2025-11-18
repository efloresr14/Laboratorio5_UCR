#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

DynArray *da_create(size_t capacity) {
    if (capacity == 0) capacity = 4;
    DynArray *a = malloc(sizeof(DynArray));
    a->data = malloc(sizeof(int) * capacity);
    a->size = 0;
    a->capacity = capacity;
    return a;
}

void da_destroy(DynArray *arr) {
    free(arr->data);
    free(arr);
}

static int da_resize(DynArray *arr, size_t newcap) {
    int *tmp = realloc(arr->data, sizeof(int) * newcap);
    if (!tmp) return 0;
    arr->data = tmp;
    arr->capacity = newcap;
    return 1;
}

int da_push(DynArray *arr, int value) {
    if (arr->size == arr->capacity)
        da_resize(arr, arr->capacity * 2);
    arr->data[arr->size++] = value;
    return 1;
}

int da_remove_at(DynArray *arr, size_t index) {
    if (index >= arr->size) return 0;
    memmove(&arr->data[index], &arr->data[index+1],
            sizeof(int)*(arr->size-index-1));
    arr->size--;
    return 1;
}

int da_get(DynArray *arr, size_t index, int *out) {
    if (index >= arr->size) return 0;
    *out = arr->data[index];
    return 1;
}

void da_print(DynArray *arr) {
    printf("Array: [");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i+1 < arr->size) printf(", ");
    }
    printf("]\n");
}
