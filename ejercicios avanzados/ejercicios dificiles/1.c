/*
Enunciado del Ejercicio:

Implementar un programa en C que simule el comportamiento de un sistema operativo en cuanto a la asignación de memoria utilizando el algoritmo de First Fit. Debe permitir que los usuarios soliciten memoria y que la liberen.

Sugerencia: El algoritmo First Fit se utiliza en la gestión de memoria y se basa en buscar el primer bloque de memoria que sea suficiente para alojar los datos.
*/

#include <stdio.h>

#define MAX 10000

char memory[MAX];

struct block {
    int size;
    int free;
    char *address;
};

struct block *flist;

void initialize() {
    flist->size = MAX;
    flist->free = 1;
    flist->address = memory;
}

void split(struct block *fitting_slot, int size) {
    struct block *new = (void *)((void *)fitting_slot + size);
    new->size = (fitting_slot->size) - size;
    new->free = 1;
    new->address = fitting_slot->address + size;
    fitting_slot->size = size;
    fitting_slot->free = 0;
}

void *my_malloc(int size) {
    struct block *curr = flist;
    while ((curr->size < size || (curr->free == 0)) && (curr->address < memory + MAX)) {
        curr = (void *)(curr + 1);
    }
    if (curr->address == memory + MAX) {
        return NULL;
    } else {
        split(curr, size);
    }
    return (void *)curr;
}

// Este es un esquema básico de cómo se podría implementar esto en C. Deberás expandir y personalizar este código para satisfacer las necesidades específicas de tu programa.
