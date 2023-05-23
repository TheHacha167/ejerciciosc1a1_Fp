/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de ordenamiento topológico en un grafo dirigido acíclico (DAG).

Sugerencia: El algoritmo de ordenamiento topológico es un algoritmo utilizado para ordenar los vértices de un DAG de manera lineal, de tal manera que para cada arista dirigida uv, el vértice u aparece antes que el vértice v en el orden topológico. El algoritmo utiliza una combinación de búsqueda en profundidad (DFS) y una pila para realizar el ordenamiento.
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
}

void topologicalSortUtil(struct Graph* graph, int v, bool visited[], int* stack, int* index) {
    visited[v] = true;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[v][i] == 1 && !visited[i])
            topologicalSortUtil(graph, i, visited, stack, index);
    }

    stack[(*index)++] = v;
}

void topologicalSort(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES];
    int index = 0;

    for (int v = 0; v < graph->V; v++) {
        if (!visited[v])
            topologicalSortUtil(graph, v, visited, stack, &index);
    }

    printf("Orden topológico del grafo:\n");
    for (int i = index - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int V = 6;
    struct Graph graph;
    initializeGraph(&graph, V);

    addEdge(&graph, 5, 2);
    addEdge(&graph, 5, 0);
    addEdge(&graph, 4, 0);
    addEdge(&graph, 4, 1);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 1);

    topologicalSort(&graph);

    return 0;
}
