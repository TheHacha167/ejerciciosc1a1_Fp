/*
Enunciado del Ejercicio:

Escriba un programa en C que verifique si una cadena de texto ingresada por el usuario es un palíndromo. 
Un palíndromo es una palabra, frase, número u otro tipo de secuencia de unidades que se lee igual de adelante hacia atrás que de atrás hacia adelante.

Sugerencia: Utilice funciones de manejo de strings en C como strlen() y un bucle for para comprobar si la cadena es un palíndromo.

Nota: Para simplificar el problema, puede suponer que la cadena de texto no tiene espacios ni signos de puntuación, y está en minúsculas.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, length;
    int flag = 0;

    printf("Ingrese una cadena: ");
    fgets(str, sizeof str, stdin); 

    length = strlen(str) - 1;  // No contar el carácter de nueva línea

    for(i=0;i < length;i++){
        if(str[i] != str[length-i-1]){
            flag = 1;
            break;
        }
    }
    
    if (flag) {
        printf("%s no es un palíndromo.\n", str);
    }    
    else {
        printf("%s es un palíndromo.\n", str);
    }
    return 0;
}
