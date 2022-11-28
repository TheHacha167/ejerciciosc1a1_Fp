// Implementa un programa que averigüe si un número N es primo.
#include <stdio.h>
#include <stdbool.h>
bool primo = true;
int n1 = 0;
int main()
{

   printf("Introduce el numero a comprobar \n");
   scanf("%i", &n1);
   if (n1 == 0 || n1 == 1 || n1 == 4)
   {
      return 0;
   }
   for (int x = 2; x < n1 / 2; ++x)
   {
      if (n1 % x == 0)
      {
         primo = false;
      }
   }
   if (primo == 1)
   {
      printf("Es primo");
   }
   else
   {
      printf("No es primo");
   }
   return 0;
}
