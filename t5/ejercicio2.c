/*
Implementa un programa con una función resta que reste dos números que se ingresan por teclado.

*/
#include <stdio.h>

int n1 = 0, n2 = 0;

int suma(int numero1, int numero2)
{

   return (numero1 + numero2);
}

int main()
{
   printf("introduce el primer numero a sumar\n");
   scanf("%i", &n1);
   printf("introduce el segundo numero a sumar\n");
   scanf("%i", &n2);
   printf("el resultado de la suma es  %i\n", suma(n1, n2));
   return 0;
}