#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 1;
    while( n < 11 ) {
        printf("Tabla del %d\n", n);
        int x = 1;
        while ( x < 11){
            printf("%d * %d = %d\n",n,x, x*n);
            x++;
            if ( x = 10){
                printf("\n");
            }
        }
        n++;
    }
    return 0;
}
