/*
Implementa un programa en lenguaje C que muestre el uso de la función strlen().

*/
#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char cadena[MAX] = "Hola mundo!";

    // Se calcula la longitud de la cadena utilizando la función strlen
    int longitud = strlen(cadena);

    printf("La cadena \"%s\" tiene una longitud de %d caracteres.\n", cadena, longitud);

    return 0;
}
