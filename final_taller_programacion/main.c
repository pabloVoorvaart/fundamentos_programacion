//librerias
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define N  5
#define M  30


//funciones
int cargar_config(float config_values[N][M], int *numero_capas_pointer, int *numero_entradas_pointer);
int escribir_config(float config_values[N][M], int numero_capas, int numero_entradas);

int main()
{
    // variables main
    int numero_entradas;
    int numero_capas;
    float config_values[N][M];

    //cargar configuracion y generar matriz
    if(cargar_config(config_values, &numero_capas, &numero_entradas))
        return 0;
    escribir_config(config_values, numero_capas, numero_entradas);

    return 0;
}

int escribir_config(float config_values[N][M], int numero_capas, int numero_entradas)
{
    int i, x, y, z, j=0;
    int long_matriz, vector_umbral, skip;

    printf("Cargado del Precepton\n");
    printf("=====================\n");
    printf("Numero de capas: %d\n", numero_capas);
    printf("Numero de entradas: %d\n", numero_entradas);
    for(i=0; i<numero_capas; i++)
    {
        long_matriz=config_values[i][j]*numero_entradas;//numero neuronas * numero de entradas
        vector_umbral=numero_entradas;
        skip=long_matriz+vector_umbral+1;
        printf("Cargando capa %d:\n", i);
        printf("  Numero de entradas: %d\n", numero_entradas);
        y=0; z=0;
        for(j=0; j<skip; j++)
        {
            if(j==0){x=config_values[i][j]; printf("  Numero de neuronas: %d\n", x);}
            if(j>0&&j<long_matriz+1){
              printf("w[%d][%d]=%f\n", z, y, config_values[i][j]);
              if(j==long_matriz/j){ z++; y=0;}
              else{y++;}
            }
        }
        j=0;
        printf("\n");
    }
};


int cargar_config(float config_values[N][M], int *numero_capas_pointer, int *numero_entradas_pointer)
{
    //declarar variables funcion
    FILE *configuracion;
    float value; //centinela
    int contador_valores=0;//mantiene una cuenta de todos los valores de entrada
    int i=-1, j=0, skip=2, pos_capa=2;

    configuracion=fopen("configuracion.txt", "r");
    if (configuracion==NULL)
    {
        printf("Config not found");
        return 1;
    }
    else
    {
        fscanf(configuracion, "%f", &value);
        while(!feof(configuracion))
        {
            //La posicion 0 del fichero siempre va a ser el numero de capas
            //lo asigno a una variable por ahora, no lo quiero en la matriz.
            if(contador_valores==0) *numero_capas_pointer=value;
            //La posicion 1 del fichero siempre va a ser el numero de entradas.
            if(contador_valores==1) *numero_entradas_pointer=value;
            //Guardar todos los valores en una matriz.
            if(contador_valores==skip)
            {
                pos_capa=contador_valores;
                i++; j=0; config_values[i][j]=value;
                skip=(value**numero_entradas_pointer)+ *numero_entradas_pointer + skip +1;
                //printf("skip is %d\n", skip);
                //printf("Array[%d][%d]: %f at pos %d\n", i, j, config_values[i][j], contador_valores);
            }
            if(contador_valores>pos_capa&&contador_valores<skip)
            {
              j++; config_values[i][j]=value;
              //printf("Array[%d][%d]: %f at pos %d\n", i, j, config_values[i][j], contador_valores);
            }
            contador_valores++;
            fscanf(configuracion, "%f", &value);
        }
        return 0;
    }
}
