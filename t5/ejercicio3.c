/*
Implementa un programa con una función menú que elija sumar o multiplicar dos números que se ingresan por teclado.

*/
#include <stdio.h>
int n1 = 0, n2 = 0, n3 = 0;
int menu(int seleccion)
{
   if (seleccion == 1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int main()
{
   printf("introduce el primer numero \n");
   scanf("%i", &n1);
   printf("introduce el segundo numero \n");
   scanf("%i", &n2);
   printf("introduce el tipo de operacion\n");
   printf("..............................\n");
   printf("1 --> sumar......2 --> multiplicar\n");
   scanf("%i", &n3);
   if (menu(n3) == 1)
   {
      printf("el resultado de su suma es : %i \n", n1 + n2);
   }
   if (menu(n3) == 0)
   {
      printf("el resultado de su multiplicacion es : %i \n", n1 * n2);
   }

   return 0;
}