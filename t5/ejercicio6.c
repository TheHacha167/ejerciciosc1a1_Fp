/*
Implementar un programa en C que lea dos números enteros cualesquiera
y llame a una función que muestre los números comprendidos entre ambos,
sin incluirlos a ellos mismos.

*/
#include <stdio.h>
int n1 = 0, n2 = 0;
void numeros()
{

   printf("introduce el primer numero \n");
   scanf("%i", &n1);
   printf("introduce el segundo numero \n");
   scanf("%i", &n2);
}
int salida(int numero1, int numero2)
{

   return (numero1 + numero2);
}
int main()
{
   numeros();
   for (int i = 1; i <= (n2 - 1); i++)
   {
      printf("%i\n", salida(n1, i));
   }

   return 0;
}