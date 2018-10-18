#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1;
    f1=fopen("entrada.txt","r");
    FILE *f2;
    f2=fopen("salida.txt", "w");
    char car;
    int ant=1;
    fscanf(f1, "%c", &car);

    if (f1==NULL)
        printf("Fichero no encontrado");//funciona
    else while (!feof(f1)){

        if (car!=' ')
            fprintf(f2,"%c",car);

        else if (ant!=' ')
            fprintf(f2, "%c", car);
        ant=car;
    fscanf(f1, "%c", &car);
    }
    fclose(f1);
    fclose(f2);
return 0;
}

