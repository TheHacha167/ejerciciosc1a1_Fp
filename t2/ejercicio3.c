// Implementa un programa que lea la edad de una persona menor a 50 años e informe
// de si es un niño (0-12 años), un adolescente (12-17), un joven (18-29) o un adulto.
#include <stdio.h>
int n1 = 0;

int main()
{
   do
   {
      printf("Introduce una edad para comprobar\n");
      scanf("%i", &n1);

   } while (n1 < 0 || n1 >= 51);

   if (n1 <= 12)
   {
      printf("Es un ninio\n");
   }
   else
   {

      if (n1 > 12 && n1 <= 17)
      {
         printf("Es un adolescente\n");
      }
      else
      {

         if (n1 > 17 && n1 <= 29)
         {
            printf("Es un joven\n");
         }
         else
         {

            if (n1 > 29)
            {
               printf("Es un adulto\n");
            }
         }
      }
   }
}