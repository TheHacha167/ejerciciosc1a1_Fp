/*
Implementa un programa en C que compare 2 cadenas y dé como resultado si son iguales, o mayor o menor una que la otra.

*/
#include <stdio.h>
#include <string.h>

int main(void) {
  // Declara dos cadenas de texto
  char str1[] = "hola";
  char str2[] = "hola";

  // Compara las dos cadenas usando la función strcmp()
  int resultado = strcmp(str1, str2);

  if (resultado == 0) {
    printf("Las cadenas son iguales.\n");
  } else if (resultado > 0) {
    printf("La cadena 1 es mayor que la cadena 2.\n");
  } else {
    printf("La cadena 1 es menor que la cadena 2.\n");
  }

  return 0;
}
