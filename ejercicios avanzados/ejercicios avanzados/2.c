/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente una lista enlazada simple con las operaciones de inserción al inicio, inserción al final, eliminación al inicio, eliminación al final y visualización.

Sugerencia: Una lista enlazada es una estructura de datos que consta de un conjunto de nodos conectados en secuencia. Cada nodo contiene datos y una referencia (en otras palabras, un enlace) al siguiente nodo en la secuencia.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);

    printf("Lista enlazada creada: ");
    printList(head);

    deleteNode(&head, 1);
    printf("\nLista enlazada después de eliminar el nodo 1: ");
    printList(head);
    
    return 0;
}
