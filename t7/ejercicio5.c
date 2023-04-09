/*
  Implementa un programa en C que asigne valores a un array usando punteros.

*/
#include <stdio.h>

#define TAMANIO 5

int main() {
    int numeros[TAMANIO];
    int *puntero_numeros;

    // Se asigna el puntero a la primera posición del array
    puntero_numeros = numeros;

    // Se utiliza un ciclo para asignar valores al array a través del puntero
    for(int i = 0; i < TAMANIO; i++) {
        *(puntero_numeros + i) = i * 10;
    }

    // Se imprime el contenido del array
    printf("Los valores del array son: ");
    for(int i = 0; i < TAMANIO; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}
