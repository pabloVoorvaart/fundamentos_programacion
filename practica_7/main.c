#include <stdio.h>

#include <stdlib.h>

//Realizar un programa en el lenguaje de programación C que lea de teclado un valor entero positivo,  y determine  si coincide el número de  cifras  iguales a 0 con el número de cifras  distintas de 0,

int main()

{

    int numero;

    int inicial;

    int cifra;

    int cont_0 = 0;

    int cont_not_0 = 0;

    scanf("%d", &numero);

    inicial=numero;

    while(numero>0)

    {

        cifra = numero % 10;

        numero = numero/10;

        if(cifra==0)

        {

            cont_0++;

        }

        else

        {

            cont_not_0 ++;

        }

    }

    if(cont_0==cont_not_0)

    {

        printf("Si coinciden las cifras iguales a 0 con las diferentes de 0 en el numero %d", inicial);

    }

    else

    {

        printf("No coinciden las cifras iguales a 0 con las diferentes de 0 en el numero %d", inicial);

    }

    return 0;

}
