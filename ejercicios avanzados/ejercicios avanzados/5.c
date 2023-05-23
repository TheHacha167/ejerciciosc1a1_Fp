/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente un árbol binario de búsqueda y realice las operaciones de inserción, búsqueda, y recorrido en orden.

Sugerencia: Un árbol binario de búsqueda es una estructura de datos en la que cada nodo tiene un valor mayor que todos los nodos de su subárbol izquierdo y menor que todos los nodos de su subárbol derecho.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   

    return node;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
       return root;
    
    if (root->key < key)
       return search(root->right, key);
  
    return search(root->left, key);
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Recorrido en orden del árbol binario de búsqueda: ");
    inorder(root);

    printf("\nBuscando el elemento 60 en el árbol: ");
    struct Node* search_node = search(root, 60);
    if (search_node != NULL)
        printf("Elemento encontrado!");
    else
        printf("Elemento no encontrado.");

    return 0;
}
