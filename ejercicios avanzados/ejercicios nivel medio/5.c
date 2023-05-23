/*
Enunciado del Ejercicio:

Escriba un programa en C que reciba una cadena de texto ingresada por el usuario y cuente el número de vocales y consonantes en la cadena.

Sugerencia: Puede utilizar la función tolower() para convertir la cadena a minúsculas y simplificar las comprobaciones. Recuerde que las vocales son 'a', 'e', 'i', 'o' y 'u', y las consonantes son las demás letras del alfabeto.

Nota: Para simplificar el problema, puede suponer que la cadena de texto no tiene espacios ni signos de puntuación.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, vowels = 0, consonants = 0;

    printf("Ingrese una cadena: ");
    fgets(str, sizeof str, stdin); 

    for(i = 0; str[i]!='\0'; ++i) {
        char ch = tolower(str[i]);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
            ++vowels;
        }
        else if((ch>='a' && ch<='z')) {
            ++consonants;
        }
    }

    printf("Vocales: %d\n", vowels);
    printf("Consonantes: %d", consonants);

    return 0;
}
