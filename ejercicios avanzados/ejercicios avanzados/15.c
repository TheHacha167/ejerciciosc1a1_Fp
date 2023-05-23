/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente el algoritmo de eliminación de Gauss-Jordan para resolver un sistema de ecuaciones lineales.

Sugerencia: El algoritmo de Gauss-Jordan es un algoritmo que puede utilizarse para resolver sistemas de ecuaciones lineales y para encontrar la inversa de cualquier matriz invertible.
*/

#include<stdio.h>

#define N 3

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void gaussJordan(float a[N][N+1]) {
    for (int i = 0; i < N; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for (int j = 0; j < N; j++) {
            if (i != j) {
                float ratio = a[j][i]/a[i][i];

                for (int k = 0; k <= N; k++)
                    a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
}

void printMatrix(float a[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++)
            printf("%.2f ", a[i][j]);
        printf("\n");
    }
}

void printResult(float a[N][N+1]) {
    printf("\nResult is : ");
    for (int i = 0; i < N; i++)
        printf("%.2f ", a[i][N]/a[i][i]);
}

int main() {
    float a[N][N+1] = { { 3.0, 2.0, -4.0, 3.0 },
                        { 2.0, 3.0, 3.0, 15.0 },
                        { 5.0, -3, 1.0, 14.0 } };
    gaussJordan(a);
    printMatrix(a);
    printResult(a);
    return 0;
}
