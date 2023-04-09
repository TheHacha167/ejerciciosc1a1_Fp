/*
  Implementa un programa en C que incluya una función que calcule la suma de los componentes de un vector.

*/
#include <stdio.h>

int suma_vector(int vector[], int tamano) {
    int suma = 0;

    for(int i = 0; i < tamano; i++) {
        suma += vector[i];
    }

    return suma;
}

int main() {
    int tamano;

    printf("Introduce el tamaño del vector: ");
    scanf("%d", &tamano);

    int vector[tamano];

    printf("Introduce los elementos del vector:\n");
    for(int i = 0; i < tamano; i++) {
        scanf("%d", &vector[i]);
    }

    int suma = suma_vector(vector, tamano);

    printf("La suma de los elementos del vector es: %d\n", suma);

    return 0;
}
