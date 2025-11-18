#include <stdio.h>
#include "dynamic_array.h"
#include "sll.h"
#include "dll.h"
#include "stack.h"

int main() {

    printf("===== Dynamic Array =====\n");
    DynArray *a = da_create(2);
    da_push(a, 10);
    da_push(a, 20);
    da_push(a, 30);
    da_print(a);
    da_remove_at(a, 1);
    da_print(a);
    int out;
    da_get(a, 1, &out);
    printf("Elemento en indice 1: %d\n", out);
    da_destroy(a);


    printf("\n===== Singly Linked List =====\n");
    SLL *l = sll_create();
    sll_insert_front(l, 3);
    sll_insert_back(l, 10);
    sll_insert_at(l, 1, 7);
    sll_print_forward(l);
    sll_remove(l, 10);
    sll_print_forward(l);
    sll_destroy(l);


    printf("\n===== Doubly Linked List =====\n");
    DLL *d = dll_create();
    dll_insert_front(d, 5);
    dll_insert_back(d, 15);
    dll_insert_at(d, 1, 9);
    dll_print_forward(d);
    dll_print_backward(d);
    dll_remove(d, 9);
    dll_print_forward(d);
    dll_destroy(d);


    printf("\n===== Stack =====\n");
    Stack *s = stack_create();
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);

    int value;
    stack_peek(s, &value);
    printf("Peek: %d\n", value);

    while (!stack_is_empty(s)) {
        stack_pop(s, &value);
        printf("Pop: %d\n", value);
    }

    stack_destroy(s);

    return 0;
}
