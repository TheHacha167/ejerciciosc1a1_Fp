/*
  Implementa un programa en C que muestre el uso de indirecciones con punteros.

*/
#include <stdio.h>

int main() {
    int numero = 10;
    int *puntero_numero;

    // Se asigna el puntero a la dirección de memoria de la variable numero
    puntero_numero = &numero;

    // Se utiliza la indirección para modificar el valor de la variable a través del puntero
    *puntero_numero = 20;

    // Se imprime el valor de la variable utilizando la indirección a través del puntero
    printf("El valor de la variable es: %d\n", *puntero_numero);

    return 0;
}
