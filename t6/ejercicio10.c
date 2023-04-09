/*
Implementa un programa en C que compare 2 cadenas y dé como resultado si son iguales, o mayor o menor una que la otra.

*/
#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char cadena1[MAX], cadena2[MAX];
    int resultado;

    printf("Ingrese la primera cadena: ");
    fgets(cadena1, MAX, stdin);

    printf("Ingrese la segunda cadena: ");
    fgets(cadena2, MAX, stdin);

    // Se compara las dos cadenas utilizando la función strcmp
    resultado = strcmp(cadena1, cadena2);

    if(resultado == 0) {
        printf("Las cadenas son iguales.\n");
    } else if(resultado < 0) {
        printf("La cadena \"%s\" es menor que la cadena \"%s\".\n", cadena1, cadena2);
    } else {
        printf("La cadena \"%s\" es mayor que la cadena \"%s\".\n", cadena1, cadena2);
    }

    return 0;
}
