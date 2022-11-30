/*
Implementar un programa llame a una función que genere números enteros de 2 en 2
 comenzando por el 2 hasta el valor máximo menor que 30 y sume los divisibles por 2.

*/
#include <stdio.h>
int n1 = 0, n2 = 0;
int suma_de_dos(int numero1)
{
   numero1 = numero1 + 2;

   n1 = numero1;

   return (numero1);
}
void es_divisible(int numero1)
{

   if (numero1 % 2 == 0)
   {
      n2 = n2 + numero1;
   }
}

int main()
{
   for (int i = 0; i < 15; i++)
   {

      printf("%i\n", suma_de_dos(n1));

      es_divisible(n1);
   }
   printf("......................\n");
   printf(" La suma de todos los numeros anteriores divisibles por dos es : %i \n", n2);
   return 0;
}