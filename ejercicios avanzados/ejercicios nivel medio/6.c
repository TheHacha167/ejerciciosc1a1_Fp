/*
Enunciado del Ejercicio:

Escriba un programa en C que calcule el factorial de un número ingresado por el usuario.

Sugerencia: El factorial de un número n se denota como n! y se calcula como el producto de todos los números enteros positivos desde 1 hasta n. Puede usar un bucle para calcular el factorial.

Nota: Asegúrese de manejar correctamente los casos especiales de 0! (que es 1) y 1! (que es también 1).
*/

#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    
    if(num < 0) {
        printf("Error! El factorial de un número negativo no existe.");
    } else {
        printf("El factorial de %d es: %lld", num, factorial(num));
    }

    return 0;
}
