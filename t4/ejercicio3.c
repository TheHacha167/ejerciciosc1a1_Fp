/*
    Implementa un programa que lea dos números enteros y escribir el mayor o un mensaje si son iguales.

*/
#include <stdio.h>
int n1 = 0, n2 = 0;

int main()
{
    printf("Da  primer numero a comparar\n");
    scanf("%i", &n1);

    printf("Da  primer numero a comparar\n");
    scanf("%i", &n2);
    if (n1 > n2)
    {
        printf("El primer numero es mayor %i\n", n1);
    }
    else
    {
        if (n2 > n1)
        {
            printf("El segundo numero es mayor %i\n", n2);
        }
        else
        {
            printf("Son iguales los numeros \n");
        }
    }
}
