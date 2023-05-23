/*
Enunciado del Ejercicio:

Escriba un programa en C que calcule la suma de los dígitos de un número ingresado por el usuario.

Sugerencia: Puede obtener los dígitos de un número utilizando el operador de módulo (%) y luego sumarlos.
*/

#include <stdio.h>

int sumDigits(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    printf("La suma de los dígitos de %d es %d.", num, sumDigits(num));

    return 0;
}
