/*
  Diseña una función recursiva en C que calcule el factorial de un número.

*/
#include <stdio.h>

int factorial(int n) {
    if(n == 0) { // Caso base
        return 1;
    } else { // Caso recursivo
        return n * factorial(n - 1);
    }
}

int main() {
    int n;

    printf("Introduce un número para calcular su factorial: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("No se puede calcular el factorial de un número negativo\n");
    } else {
        printf("El factorial de %d es %d\n", n, factorial(n));
    }

    return 0;
}
