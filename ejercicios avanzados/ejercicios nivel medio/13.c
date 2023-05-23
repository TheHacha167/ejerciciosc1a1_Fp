/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba un número entero ingresado por el usuario y determine si es un número Armstrong.

Sugerencia: Un número es Armstrong si la suma de los cubos de sus dígitos es igual al número mismo.
*/

#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int originalNum, remainder, result = 0;
    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, 3);
        originalNum /= 10;
    }

    if(result == num)
        return 1;
    else
        return 0;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    if(isArmstrong(num)) {
        printf("%d es un número Armstrong.", num);
    } else {
        printf("%d no es un número Armstrong.", num);
    }

    return 0;
}
