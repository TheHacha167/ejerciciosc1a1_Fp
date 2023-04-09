/*
Implementa un programa copie un arrray en otro utilizando una función.

*/
#include <stdio.h>

#define SIZE 10

void copiar_array(int *arr1, int *arr2, int size) {
    for(int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
}

int main() {
    int arr1[SIZE], arr2[SIZE];

    // Se inicializa el primer array con valores del 0 al 9
    for(int i = 0; i < SIZE; i++) {
        arr1[i] = i;
    }

    // Se copia el primer array en el segundo
    copiar_array(arr1, arr2, SIZE);

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
