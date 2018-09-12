#include <stdio.h>
#include <stdlib.h>
// Ejercico dos practica 1

// Enunciado: usar printf para printerar la tabla de multiplicación del 7

// Resolucion del problema, nivel basico.
/*
int main(){
    // Definimos varaible n = 7
    int n = 7;
    // Utilizamos la funcion printf para printear un texto que indice la operacion y el resultado
    printf("Tabla del 7:\n");
    printf("%d * 1 = %d\n", n, n*1);
    printf("%d * 2 = %d\n", n, n*2);
    printf("%d * 3 = %d\n", n, n*3);
    printf("%d * 4 = %d\n", n, n*4);
    printf("%d * 5 = %d\n", n, n*5);
    printf("%d * 6 = %d\n", n, n*6);
    printf("%d * 7 = %d\n", n, n*7);
    printf("%d * 8 = %d\n", n, n*8);
    printf("%d * 9 = %d\n", n, n*9);
    printf("%d * 10 = %d\n", n, n*10);
}
*/


// Resoulcion de problema, nivel me creo superior a los demas.
/*
int main(){
    //Utilizamos un contador n+1 para hacer que se ejecute un while loop 10 veces.
    int x = 7; // Definimos x como 7, esta no varia.
    int n = 1; // Queremos empezar a multiplicar por 1. Añadiremos +1 cada vez que se acabe el loop.

    printf("Tabla del %d:\n\n", x);
    while(n < 11 ) {
        printf("%d * %d = %d\n", x, n, x*n);
        n++; //'Añada +1 a n.
    }
}
*/

// Resolucion de problema, nivel esto no es necesario pero me aburro.

int main(){
    // Utilizamos dos contadores para printear todas las tablas de multiplicar.
    int n = 1;
    while( n < 11 ) {
        printf("\nTabla del %d\n", n);
        int x = 1;
        while ( x < 11 ){
            printf("%d * %d = %d\n",n,x, x*n);
            x++;
        }
        n++;
    }
}

