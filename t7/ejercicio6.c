/*
  Implementa un programa en C que muestre el uso de matrices de punteros.

*/
#include <stdio.h>

#define FILAS 3
#define COLUMNAS 2

int main() {
    int numeros[FILAS][COLUMNAS] = {
        {10, 20},
        {30, 40},
        {50, 60}
    };

    int *punteros[FILAS];

    // Se asignan los punteros a las filas de la matriz
    for(int i = 0; i < FILAS; i++) {
        punteros[i] = numeros[i];
    }

    // Se imprimen los valores de la matriz utilizando los punteros
    printf("Los valores de la matriz son:\n");
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("%d ", *(punteros[i] + j));
        }
        printf("\n");
    }

    return 0;
}
