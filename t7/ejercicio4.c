/*
  Implementa un programa que muestre el uso de punteros a cadenas de caracteres.

*/
#include <stdio.h>

int main() {
    char *puntero_cadena;
    char cadena[] = "Hola mundo!";

    // Se asigna el puntero a la primera posición de la cadena
    puntero_cadena = cadena;

    printf("El valor de la cadena es: %s\n", cadena);
    printf("El valor del puntero es: %p\n", puntero_cadena);
    printf("El primer caracter de la cadena es: %c\n", *puntero_cadena);

    // Se utiliza la aritmética de punteros para acceder a los caracteres de la cadena
    puntero_cadena += 4;

    printf("El quinto caracter de la cadena es: %c\n", *puntero_cadena);

    return 0;
}
