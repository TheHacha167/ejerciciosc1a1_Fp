/*
  Implementa un programa que lea la información de estudiantes de un fichero.

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ESTUDIANTES 100
#define MAX_NOMBRE 50

// Se define la estructura para representar un estudiante
struct estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
};

int main() {
    FILE *fichero;
    fichero = fopen("estudiantes.txt", "r");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    // Se define un array de estudiantes
    struct estudiante estudiantes[MAX_ESTUDIANTES];

    // Se leen los estudiantes desde el fichero
    int i = 0;
    while(fscanf(fichero, "%s %d %f", estudiantes[i].nombre, &estudiantes[i].edad, &estudiantes[i].promedio) != EOF) {
        i++;
    }

    // Se cierra el fichero
    fclose(fichero);

    // Se imprime la información de los estudiantes
    for(int j = 0; j < i; j++) {
        printf("Estudiante %d:\n", j+1);
        printf("Nombre: %s\n", estudiantes[j].nombre);
        printf("Edad: %d\n", estudiantes[j].edad);
        printf("Promedio: %.2f\n", estudiantes[j].promedio);
    }

    return 0;
}
