/*
  Implementar un programa en C que use una función recursiva para ordenar una lista con la técnica Quicksort.

*/
#include <stdio.h>

void quicksort(int arr[], int izquierda, int derecha) {
    if(izquierda >= derecha) { // Caso base: ya está ordenado
        return;
    }

    int pivote = arr[(izquierda + derecha) / 2];
    int i = izquierda, j = derecha;

    while(i <= j) {
        while(arr[i] < pivote) {
            i++;
        }

        while(arr[j] > pivote) {
            j--;
        }

        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quicksort(arr, izquierda, j);
    quicksort(arr, i, derecha);
}

int main() {
    int arr[] = {5, 3, 8, 1, 6, 2, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Array ordenado: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
