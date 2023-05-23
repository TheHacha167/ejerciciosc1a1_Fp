/*
Enunciado del Ejercicio:

Escriba un programa en C que encuentre el número más grande en un array de números enteros. El array debe ser llenado por el usuario.

Sugerencia: Utilice un bucle para pedir al usuario que introduzca los números del array y otro bucle para encontrar el número más grande.

*/
#include <stdio.h>

int main() {
    int i, n;
    float arr[100];

    printf("Ingrese la cantidad de elementos (1 a 100): ");
    scanf("%d", &n);

    for(i = 0; i < n; ++i) {
       printf("Ingrese Numero %d: ", i+1);
       scanf("%f", &arr[i]);
    }

    // Suponemos que el primer número es el más grande
    for(i = 1; i < n; ++i) {
       // Si arr[i] es mayor que arr[0], asignamos arr[i] a arr[0]
       if(arr[0] < arr[i])
           arr[0] = arr[i];
    }
    printf("El número más grande es %.2f", arr[0]);

    return 0;
}
