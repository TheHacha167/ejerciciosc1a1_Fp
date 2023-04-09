/*
  Implementa un programa que incluya una función recursiva que calcule la serie de Fibonacci de un número.

*/
#include <stdio.h>

int fibonacci(int n) {
    if(n == 0) { // Caso base
        return 0;
    } else if(n == 1) { // Caso base
        return 1;
    } else { // Caso recursivo
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Introduce un número: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("El número debe ser positivo\n");
    } else {
        printf("El %d-ésimo número de la serie de Fibonacci es %d\n", n, fibonacci(n));
    }

    return 0;
}
