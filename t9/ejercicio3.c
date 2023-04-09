/*
  Implementa un programa que incluya una función recursiva que resuelva la raíz cuadrada.

*/
#include <stdio.h>
#include <math.h>

double raiz_cuadrada(double num, double tolerancia, double aproximacion) {
    double diferencia = fabs(aproximacion * aproximacion - num);

    if(diferencia <= tolerancia) { // Caso base
        return aproximacion;
    } else { // Caso recursivo
        double nueva_aproximacion = (aproximacion + num / aproximacion) / 2.0;
        return raiz_cuadrada(num, tolerancia, nueva_aproximacion);
    }
}

int main() {
    double num, tolerancia, resultado;

    printf("Introduce un número: ");
    scanf("%lf", &num);

    printf("Introduce la tolerancia: ");
    scanf("%lf", &tolerancia);

    resultado = raiz_cuadrada(num, tolerancia, 1.0);

    printf("La raíz cuadrada de %lf es %lf\n", num, resultado);

    return 0;
}
