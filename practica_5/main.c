#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fichero;
    FILE *mayusculas;
    char car;
    fichero= fopen("file.txt", "r");

    if (fichero==NULL)
    {
        printf ("Nose puede acceder");
    }
    else
    {
        mayusculas = fopen ("mayusculas.txt", "w");

        fscanf(fichero, "%c", &car);
        while(!feof(fichero))
        {
            //convertir a mayusc
            if (car >= 'a' && car <= 'z') car = 'A'+car-'a';
            //escribe en fichero mayusculas + printear mayuscula
            printf("%c", car);
            fprintf(mayusculas, "%c", car);
            //vuelve a escanear el fichero
            fscanf(fichero, "%c", &car);
        }

        fclose(fichero);
        fclose(mayusculas);
    }
    return 0;
}
