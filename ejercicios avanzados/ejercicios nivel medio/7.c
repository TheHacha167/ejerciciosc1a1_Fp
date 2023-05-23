/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba una cadena de texto ingresada por el usuario y luego la invierta.

Sugerencia: Puede utilizar funciones de manejo de strings en C como strlen() y un bucle for para invertir la cadena.

Nota: Asegúrese de manejar correctamente los límites del array para evitar errores de acceso fuera de límites.
*/

#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int i, length;
    char temp;

    length = strlen(str);

    for(i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[100];

    printf("Ingrese una cadena: ");
    fgets(str, sizeof str, stdin); 
    str[strlen(str) - 1] = '\0';  // Eliminar el carácter de nueva línea

    reverse(str);

    printf("Cadena invertida: %s", str);

    return 0;
}
