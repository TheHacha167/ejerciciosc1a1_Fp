/*
  Implementa un programa en C que incluya una función recursiva que calcule la división entera.

*/
#include <stdio.h>

int division_entera(int dividendo, int divisor) {
    if(dividendo < divisor) { // Caso base
        return 0;
    } else { // Caso recursivo
        return 1 + division_entera(dividendo - divisor, divisor);
    }
}

int main() {
    int dividendo, divisor;

    printf("Introduce el dividendo: ");
    scanf("%d", &dividendo);

    printf("Introduce el divisor: ");
    scanf("%d", &divisor);

    if(divisor == 0) {
        printf("El divisor no puede ser cero\n");
    } else {
        int resultado = division_entera(dividendo, divisor);
        printf("%d / %d = %d\n", dividendo, divisor, resultado);
    }

    return 0;
}
