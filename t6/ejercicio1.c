/*
Implementa un programa que introduzca los valores de un array mediante un bucle solicitando los datos por teclado.

*/
#include <stdio.h>
int n1 = 0;
int valores[];
int main()
{
   printf("introduzca el numero de datos que desea introducir\n");
   scanf("%i", &n1);
   for (size_t i = 0; i < n1; ++i)
   {
      printf("introduzca el %i valor a almacenar :\n", i);
      scanf("%i", &valores[i]);
   }
   printf("los valores introducidos corresponden a :\n");
   for (size_t i = 0; i < n1; ++i)
   {
      printf("%i\n", valores[i]);
   }
   return 0;
}