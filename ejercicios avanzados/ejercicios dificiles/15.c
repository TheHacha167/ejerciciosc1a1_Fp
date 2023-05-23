/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Dijkstra para encontrar el camino más corto desde un vértice de origen a todos los demás vértices en un grafo dirigido ponderado.

Sugerencia: El algoritmo de Dijkstra es un algoritmo de búsqueda de caminos mínimos que encuentra el camino más corto desde un vértice de origen a todos los demás vértices en un grafo dirigido ponderado. Utiliza una lista de nodos no visitados y va seleccionando el nodo con la distancia más corta en cada iteración.
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
}

int findMinDistance(int dist[], bool visited[], int V) {
    int minDist = INF;
    int minDistVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minDistVertex = v;
        }
    }

    return minDistVertex;
}

void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d ", vertex);
        return;
    }

    printPath(parent, parent[vertex]);
    printf("%d ", vertex);
}

void printSolution(int dist[], int parent[], int startVertex, int V) {
    printf("Distancias desde el vértice %d:\n", startVertex);
    printf("Vértice\tDistancia\tCamino\n");
    for (int v = 0; v < V; v++) {
        printf("%d\t%d\t\t", v, dist[v]);
        printPath(parent, v);
        printf("\n");
    }
}

void dijkstra(struct Graph* graph, int startVertex) {
    int V = graph->V;
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        visited[v] = false;
        parent[v] = -1;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph->adjMatrix[u][v] != 0 && dist[u] != INF &&
                dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, startVertex, V);
}

int main() {
    int V = 6;
    struct Graph graph;
    initializeGraph(&graph, V);

    addEdge(&graph, 0, 1, 4);
    addEdge(&graph, 0, 2, 1);
    addEdge(&graph, 1, 3, 1);
    addEdge(&graph, 2, 1, 2);
    addEdge(&graph, 2, 3, 5);
    addEdge(&graph, 3, 4, 3);
    addEdge(&graph, 4, 2, 3);
    addEdge(&graph, 4, 5, 2);
    addEdge(&graph, 5, 3, 1);

    int startVertex = 0;
    dijkstra(&graph, startVertex);

    return 0;
}
