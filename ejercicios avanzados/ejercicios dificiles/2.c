/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de búsqueda A* (A-star) para encontrar la ruta más corta en un grafo ponderado con heurísticas.

Sugerencia: El algoritmo de búsqueda A* combina el algoritmo de búsqueda en grafo y una función heurística para encontrar la ruta más corta entre un nodo inicial y un nodo objetivo en un grafo ponderado. La función heurística es una estimación de la distancia entre un nodo y el nodo objetivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 6

int graph[SIZE][SIZE] = {{0, 5, 0, 9, 0, 0},
                         {5, 0, 2, 0, 4, 0},
                         {0, 2, 0, 3, 0, 0},
                         {9, 0, 3, 0, 2, 7},
                         {0, 4, 0, 2, 0, 0},
                         {0, 0, 0, 7, 0, 0}};

int heuristic[SIZE] = {10, 9, 7, 8, 6, 0};

typedef struct Node {
    int vertex;
    int f;
    int g;
    struct Node* parent;
} Node;

Node* createNode(int vertex, int f, int g, Node* parent) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->f = f;
    newNode->g = g;
    newNode->parent = parent;
    return newNode;
}

Node* insertNode(Node* heap[], Node* element, int* heapSize) {
    (*heapSize)++;
    int i = *heapSize;
    while (i > 1 && element->f < heap[i/2]->f) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = element;
    return heap;
}

Node* deleteNode(Node* heap[], int* heapSize) {
    Node* minNode, * lastNode;
    int child, i;
    minNode = heap[1];
    lastNode = heap[(*heapSize)--];
    for (i = 1; i*2 <= *heapSize; i = child) {
        child = i*2;
        if (child != *heapSize && heap[child+1]->f < heap[child]->f)
            child++;
        if (lastNode->f > heap[child]->f)
            heap[i] = heap[child];
        else
            break;
    }
    heap[i] = lastNode;
    return minNode;
}

bool isVisited(Node* visited[], int vertex, int* visitedSize) {
    for (int i = 0; i < *visitedSize; i++) {
        if (visited[i]->vertex == vertex)
            return true;
    }
    return false;
}

void printPath(Node* current) {
    if (current->parent != NULL)
        printPath(current->parent);
    printf("%d ", current->vertex);
}

void aStar(int startVertex, int goalVertex) {
    Node* heap[SIZE*SIZE];
    int heapSize = 0;
    int visitedSize = 0;
    Node* visited[SIZE*SIZE] = {NULL};
    Node* startNode = createNode(startVertex, 0, 0, NULL);
    insertNode(heap, startNode, &heapSize);
    while (heapSize != 0) {
        Node* current = deleteNode(heap, &heapSize);
        visited[visitedSize++] = current;
        if (current->vertex == goalVertex) {
            printf("Optimal Path: ");
            printPath(current);
            return;
        }
        for (int i = 0; i < SIZE; i++) {
            if (graph[current->vertex][i] != 0 && !isVisited(visited, i, &visitedSize)) {
                int g = current->g + graph[current->vertex][i];
                int h = heuristic[i];
                Node* newNode = createNode(i, g+h, g, current);
                insertNode(heap, newNode, &heapSize);
            }
        }
    }
    printf("Path not found.\n");
}

int main() {
    int startVertex = 0;
    int goalVertex = 5;
    aStar(startVertex, goalVertex);
    return 0;
}
