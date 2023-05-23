/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba un número entero ingresado por el usuario y verifique si el número es primo.

Sugerencia: Un número es primo si solo tiene dos divisores distintos: él mismo y 1. Puede usar un bucle para verificar si el número tiene otros divisores.

Nota: Asegúrese de manejar correctamente el caso especial de 1, que no es un número primo.
*/

#include <stdio.h>

int isPrime(int num) {
    if(num <= 1) {
        return 0;
    }
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    if(isPrime(num)) {
        printf("%d es un número primo.", num);
    } else {
        printf("%d no es un número primo.", num);
    }

    return 0;
}
