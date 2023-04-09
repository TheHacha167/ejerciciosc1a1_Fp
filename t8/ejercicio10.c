/*
  Implementa un programa en lenguaje C que introduzca registros con información de personas en un fichero con la función fwrite y posteriormente utilice la función fseek para buscar y obtener la información de una persona determinada.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOMBRE 20
#define TAM_APELLIDO 20
#define TAM_FECHA 10
#define TAM_REGISTRO (TAM_NOMBRE + TAM_APELLIDO + TAM_FECHA + sizeof(int))

struct Persona {
    char nombre[TAM_NOMBRE];
    char apellido[TAM_APELLIDO];
    char fecha[TAM_FECHA];
    int edad;
};

int main() {
    FILE *fichero;
    struct Persona persona, persona_leida;
    int encontrado = 0;

    // Se abre el fichero en modo escritura binaria
    fichero = fopen("personas.dat", "wb");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    // Se escriben los datos de varias personas en el fichero utilizando la función fwrite
    persona = (struct Persona){"Juan", "Perez", "01-01-1990", 31};
    fwrite(&persona, TAM_REGISTRO, 1, fichero);

    persona = (struct Persona){"Maria", "Garcia", "12-05-1985", 36};
    fwrite(&persona, TAM_REGISTRO, 1, fichero);

    persona = (struct Persona){"Luis", "Gomez", "05-03-1995", 26};
    fwrite(&persona, TAM_REGISTRO, 1, fichero);

    // Se cierra el fichero
    fclose(fichero);

    printf("Se han escrito los datos de las personas en el fichero.\n");

    // Se abre el fichero en modo lectura binaria
    fichero = fopen("personas.dat", "rb");

    if(fichero == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    // Se busca la persona con nombre "Maria" utilizando la función fseek
    while(!encontrado && fread(&persona_leida, TAM_REGISTRO, 1, fichero) != 0) {
        if(strcmp(persona_leida.nombre, "Maria") == 0) {
            encontrado = 1;
        }
    }

    // Si se ha encontrado la persona, se muestra su información
    if(encontrado) {
        printf("Persona encontrada:\n");
        printf("Nombre: %s\n", persona_leida.nombre);
        printf("Apellido: %s\n", persona_leida.apellido);
        printf("Fecha de nacimiento: %s\n", persona_leida.fecha);
        printf("Edad: %d\n", persona_leida.edad);
    } else {
        printf("No se ha encontrado ninguna persona con ese nombre\n");
    }

    // Se cierra el fichero
    fclose(fichero);

    return 0;
}
