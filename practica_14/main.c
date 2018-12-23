//Programa de matrices con columnas iguales

#include<stdlib.h>   // libreria para el uso de rand()
#include <stdio.h>
#include<time.h>     // libreria para el uso de time() */

#define N 3        //definir el tamaño de las filas de la matriz
#define M 5        //definir el tamaño de las columnas de la matriz

void escribirMat (int mat[N][M]);   // escribe la matriz
void generaMat (int mat[N][M]);     // rellena la matriz con num aleatorios
void matrizMaxPos (int mat[N][M], int *max, int *fil, int *col);
//devuelve el valor mayor de mat y la fila y columna en la que se encuentra
// añadir el resto de las funciones:
int matrizColCompar (int mat[N][M]);
int matrizFilCompar (int mat[N][M]);

int main()
{
    int mat[N][M];
    int max, fil, col;

    generaMat(mat);
    escribirMat(mat);
    matrizMaxPos(mat, &max, &fil, &col);

    if(matrizColCompar(mat))
    {
      printf("Hay dos columnas iguales.\n\n");
    }
    else
    {
      if(matrizFilCompar(mat))
      {
        printf("Hay dos filas iguales.\n\n");
      }
      else
      {
        printf("No hay ni columnas ni filas iguales.\n\n");
      }
    }

    printf("El maximo es: %d\n", max);
    printf("Y la primera vez aparece en la fila %d y columna %d.\n", fil, col);

    return 0;
}

//definición de funciones:
void matrizMaxPos (int mat[N][M], int *max, int *fil, int *col)
{
  int f, c;
  *max = 0;

  for(f=0; f<N; f++)
      for(c=0; c<M; c++)
        if(mat[f][c]>*max)
        {
          *max=mat[f][c];
          *fil=f+1;
          *col=c+1;
        }
}

void generaMat (int mat[N][M])
{
    int f,c;
    srand(time(NULL));

    for(f=0; f<N; f++)
        for(c=0; c<M; c++)
            mat[f][c]=rand()%20+1;
}

void escribirMat(int mat[N][M])
{
    int f,c;
    printf("\n");

    for(f=0; f<N; f++)
    {
        for(c=0; c<M; c++)
         {
            if(mat[f][c]<10) printf(" %d  ", mat[f][c]);
            if(mat[f][c]>9) printf("%d  ", mat[f][c]);
         }
      printf("\n");
    }
    printf("\n");
}

int matrizColCompar(int mat[N][M])
{
    int f=0, c, d;
    int count=0;

    for(c=0; c<M; c++)
     {
       for(d=c+1; d<M; d++)
       {
         if(mat[f][c]==mat[f][d])
         {
           //printf("[%d][%d]==[%d][%d]\n", f,c,f,d);
           for(f=0; f<N; f++)
           {
             if(mat[f][c]==mat[f][d]) count++;
             if(mat[f][c]!=mat[f][d]) count=0;
           }
           if(count==N) return 1;
           f=0;
          }
       }
     }
     if(count!=N) return 0;
}

int matrizFilCompar (int mat[N][M])
{
  int f, c=0, d;
  int count=0;

  for(f=0; f<N; f++)
   {
     for(d=f+1; d<M; d++)
     {
       if(mat[f][c]==mat[d][c])
       {
         //printf("[%d][%d]==[%d][%d]\n", f,c,d,c);
         for(c=0; c<N; c++)
         {
           if(mat[f][c]==mat[d][c]) count++;
           if(mat[f][c]!=mat[d][c]) count=0;
         }
         if(count==N) return 1;
         c=0;
        }
     }
   }
   if(count!=N) return 0;
}
