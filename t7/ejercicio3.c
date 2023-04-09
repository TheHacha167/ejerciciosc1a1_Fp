/*
  Implementa un programa que muestre el uso de punteros y arrays.

*/
#include <stdio.h>

#define TAMANIO 5

int main() {
    int numeros[TAMANIO] = {10, 20, 30, 40, 50};
    int *puntero_numeros;

    // Se asigna el puntero a la primera posición del array
    puntero_numeros = numeros;

    printf("Los valores del array son: ");
    for(int i = 0; i < TAMANIO; i++) {
        printf("%d ", *(puntero_numeros + i));
    }

    printf("\nLa dirección de memoria del primer elemento es: %p\n", puntero_numeros);
    printf("La dirección de memoria del segundo elemento es: %p\n", puntero_numeros + 1);

    return 0;
}
