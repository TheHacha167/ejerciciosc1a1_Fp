/*
  Implementa un programa que escriba datos formateados (fprintf) en un fichero.

*/
#include <stdio.h>

int main() {
    FILE *fichero;
    fichero = fopen("datos.txt", "w");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    char nombre[20];
    int edad;
    float promedio;

    printf("Introduce el nombre del estudiante: ");
    scanf("%s", nombre);
    printf("Introduce la edad del estudiante: ");
    scanf("%d", &edad);
    printf("Introduce el promedio del estudiante: ");
    scanf("%f", &promedio);

    // Se escriben los datos del estudiante en el fichero utilizando la función fprintf
    fprintf(fichero, "Nombre: %s\n", nombre);
    fprintf(fichero, "Edad: %d\n", edad);
    fprintf(fichero, "Promedio: %.2f\n", promedio);

    // Se cierra el fichero
    fclose(fichero);

    printf("Se han escrito los datos del estudiante en el fichero.\n");

    return 0;
}
