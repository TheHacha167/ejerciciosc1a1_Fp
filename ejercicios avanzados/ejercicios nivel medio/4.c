/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba dos matrices cuadradas de tamaño 3x3 ingresadas por el usuario y luego calcule la suma de las dos matrices.

Sugerencia: Las matrices en C se pueden representar como arrays bidimensionales. Podrías utilizar bucles anidados para recoger y sumar los elementos de las matrices.
*/

#include <stdio.h>

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j;

    printf("Ingrese los elementos de la primera matriz 3x3:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Ingrese el elemento en la posición (%d, %d): ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nIngrese los elementos de la segunda matriz 3x3:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Ingrese el elemento en la posición (%d, %d): ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    // Sumar las dos matrices y guardar el resultado en C
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nLa suma de las dos matrices es:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
