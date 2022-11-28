// Implementa un programa que lea un número N y muestre la suma de los N primeros números.

#include <stdio.h>
int n1 = 0, n2 = 0;

int main()
{

   printf("Introduce el numero\n");
   scanf("%i", &n1);
   for (int i = 0; i < (n1 + 1); i++)
   {
      printf("%i\n", n2);
      n2 = n2 + 1;
   }
   return 0;
}