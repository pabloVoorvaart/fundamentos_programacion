#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *entrada;
    FILE *salida;
    char car;
    char bcar;

    entrada= fopen("entrada.txt", "r");

    if (entrada==NULL)
    {
        printf ("Nose puede acceder");
    }
    else
    {
        salida = fopen ("salida.txt", "w");
        fscanf(entrada, "%c", &car);
        while(!feof(entrada))
        {
            bcar = car;
            //Debug printf("Before: %c\n", bcar);
            fscanf(entrada, "%c", &car);
            //Debug printf("Actual: %c\n", car);
            if(bcar==' ' && car==' ')
            {
                printf("skip\n");
            }
            else
            {
                fprintf(salida, "%c", bcar);
            }
        }
    }
    return 0;
}
