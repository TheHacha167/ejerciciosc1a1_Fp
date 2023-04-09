/*
  Implementa un programa en C que incluya una función recursiva que solucione el problema de las torres de Hanoi.

*/
#include <stdio.h>

void hanoi(int n, char torre_origen, char torre_destino, char torre_auxiliar) {
    if(n == 1) { // Caso base
        printf("Mover disco 1 de la torre %c a la torre %c\n", torre_origen, torre_destino);
        return;
    }

    hanoi(n - 1, torre_origen, torre_auxiliar, torre_destino);
    printf("Mover disco %d de la torre %c a la torre %c\n", n, torre_origen, torre_destino);
    hanoi(n - 1, torre_auxiliar, torre_destino, torre_origen);
}

int main() {
    int n;

    printf("Introduce el número de discos: ");
    scanf("%d", &n);

    if(n < 1) {
        printf("El número de discos debe ser mayor o igual a 1\n");
    } else {
        hanoi(n, 'A', 'C', 'B');
    }

    return 0;
}
