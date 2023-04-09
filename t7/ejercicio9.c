/*
  Implementa un programa en lenguaje C que cree un puntero y se le asigne memoria con la función malloc().

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *puntero_entero;
    int tamano = 5;

    // Se utiliza la función malloc para asignar memoria al puntero
    puntero_entero = (int*) malloc(tamano * sizeof(int));

    // Se verifica si se asignó correctamente la memoria
    if (puntero_entero == NULL) {
        printf("No se pudo asignar memoria\n");
        return 1;
    }

    // Se utiliza el puntero para asignar valores a los elementos del arreglo
    for(int i = 0; i < tamano; i++) {
        *(puntero_entero + i) = i * 10;
    }

    // Se imprime el contenido del arreglo a través del puntero
    printf("Los valores del arreglo son: ");
    for(int i = 0; i < tamano; i++) {
        printf("%d ", *(puntero_entero + i));
    }
    printf("\n");

    // Se libera la memoria asignada con la función free
    free(puntero_entero);

    return 0;
}
