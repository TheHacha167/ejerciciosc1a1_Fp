// Implementa un programa que lea dos números enteros cualesquiera y muestre los números comprendidos entre ambos, sin incluirlos a ellos mismos.

#include <stdio.h>
int n1 = 0, n2 = 0;

int main()
{
   printf("Da el primer numero\n");
   scanf("%i", &n1);
   printf("Da el segundo numero\n");
   scanf("%i", &n2);

   for (int i = 1; i <= (n2 - 1); i++)
   {
      printf("%i\n", n1 + i);
   }

   return 0;
}