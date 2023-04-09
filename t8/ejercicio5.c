/*
  Escribe datos en un fichero carácter a carácter.

*/
#include <stdio.h>

int main() {
    FILE *fichero;
    fichero = fopen("ejemplo.txt", "w");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    char caracter;
    printf("Introduce los caracteres que quieres escribir en el fichero (termina con Ctrl + D en Unix o Ctrl + Z en Windows):\n");

    // Se lee el caracter introducido por el usuario desde la entrada estándar (teclado)
    while((caracter = getchar()) != EOF) {
        // Se escribe el caracter en el fichero utilizando la función fputc
        fputc(caracter, fichero);
    }

    // Se cierra el fichero
    fclose(fichero);

    printf("Se ha escrito el texto en el fichero.\n");

    return 0;
}
