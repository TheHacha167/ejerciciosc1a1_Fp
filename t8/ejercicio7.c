/*
  Implementa un programa en C que copie un fichero en otro fichero.

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fichero_original, *fichero_copia;
    char caracter;

    // Se abre el fichero original en modo lectura
    fichero_original = fopen("original.txt", "r");

    if(fichero_original == NULL) {
        printf("Error al abrir el fichero original\n");
        return 1;
    }

    // Se abre el fichero copia en modo escritura
    fichero_copia = fopen("copia.txt", "w");

    if(fichero_copia == NULL) {
        printf("Error al abrir el fichero copia\n");
        return 1;
    }

    // Se lee el fichero original y se copia en el fichero copia
    while((caracter = fgetc(fichero_original)) != EOF) {
        fputc(caracter, fichero_copia);
    }

    // Se cierran ambos ficheros
    fclose(fichero_original);
    fclose(fichero_copia);

    printf("Se ha copiado el fichero correctamente.\n");

    return 0;
}
