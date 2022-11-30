/*
Implementar un programa que lea un número N y llame a una función que muestre la suma de los N primeros números.

*/
#include <stdio.h>
int n1 = 0, n2 = 0, n3 = 0;
void sumatoria(int numero1)
{

    numero1 = numero1 + 1;
    n3 = n3 + n2;
    n2 = numero1;
}
int main()
{

    printf("Introduce el numero\n");
    scanf("%i", &n1);
    for (int i = 0; i < (n1 + 1); i++)
    {
        printf("%i\n", n2);
        sumatoria(n2);
    }
    printf("........................\n");
    printf(" el resultado de la sumatoria es%i\n", n3);
    return 0;
}