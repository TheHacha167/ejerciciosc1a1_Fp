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

    char cadena1[] = "Hola mundo!";
    char cadena2[] = "Este es un ejemplo de escritura en un fichero.";
    char cadena3[] = "Hasta luego!";

    // Se escriben las cadenas en el fichero utilizando la función puts
    puts(cadena1);
    fputs(cadena1, fichero);

    puts(cadena2);
    fputs(cadena2, fichero);

    puts(cadena3);
    fputs(cadena3, fichero);

    // Se cierra el fichero
    fclose(fichero);

    return 0;
}
