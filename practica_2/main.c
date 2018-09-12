#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int contador = 0;
    int numeros[3];
    while ( contador < 3 ){
        printf("Escribe un numero: \n");
        scanf("%d", &n);
        numeros[contador] = n;
        printf("Has escrito %d\n", numeros[contador] );
        contador++;
    }


    if (numeros[1]>numeros[2]>numeros[3]){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}
