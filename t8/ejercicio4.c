/*
  Implementa un programa en C que abra un fichero, entre 3 opciones y lea su información sucesivamente y la muestre por pantalla.

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fichero;
    fichero = fopen("datos.txt", "r");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    int opcion;
    printf("Seleccione una opción:\n");
    printf("1. Leer todo el contenido del fichero\n");
    printf("2. Leer el contenido del fichero línea por línea\n");
    printf("3. Leer el contenido del fichero palabra por palabra\n");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Contenido del fichero:\n");

            // Se lee el contenido completo del fichero y se muestra por pantalla
            char caracter;
            while((caracter = fgetc(fichero)) != EOF) {
                printf("%c", caracter);
            }
            break;

        case 2:
            printf("Contenido del fichero línea por línea:\n");

            // Se lee el contenido del fichero línea por línea y se muestra por pantalla
            char linea[100];
            while(fgets(linea, 100, fichero) != NULL) {
                printf("%s", linea);
            }
            break;

        case 3:
            printf("Contenido del fichero palabra por palabra:\n");

            // Se lee el contenido del fichero palabra por palabra y se muestra por pantalla
            char palabra[20];
            while(fscanf(fichero, "%s", palabra) != EOF) {
                printf("%s ", palabra);
            }
            break;

        default:
            printf("Opción inválida\n");
            break;
    }

    // Se cierra el fichero
    fclose(fichero);

    return 0;
}
