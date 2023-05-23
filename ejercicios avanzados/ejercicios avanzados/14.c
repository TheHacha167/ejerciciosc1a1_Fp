/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Prim para encontrar el árbol recubridor mínimo de un grafo.

Sugerencia: Un árbol recubridor mínimo es un subgrafo que es un árbol, conecta todos los vértices y tiene el menor peso total de todas las aristas. El algoritmo de Prim es un algoritmo que encuentra este árbol.
*/

#include <stdio.h>
#define INF 9999999
#define V 5

int G[V][V] = { { 0, 9, 75, 0, 0 },
                { 9, 0, 95, 19, 42 },
                { 75, 95, 0, 51, 66 },
                { 0, 19, 51, 0, 31 },
                { 0, 42, 66, 31, 0 } };
int selected[V];

void prim() {
    int x, y;
    int total = 0;
    int min, edge = 0;
    selected[0] = 1;

    printf("Edge : Weight\n");
    while (edge < V - 1) {
        min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        total += G[x][y];
        selected[y] = 1;
        edge++;
    }
    printf("Total weight of MST: %d\n", total);
}

int main() {
    prim();
    return 0;
}
