/*
Implementa un programa en lenguaje C que utilice las funciones strcpy, strcat.

*/
#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char destino[MAX] = "Hola ";
    char origen[MAX] = "mundo";

    // Se copia la cadena origen en la cadena destino
    strcpy(destino, origen);

    printf("Cadena copiada: %s\n", destino);

    // Se concatena la cadena origen en la cadena destino
    strcat(destino, " cruel");

    printf("Cadena concatenada: %s\n", destino);

    return 0;
}
