/*
Enunciado del Ejercicio:

Escriba un programa en C que genere los primeros n números de la serie de Fibonacci, donde n es ingresado por el usuario.

Sugerencia: La serie de Fibonacci se genera sumando los dos últimos números de la serie para obtener el siguiente. Los dos primeros números son 0 y 1.
*/

#include <stdio.h>

void fibonacci(int n) {
    long long int t1 = 0, t2 = 1, nextTerm;

    printf("Serie de Fibonacci: ");

    for (int i = 1; i <= n; ++i) {
        printf("%lld, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main() {
    int n;
    printf("Ingrese el número de términos: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}
