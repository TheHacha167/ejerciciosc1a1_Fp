/*
Enunciado del Ejercicio:

Escriba un programa en C que ordene un arreglo de n números ingresados por el usuario utilizando el algoritmo de ordenamiento QuickSort.

Sugerencia: El algoritmo QuickSort es un algoritmo de ordenamiento por comparación que utiliza la estrategia "divide y vencerás".
*/

#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
