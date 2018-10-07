#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *entrada;
    FILE *mayusculas;
    char car;
    entrada= fopen("entrada.txt", "r");

    if (entrada==NULL)
    {
        printf ("No se puede acceder\n");
    }
    else
    {
        mayusculas = fopen ("mayusculas.txt", "w");

        fscanf(entrada, "%c", &car);
        while(!feof(entrada))
        {
            //convertir a mayusc
            if (car >= 'a' && car <= 'z') car = 'A'+car-'a';
            //escribe en entrada mayusculas + printear mayuscula
            printf("%c", car);
            fprintf(mayusculas, "%c", car);
            //vuelve a escanear el entrada
            fscanf(entrada, "%c", &car);
        }

        fclose(entrada);
        fclose(mayusculas);
    }
    return 0;
}
