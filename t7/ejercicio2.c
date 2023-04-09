/*
  Implementa un programa en C que muestre el uso de operaciones aritméticas con punteros.
*/
#include <stdio.h>

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int *puntero_numeros;

    // Se asigna el puntero a la primera posición del array
    puntero_numeros = numeros;

    printf("Los valores del array son: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(puntero_numeros + i));
    }

    printf("\nEl valor del primer elemento es: %d\n", *puntero_numeros);

    // Se realiza una operación aritmética con el puntero
    puntero_numeros += 2;

    printf("El valor del tercer elemento es: %d\n", *puntero_numeros);

    return 0;
}
