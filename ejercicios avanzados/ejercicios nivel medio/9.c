/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba dos números enteros ingresados por el usuario y calcule su MCD (Máximo Común Divisor).

Sugerencia: Puede utilizar el algoritmo de Euclides para calcular el MCD. Este algoritmo dice que el MCD de dos números a y b (siendo a > b) es igual al MCD de b y el resto de la división de a entre b.
*/

#include <stdio.h>

int mcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return mcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("El MCD de %d y %d es %d.", num1, num2, mcd(num1, num2));

    return 0;
}
