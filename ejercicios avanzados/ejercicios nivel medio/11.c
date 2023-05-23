/*
Enunciado del Ejercicio:

Escriba un programa en C que intercambie los valores de dos variables ingresadas por el usuario sin usar una tercera variable.

Sugerencia: Puede realizar el intercambio usando operaciones aritméticas.
*/

#include <stdio.h>

int main() {
    int a, b;
    printf("Ingrese el primer número (a): ");
    scanf("%d", &a);
    printf("Ingrese el segundo número (b): ");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Después del intercambio, a = %d y b = %d.", a, b);

    return 0;
}
