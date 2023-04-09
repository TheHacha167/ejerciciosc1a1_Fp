/*
  Implementa un programa en C que incluya una función que realice una búsqueda dicotómica en un array.

*/
#include <stdio.h>

int busqueda_dicotomica(int arr[], int n, int clave) {
    int izquierda = 0, derecha = n - 1;

    while(izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;

        if(arr[medio] == clave) {
            return medio;
        } else if(arr[medio] < clave) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1; // Si no se encuentra la clave, se devuelve -1
}

int main() {
    int arr[] = {1, 3, 4, 6, 8, 9, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int clave;

    printf("Introduce la clave a buscar: ");
    scanf("%d", &clave);

    int indice = busqueda_dicotomica(arr, n, clave);

    if(indice == -1) {
        printf("La clave no se encuentra en el array\n");
    } else {
        printf("La clave se encuentra en el índice %d del array\n", indice);
    }

    return 0;
}
