/*
  Implementa un programa en C defina un puntero a una estructura y se pase como argumento a una función.

*/
#include <stdio.h>

// Se define la estructura
struct persona {
    char nombre[20];
    int edad;
};

// Se define la función que recibe un puntero a la estructura como argumento
void imprimir_persona(struct persona *puntero_persona) {
    printf("Nombre: %s\n", puntero_persona->nombre);
    printf("Edad: %d\n", puntero_persona->edad);
}

int main() {
    // Se declara una variable de la estructura
    struct persona p = {"Juan", 25};

    // Se declara un puntero a la estructura y se asigna a la dirección de la variable
    struct persona *puntero_p = &p;

    // Se llama a la función y se pasa el puntero como argumento
    imprimir_persona(puntero_p);

    return 0;
}
