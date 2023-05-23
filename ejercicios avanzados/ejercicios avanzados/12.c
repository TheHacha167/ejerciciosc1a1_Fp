/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de búsqueda binaria en un árbol binario de búsqueda (BST).

Sugerencia: Un BST es un árbol donde los nodos de la izquierda son menores que el nodo raíz y los nodos de la derecha son mayores. La búsqueda binaria en un BST es más eficiente que en una matriz.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int data) {
    node* newNode = malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* insertNode(node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

node* findNode(node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return findNode(root->right, data);

    return findNode(root->left, data);
}

int main() {
    node* root = NULL;
    root = insertNode(root, 8); 
    insertNode(root, 3);
    insertNode(root, 1); 
    insertNode(root, 6); 
    insertNode(root, 7); 
    insertNode(root, 10);
    insertNode(root, 14);
    insertNode(root, 4);

    node* temp = findNode(root, 10);
    if (temp) {
        printf("Searched node = %d\n", temp->data);
    } else {
        printf("Data Not found in tree.\n");
    }

    return 0;
}
