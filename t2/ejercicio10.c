//Implementa un programa que lea N números mayores que cero e imprima la media, el valor máximo y el mínimo.

#include <stdio.h>

int main() {
    int n, num, max, min, sum;
    float prom;

    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d", &n);

    // Se lee el primer numero para inicializar max y min
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    max = num;
    min = num;
    sum = num;

    // Se leen los siguientes n-1 numeros
    for(int i = 1; i < n; i++) {
        printf("Ingrese otro numero: ");
        scanf("%d", &num);

        if(num > max) {
            max = num;
        }

        if(num < min) {
            min = num;
        }

        sum += num;
    }

    // Se calcula la media
    prom = (float) sum / n;

    // Se imprimen los resultados
    printf("La media es: %.2f\n", prom);
    printf("El valor maximo es: %d\n", max);
    printf("El valor minimo es: %d\n", min);

    return 0;
}
