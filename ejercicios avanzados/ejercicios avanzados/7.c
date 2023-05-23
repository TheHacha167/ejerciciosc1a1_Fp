/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente un hash table con colisiones manejadas por encadenamiento (separate chaining).

Sugerencia: Un hash table es una estructura de datos que implementa una matriz asociativa, una estructura que puede asignar claves a valores. Un hash table utiliza una función de hash para calcular un índice en un array de buckets o slots, desde los cuales se puede buscar el valor deseado.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, val;
    struct Node* next;
} Node;

typedef struct Table {
    Node** list;
    int size;
} Table;

Node* createNode(int key, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Node creation failed\n");
        exit(0);
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Table* createTable(int size) {
    Table* table = (Table*)malloc(sizeof(Table));
    if (!table) {
        printf("Table creation failed\n");
        exit(0);
    }
    table->size = size;
    table->list = (Node**)malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++)
        table->list[i] = NULL;
    return table;
}

int hashCode(Table* t, int key) {
    if (key < 0)
        return -(key % t->size);
    return key % t->size;
}

void insert(Table* t, int key, int val) {
    int pos = hashCode(t, key);
    Node* list = t->list[pos];
    Node* newNode = createNode(key, val);
    Node* temp = list;
    while (temp) {
        if (temp->key == key) {
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->next = list;
    t->list[pos] = newNode;
}

int search(Table* t, int key) {
    int pos = hashCode(t, key);
    Node* list = t->list[pos];
    Node* temp = list;
    while (temp) {
        if (temp->key == key) {
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}

void display(Table* t) {
    for (int i = 0; i < t->size; i++) {
        Node* temp = t->list[i];
        printf("Position %d: ", i);
        while (temp) {
            printf("(%d,%d) -> ", temp->key, temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Table* t = createTable(5);
    insert(t, 1, 1);
    insert(t, 2, 2);
    insert(t, 3, 3);
    insert(t, 4, 4);
    display(t);
    printf("Searching for key 2: %d", search(t, 2));
    return 0;
}
