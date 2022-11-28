// Implementa un programa que lea un número positivo por teclado e informe de si el número es par o impar.

#include <stdio.h>
int n1 = 0, n2 = 0;
int main()
{

   printf("Da un numero para evaluar si es par \n");
   scanf("%i", &n1);

   n2 = n1 % 2;

   if (n2 = 0)
   {
      printf("El numero introducido es par \n");
   }
   else
   {
      printf("El numero introducido no es par \n");
   }

   return 0;
}