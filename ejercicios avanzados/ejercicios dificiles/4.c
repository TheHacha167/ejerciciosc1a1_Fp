/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Floyd-Warshall para encontrar las distancias más cortas entre todos los pares de vértices en un grafo ponderado dirigido o no dirigido.

Sugerencia: El algoritmo de Floyd-Warshall resuelve el problema de los caminos más cortos para todos los pares de vértices en un grafo ponderado. Se basa en la técnica de programación dinámica y utiliza una matriz de distancias para almacenar las distancias más cortas entre los vértices.
*/

#include <stdio.h>
#include <stdbool.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V]) {
    printf("Matriz de distancias más cortas entre todos los pares de vértices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    floydWarshall(graph);
    return 0;
}
