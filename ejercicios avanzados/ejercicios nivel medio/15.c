/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba una cadena de texto ingresada por el usuario y cuente el número de palabras en la cadena.

Sugerencia: Puede considerar que una palabra está formada por caracteres alfabéticos y está separada por espacios o el final de la cadena.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int countWords(char str[]) {
    int count = 0;
    bool inWord = false;
    for(int i = 0; str[i] != '\0'; i++) {
        if(isspace(str[i])) {
            inWord = false;
        } else if(!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];

    printf("Ingrese una cadena: ");
    fgets(str, sizeof str, stdin); 

    printf("Número de palabras: %d", countWords(str));

    return 0;
}
