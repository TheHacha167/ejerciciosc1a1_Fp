/*
Implementa un programa que copie un array en otro.

*/
#include <stdio.h>

#define SIZE 10

int main() {
    int arr1[SIZE], arr2[SIZE];

    // Se inicializa el primer array con valores del 0 al 9
    for(int i = 0; i < SIZE; i++) {
        arr1[i] = i;
    }

    // Se copia el primer array en el segundo
    for(int i = 0; i < SIZE; i++) {
        arr2[i] = arr1[i];
    }

    // Se imprime el primer array
    printf("Primer array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    // Se imprime el segundo array
    printf("Segundo array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n");

    return 0;
}
