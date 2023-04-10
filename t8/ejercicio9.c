/*
  Implementa un programa en C que muestre el uso de la función ferror() en ficheros.

*/
#include <stdio.h>

int main() {
    FILE *fichero;
    char caracter;

    // Se abre el fichero en modo lectura
    fichero = fopen("ejemplo.txt", "r");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    // Se intenta leer un carácter del fichero
    caracter = fgetc(fichero);

    // Se comprueba si se ha producido un error durante la lectura del carácter
    if(ferror(fichero)) {
        printf("Se ha producido un error durante la lectura del fichero\n");
        return 1;
    }

    // Se cierra el fichero
    fclose(fichero);

    printf("El primer carácter del fichero es '%c'\n", caracter);

    return 0;
}
