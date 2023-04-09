/*
  Implementa un programa que defina un puntero a un entero.

*/
#include <stdio.h>

int main() {
    int *puntero_entero;
    int entero = 10;

    // Se asigna la dirección de memoria del entero al puntero
    puntero_entero = &entero;

    printf("El valor del entero es: %d\n", entero);
    printf("La dirección de memoria del entero es: %p\n", &entero);
    printf("El valor del puntero es: %p\n", puntero_entero);

    return 0;
}
