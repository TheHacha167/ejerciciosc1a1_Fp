/*
Enunciado del Ejercicio:

Escriba un programa en C que ordene un array de números enteros en orden ascendente utilizando el algoritmo de ordenamiento por burbuja.
El array debe ser llenado por el usuario.

Sugerencia: El algoritmo de ordenamiento por burbuja compara cada número en el array con el siguiente, intercambiándolos si están en el orden incorrecto.

Nota: Asegúrese de manejar correctamente los límites del array para evitar errores de acceso fuera de límites.
*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n-1; i++) {     
       for (j = 0; j < n-i-1; j++) { 
           if (arr[j] > arr[j+1]) {
              temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
       }
   }
}

int main() {
    int arr[100], i, n;
    
    printf("Ingrese la cantidad de elementos (1 a 100): ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
       printf("Ingrese el número %d: ", i+1);
       scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("Array en orden ascendente: ");
    for(i = 0; i < n; i++)
       printf("%d ", arr[i]);
    
    return 0;
}
