/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de búsqueda en profundidad (DFS) en un grafo no dirigido.

Sugerencia: El algoritmo de búsqueda en profundidad (DFS) es un algoritmo de recorrido utilizado para explorar o buscar en un grafo o árbol. Utiliza una pila o la recursión para visitar todos los vértices alcanzables desde un vértice de inicio.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initializeGraph(struct Graph* graph, int V) {
    graph->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void DFSUtil(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[v][i] == 1 && !visited[i])
            DFSUtil(graph, i, visited);
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    DFSUtil(graph, startVertex, visited);
}

int main() {
    int V = 7;
    struct Graph graph;
    initializeGraph(&graph, V);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 2, 6);

    int startVertex = 0;
    printf("Recorrido DFS desde el vértice %d: ", startVertex);
    DFS(&graph, startVertex);
    printf("\n");

    return 0;
}
