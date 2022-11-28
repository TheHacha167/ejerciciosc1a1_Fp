// Implementa un programa que genere números enteros de 3 en 3 comenzando por el 2 hasta el valor máximo menor que 30.

#include <stdio.h>
int n1 = 2;

int main()
{
   for (int i = 0; i < 9; i++)
   {
      n1 = n1 + 3;
      printf("%i\n", n1);
   }

   return 0;
}