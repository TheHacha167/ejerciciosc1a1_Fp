/*
Implementa un programa que liste las notas de cada alumno y su media. Cada alumno puede tener un máximo de cinco asignaturas, aunque puede tener como mínimo 2. Número de alumnos: 10, número de asignaturas: 2-5.

*/
#include <stdio.h>

int main() {
    int num_alumnos = 10;
    int num_asignaturas;
    float nota, sum, media;

    for(int i = 1; i <= num_alumnos; i++) {
        printf("Alumno %d\n", i);
        printf("Ingrese el numero de asignaturas (minimo 2, maximo 5): ");
        scanf("%d", &num_asignaturas);

        sum = 0.0;

        if(num_asignaturas < 2 || num_asignaturas > 5) {
            printf("El numero de asignaturas debe estar entre 2 y 5.\n");
            i--;
            continue;
        }

        for(int j = 1; j <= num_asignaturas; j++) {
            printf("Ingrese la nota de la asignatura %d: ", j);
            scanf("%f", &nota);

            sum += nota;
        }

        media = sum / num_asignaturas;

        printf("Notas: ");
        for(int j = 1; j <= num_asignaturas; j++) {
            printf("%.1f ", nota);
        }
        printf("\n");

        printf("Media: %.2f\n\n", media);
    }

    return 0;
}
