#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
    struct Edge* next;
};

struct Graph {
    int V, E;
    struct Edge* edges[MAX_VERTICES];
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    for (int i = 0; i < V; i++) {
        graph->edges[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    edge->next = NULL;

    // Agregar arista al inicio de la lista de adyacencia del origen
    edge->next = graph->edges[src];
    graph->edges[src] = edge;

    // Agregar arista al inicio de la lista de adyacencia del destino (grafo no dirigido)
    edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->src = dest;
    edge->dest = src;
    edge->weight = weight;
    edge->next = NULL;

    edge->next = graph->edges[dest];
    graph->edges[dest] = edge;
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

void unionSets(struct Subset subsets[], int x, int y) {
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
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0; // Índice del resultado
    int i = 0; // Índice de las aristas ordenadas por peso

    // Ordenar las aristas por peso de forma ascendente
    qsort(graph->edges, graph->E, sizeof(struct Edge*), compareEdges);

    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge* nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge->src);
        int y = find(subsets, nextEdge->dest);

        // Si la inclusión de la arista no crea un ciclo, se agrega al resultado
        if (x != y) {
            result[e++] = *nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Aristas en el Árbol de Expansión Mínima:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d\t%d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V = 5;
    int E = 7;
    struct Graph* graph = createGraph(V, E);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    kruskalMST(graph);

    return 0;
}
