/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de búsqueda de profundidad (DFS) para un grafo representado usando una lista de adyacencia.

Sugerencia: DFS es un algoritmo para recorrer o buscar estructuras de datos de árbol o grafo. Comienza en la raíz y explora lo más posible a lo largo de cada rama antes de retroceder.
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph {
    int numVertices;
    int* visited;
    struct node** adjLists;
};

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while(temp != NULL) {
        int connectedVertex = temp->vertex;

        if(graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }       
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    DFS(graph, 2);

    return 0;
}
