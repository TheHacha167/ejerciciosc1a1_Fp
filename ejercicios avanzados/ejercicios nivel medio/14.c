/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba un número entero ingresado por el usuario y genere un triángulo de Pascal de esa altura.

Sugerencia: El triángulo de Pascal se forma sumando los dos números directamente encima de un número para obtener el número siguiente.
*/

#include <stdio.h>

void printPascal(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++) {
            printf("%d ", C);
            C = C * (line - i) / i;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Ingrese la altura del triángulo de Pascal: ");
    scanf("%d", &n);

    printPascal(n);

    return 0;
}
