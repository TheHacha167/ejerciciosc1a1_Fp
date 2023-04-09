/*
  Escribe un programa en C que cree un archivo e introducir el texto que el usuario introduce por teclado.

*/
#include <stdio.h>

int main() {
    FILE *fichero;
    fichero = fopen("ejemplo.txt", "w");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    char texto[100];

    printf("Introduce el texto que quieres escribir en el fichero:\n");
    fgets(texto, 100, stdin);

    // Se escribe el texto en el fichero utilizando la función fprintf
    fprintf(fichero, "%s", texto);

    // Se cierra el fichero
    fclose(fichero);

    printf("Se ha escrito el texto en el fichero.\n");

    return 0;
}
