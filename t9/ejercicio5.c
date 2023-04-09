/*
  Escribe una función recursiva en C que calcule el máximo común divisor de dos números.

*/
#include <stdio.h>

int mcd(int a, int b) {
    if(b == 0) { // Caso base
        return a;
    } else { // Caso recursivo
        return mcd(b, a % b);
    }
}

int main() {
    int a, b;

    printf("Introduce dos números enteros: ");
    scanf("%d %d", &a, &b);

    if(a < 0 || b < 0) {
        printf("Los números introducidos deben ser positivos\n");
    } else {
        printf("El MCD de %d y %d es %d\n", a, b, mcd(a, b));
    }

    return 0;
}
