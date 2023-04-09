/*
  Implementa un programa en C que muestre el uso de fwrite en un fichero.

*/
#include <stdio.h>

struct estudiante {
    char nombre[20];
    int edad;
    float promedio;
};

int main() {
    FILE *fichero;
    struct estudiante e1 = {"Juan", 20, 8.7};
    struct estudiante e2 = {"Maria", 19, 9.2};

    // Se abre el fichero en modo escritura binaria
    fichero = fopen("estudiantes.dat", "wb");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    // Se escriben los datos de los estudiantes en el fichero utilizando la función fwrite
    fwrite(&e1, sizeof(struct estudiante), 1, fichero);
    fwrite(&e2, sizeof(struct estudiante), 1, fichero);

    // Se cierra el fichero
    fclose(fichero);

    printf("Se han escrito los datos de los estudiantes en el fichero.\n");

    return 0;
}
