/*
    Implementa un programa que realice las operaciones de suma, resta, división y multiplicación de dos números.

*/
#include <stdio.h>
int main()
{
    int n1, n2, n3, res;
    printf("Introduce el primer numero ");
    scanf("%i", &n1);
    printf("Introduce el segundo numero: ");
    scanf("%i", &n2);
    printf("Introduce operacion suma(1), resta(2), producto(3), division(4): \n");
    scanf("%i", &n3);
    if (n3 == 1)
    {
        res = n1 + n2;
        printf("%i + %i = %i", n1, n2, res);
    }
    else if (n3 == 2)
    {
        res = n1 - n2;
        printf("%i - %i = %i\n", n1, n2, res);
    }
    else if (n3 == 3)
    {
        res = n1 * n2;
        printf("%i * %i = %d\n", n1, n2, res);
    }
    else if (n3 == 4)
    {
        res = n1 / n2;
        printf("n3 / %i = %i\n", n1, n2, res);
    }
    return 0;
}