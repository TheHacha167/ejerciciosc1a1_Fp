/*
    Implementa un programa que muestre la tabla de multiplicar de un número entero.

*/
#include <stdio.h>
int n1 = 0;

int main()
{
    printf("Da  primer numero a obtener la tabla\n");
    scanf("%i", &n1);

    for (int i = 0; i < 11; i++)
    {
        printf("%i\n", n1 * i);
    }

    return 0;
}