/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente la función de la transformada rápida de Fourier (FFT).

Sugerencia: La FFT es un algoritmo que calcula la transformada discreta de Fourier (DFT) de una secuencia, o su inversa. Las aplicaciones de la FFT incluyen la resolución de ecuaciones diferenciales parciales, el análisis espectral y el procesamiento de imágenes y señales.
*/

#define _USE_MATH_DEFINES
#include <math.h>
#include <complex.h>
#include <tgmath.h>
#include <stdio.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#define SIZE 4

void fft(complex double* a, int n) {
    if (n == 1)
        return;
    
    complex double a0[n/2];
    complex double a1[n/2];

    for (int i = 0; i < n/2; i++) {
        a0[i] = a[i*2];
        a1[i] = a[i*2 + 1];
    }

    fft(a0, n/2);
    fft(a1, n/2);

    for (int i = 0; i < n/2; i++) {
        complex double t = cexp(-2.0*I*M_PI*i/n)*a1[i];
        a[i] = a0[i] + t;
        a[i + n/2] = a0[i] - t;
    }
}

int main() {
    complex double a[SIZE] = {1, 2, 3, 4};
    fft(a, SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("%2.2lf + %2.2lfi\n", creal(a[i]), cimag(a[i]));
    }
    return 0;
}
