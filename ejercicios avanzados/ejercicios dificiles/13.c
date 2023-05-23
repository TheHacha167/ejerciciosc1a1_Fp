/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Floyd-Warshall para encontrar todos los caminos más cortos entre todos los pares de vértices en un grafo dirigido ponderado.

Sugerencia: El algoritmo de Floyd-Warshall es un algoritmo de programación dinámica que encuentra todos los caminos más cortos entre todos los pares de vértices en un grafo dirigido ponderado. Utiliza una matriz de distancias para realizar un seguimiento de las distancias mínimas entre los vértices y actualiza la matriz iterativamente para encontrar los caminos más cortos.
*/

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int dist[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Matriz de distancias:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 4;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph, V);

    return 0;
}
