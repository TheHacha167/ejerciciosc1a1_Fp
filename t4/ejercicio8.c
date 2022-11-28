/*
    Implementa un programa que muestre por pantalla todos los números comprendidos entre 1 y 100 que son múltiplos de 7 o de 13.

*/
#include <stdio.h>

int main()
{
    for (size_t i = 0; i < 100; i++)
    {

        if (i % 7 == 0)
        {
            printf("Multiplo de 7     %i\n", i);
        }
        else
        {

            if (i % 13 == 0)
            {
                printf("Multiplo de 13    %i\n", i);
            }
        }
    }

    return 0;
}