// Implementa un programa que lea un número por teclado e informe de si el número es múltiplo de 2 o de 3 (o de ambos).

#include <stdio.h>
int n1 = 0;

int main()
{
   printf("Da un numero para evaluar si es multiplo de 2 o 3\n");
   scanf("%i", &n1);

   // n2 = n1 % 2;

   if (n1 % 2 == 0)
   {
      printf("El numero introducido multiplo de 2\n");
   }
   else
   {

      if (n1 % 3 == 0)
      {
         printf("El numero introducido multiplo de 3\n");
      }
   }

   return 0;
}