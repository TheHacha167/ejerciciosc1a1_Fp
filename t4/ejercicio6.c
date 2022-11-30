/*
    Implementa un programa que genere números enteros de 2 en 2 comenzando
    por el 2 hasta el valor máximo menor que 30 y sume los divisibles por 2.

*/
#include <stdio.h>
int n1 = 2, n2 = 0;

int main()
{
    for (int i = 0; i < 14; i++)
    {
        
        printf("%i\n", n1);
        n1 = n1 + 2;
        if (n1 % 2 == 0)
        {
            n2 = n2 + n1;
        }
    }
    printf("......................\n");
    printf(" La suma de todos los numeros anteriores divisibles por dos es : %i \n", n2);
    return 0;
}