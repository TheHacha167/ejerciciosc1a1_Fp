/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Kruskal para encontrar el árbol de expansión mínima de un grafo ponderado no dirigido.

Sugerencia: El algoritmo de Kruskal es un algoritmo voraz (greedy) que encuentra un árbol de expansión mínima para un grafo conexo ponderado. Se basa en la técnica de conjunto disjunto para verificar si agregar una arista a un árbol forma un ciclo o no.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 20

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* a_edge = (struct Edge*)a;
    struct Edge* b_edge = (struct Edge*)b;
    return a_edge->weight - b_edge->weight;
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX_EDGES];
    int e = 0;
    int i = 0;
    qsort(graph->edges, graph->E, sizeof(struct Edge), compareEdges);
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d    Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V = 4;  // Número de vértices
    int E = 5;  // Número de aristas
    struct Graph* graph = createGraph(V, E);
    // Agregar aristas al grafo
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;
    KruskalMST(graph);
    return 0;
}
