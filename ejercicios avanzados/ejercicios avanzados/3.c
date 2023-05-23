/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente una pila (stack) con las operaciones push, pop y display usando una lista enlazada.

Sugerencia: Una pila es una estructura de datos que sigue la disciplina LIFO (Last In First Out). Las operaciones push y pop se realizan en el extremo superior de la pila.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    struct Node* top;
    int res;
    if (*top_ref == NULL) {
        printf("Stack underflow \n");
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

void display(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    printf("Stack: ");
    display(top);

    printf("\nDespués de hacer pop: ");
    pop(&top);
    display(top);

    return 0;
}
