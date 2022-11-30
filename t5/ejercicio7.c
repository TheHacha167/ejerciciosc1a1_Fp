/*
Implementar un programa que llame a una función que muestre
la tabla de multiplicar de un número entero.

*/
#include <stdio.h>
int n1 = 0;
int salida(int numero1, int numero2)
{

   return (numero1 * numero2);
}
int main()
{
   printf("introduce el numero del que obtener la tabla\n");
   scanf("%i", &n1);
   for (int i = 0; i < 11; i++)
   {
      printf("%i\n", salida(n1, i));
   }

   return 0;
}