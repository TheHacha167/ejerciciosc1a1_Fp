/*
Lee una matriz de 3 × 3 números y calcula la suma de cada una sus filas
y columnas dejando sus resultados en 2 arrays,
uno de suma de filas y otro de suma de columnas.

1  2  3 -->6
4  5  6 -->15
7  8  9 -->24
|  |  |
|  |  |
12 15  18
t1= filas
t2= columnas
*/

#include <stdio.h>

const int t1 = 3;
const int t2 = 3;
int x = 0, y = 0;
int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int matriz1_suma_filas[3];
int matriz1_suma_columnas[3];
/**
 * @brief 
 * 
 * @param matriz 
 * @param tamanio1 
 * @param tamanio2 
 */
void matriz(int matriz[x][y], int tamanio1, int tamanio2)
{

   printf("Vamos a proceder a leer los datos para una matriz:  \n");
   printf("Esta matriz tiene un tamanio de %i x %i\n", tamanio1, tamanio2);
   for (size_t i = 0; i < tamanio1; ++i)
   {
      for (size_t j = 0; j < tamanio2; ++j)
      {
         printf("introduce el valor correspondiente a la posicion de la matriz: %i x %i\n", i, j);
         scanf("%i", &matriz[i][j]);
      }
   }
}
/**
 * @brief 
 * 
 * @param matriz 
 * @param tamanio1 
 * @param tamanio2 
 * @param matriz2 
 */
void suma_matriz_columnas(int matriz[x][y], int tamanio1, int tamanio2, int matriz2[])
{
   int n1 = 0;
   x = tamanio1;
   y = tamanio2;
   for (int i = 0; i < x; ++i)
   {
      for (int j = 0; j < y; ++j)
      {
         n1 = n1 + matriz[i][j];
      }

      matriz2[i] = n1;
      /*
         printf("\n");
         printf("%i\n", n1);
         printf("\n");
         printf("%i\n", matriz2[i]);
      */
      n1 = 0;
   }
}
/**
 * @brief 
 * 
 * @param matriz 
 * @param tamanio1 
 * @param tamanio2 
 * @param matriz2 
 */
void suma_matriz_filas(int matriz[x][y], int tamanio1, int tamanio2, int matriz2[])
{
   int n1 = 0;
   x = tamanio1;
   y = tamanio2;
   for (int i = 0; i < x; ++i)
   {
      for (int j = 0; j < y; ++j)
      {
         n1 = n1 + matriz[j][i];
      }

      matriz2[i] = n1;
      /*
         printf("\n");
         printf("%i\n", n1);
         printf("\n");
         printf("%i\n", matriz2[i]);
      */
      n1 = 0;
   }
}
/**
 * @brief 
 * 
 * @param matriz 
 * @param tamanio1 
 * @return int 
 */
int salida_matriz_una_dimension(int matriz[x], int tamanio1)
{
   x = tamanio1;

   for (int i = 0; i < 3; ++i)
   {

      printf(" %i ", matriz[i]);
      printf("\n");
   }
   return 0;
}
/**
 * @brief 
 * 
 * @param matriz 
 * @param tamanio1 
 * @param tamanio2 
 * @return int 
 */
int salida_matriz_dos_dimension(int matriz[x][y], int tamanio1, int tamanio2)
{
   x = tamanio1;
   y = tamanio2;

   for (int i = 0; i < x; ++i)
   {
      for (int j = 0; j < y; ++j)
      {
         printf(" %i ", matriz[i][j]);
         printf("\n");
         printf("%i\n", matriz[i][j]);
        
      }
   }
   return 0;
}

int main()
{
    matriz(matriz1,t1,t2);
   salida_matriz_dos_dimension(matriz1, 3, 3);

   suma_matriz_columnas(matriz1, t1, t2, matriz1_suma_columnas);
   printf("la suma de las columnas es :    \n");
   salida_matriz_una_dimension(matriz1_suma_columnas, 3);

   printf("\n");

   suma_matriz_filas(matriz1, t1, t2, matriz1_suma_filas);
   printf("la suma de las filas es :    \n");
   salida_matriz_una_dimension(matriz1_suma_filas, 3);

   return 0;
}