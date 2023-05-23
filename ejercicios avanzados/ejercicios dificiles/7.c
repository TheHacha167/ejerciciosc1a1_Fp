/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de detección de ciclos en un grafo dirigido.

Sugerencia: El algoritmo de detección de ciclos en un grafo dirigido se basa en la técnica de búsqueda en profundidad (DFS). Utiliza una matriz de visitados para realizar un seguimiento de los nodos visitados durante el recorrido y detectar ciclos en el grafo.
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

bool isCyclicUtil(struct Graph* graph, int v, bool visited[], bool recStack[]) {
    if (visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < graph->V; i++) {
            if (graph->adjMatrix[v][i] == 1) {
                if (!visited[i] && isCyclicUtil(graph, i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    bool recStack[MAX_VERTICES] = {false};

    for (int v = 0; v < graph->V; v++) {
        if (isCyclicUtil(graph, v, visited, recStack))
            return true;
    }

    return false;
}

int main() {
    int V = 4;
    struct Graph graph;
    initializeGraph(&graph, V);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 1);

    if (isCyclic(&graph))
        printf("El grafo contiene un ciclo.\n");
    else
        printf("El grafo no contiene ciclos.\n");

    return 0;
}
