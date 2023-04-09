/*
Implementa un programa en C que convierta la constante 3,14192653 a una cadena.

*/
#include <stdio.h>

#include <stdio.h>

int main() {
    char cadena[20];

    // Se convierte la constante a una cadena
    sprintf(cadena, "%.8f", 3.14192653);

    // Se imprime la cadena resultante
    printf("Cadena: %s\n", cadena);

    return 0;
}
