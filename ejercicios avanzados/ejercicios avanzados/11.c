/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de Knapsack utilizando programación dinámica.

Sugerencia: El problema del Knapsack o de la mochila es un problema clásico de optimización combinatoria. Se trata de llenar una mochila con capacidad limitada con elementos de distintos pesos y valores de manera que se maximice el valor total.
*/

#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
