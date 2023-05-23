/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Dijkstra para encontrar el camino más corto desde un nodo a todos los demás en un grafo ponderado.

Sugerencia: El algoritmo de Dijkstra es un algoritmo para encontrar el camino más corto entre nodos en un grafo, que puede representar, por ejemplo, redes de carreteras.
*/

#include <stdio.h>
#include <stdlib.h>
#define INF 99999
#define V 5

int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; 
    int sptSet[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = 0;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 }};
    dijkstra(graph, 0);
    return 0;
}
