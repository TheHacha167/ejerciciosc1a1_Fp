/*
Usa la función fflush para limpiar el buffer de entrada.

*/
#include <stdio.h>

int main() {
    char c;

    printf("Ingrese un caracter: ");
    fflush(stdout); // Se limpia el buffer de salida

    scanf("%c", &c);

    printf("El caracter ingresado es: %c\n", c);

    return 0;
}
