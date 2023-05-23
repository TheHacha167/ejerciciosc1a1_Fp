/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Prim para encontrar el árbol de expansión mínima en un grafo no dirigido ponderado.

Sugerencia: El algoritmo de Prim es un algoritmo voraz (greedy) que encuentra el árbol de expansión mínima para un grafo no dirigido ponderado. Se basa en la idea de agregar aristas al árbol de forma incremental, seleccionando siempre la arista de menor peso que conecte un vértice en el árbol con un vértice fuera del árbol.
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

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

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

int findMinKey(int key[], bool mstSet[], int V) {
    int minKey = INF;
    int minKeyVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minKeyVertex = v;
        }
    }

    return minKeyVertex;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Aristas en el Árbol de Expansión Mínima:\n");
    printf("Arista\tPeso\n");
    for (int v = 1; v < V; v++)
        printf("%d - %d\t%d\n", parent[v], v, graph[v][parent[v]]);
}

void primMST(struct Graph* graph) {
    int V = graph->V;
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int v = 0; v < V; v++) {
        key[v] = INF;
        mstSet[v] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph->adjMatrix[u][v] != 0 && !mstSet[v] && graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    printMST(parent, graph->adjMatrix, V);
}

int main() {
    int V = 5;
    struct Graph graph;
    initializeGraph(&graph, V);

    addEdge(&graph, 0, 1, 2);
    addEdge(&graph, 0, 3, 6);
    addEdge(&graph, 1, 2, 3);
    addEdge(&graph, 1, 3, 8);
    addEdge(&graph, 1, 4, 5);
    addEdge(&graph, 2, 4, 7);
    addEdge(&graph, 3, 4, 9);

    primMST(&graph);

    return 0;
}
