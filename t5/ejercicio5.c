/*
Implementar un programa que lea dos números enteros y se los pase a una función
que escriba por pantalla cual es el mayor o un mensaje si son iguales.

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
int comparacion(int numero1, int numero2)
{
   if (numero1 > numero2)
   {
      return 1;
   }
   else
   {
      if (numero2 > numero1)
      {
         return 2;
      }
      else
      {
         return 0;
      }
   }
}
int main()
{
   numeros();
   if (comparacion(n1, n2) == 1)
   {
      printf("el numero mayor es : %i \n", n1);
   }
   if (comparacion(n1, n2) == 2)
   {
      printf("el numero mayor es : %i \n", n2);
   }
   if (comparacion(n1, n2) == 0)
   {
      printf("Los dos numeros son iguales : %i = %i\n", n1, n2);
   }

   return 0;
}