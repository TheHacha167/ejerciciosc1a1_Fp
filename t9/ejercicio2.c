/*
  Escribe un programa en C que incluya una función recursiva que calcule la potencia de un número.

*/
#include <stdio.h>

double potencia(double base, int exponente) {
    if(exponente == 0) { // Caso base
        return 1;
    } else if(exponente > 0) { // Caso positivo
        return base * potencia(base, exponente - 1);
    } else { // Caso negativo
        return 1 / base * potencia(base, exponente + 1);
    }
}

int main() {
    double base, resultado;
    int exponente;

    printf("Introduce la base: ");
    scanf("%lf", &base);

    printf("Introduce el exponente: ");
    scanf("%d", &exponente);

    resultado = potencia(base, exponente);

    printf("%lf elevado a %d es %lf\n", base, exponente, resultado);

    return 0;
}
