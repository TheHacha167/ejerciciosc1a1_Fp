/*
Similar al ejercicio 1, desarrollando más funciones.
Implementa un programa con una función menú que elija sumar o multiplicar,
con una fusión que solicite dos números que se ingresan por teclado y una función multiplicar
y otra sumar para operar con los dos números.

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
void numeros()
{

   printf("introduce el primer numero \n");
   scanf("%i", &n1);
   printf("introduce el segundo numero \n");
   scanf("%i", &n2);
}
int suma(int numero1, int numero2)
{

   return (numero1 + numero2);
}
int multiplicacion(int numero1, int numero2)
{

   return (numero1 * numero2);
}
int main()
{
   numeros();
   printf("introduce el tipo de operacion\n");
   printf("..............................\n");
   printf("1 --> sumar..2 --> multiplicar\n");
   scanf("%i", &n3);
   if (menu(n3) == 1)
   {
      printf("el resultado de su suma es : %i \n", suma(n1, n2));
   }
   if (menu(n3) == 0)
   {
      printf("el resultado de su multiplicacion es : %i \n", multiplicacion(n1, n2));
   }

   return 0;
}