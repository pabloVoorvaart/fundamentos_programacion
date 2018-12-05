//librerias
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define N  5
#define M  30
#define P  2

//funciones
int cargar_config(float config_values[N][M], int *numero_capas_pointer, int *numero_entradas_pointer);
int escribir_config(float config_values[N][M], int numero_capas, int numero_entradas);
int calculo_perceptron(float config_values[N][M], int numero_capas, int numero_entradas, float entrada[P]);

int main()
{
    // variables main
    int numero_entradas;
    int numero_capas;
    float entrada[P] = {1.000, 1.000};
    float config_values[N][M];

    //cargar configuracion y generar matriz
    if(cargar_config(config_values, &numero_capas, &numero_entradas))
        return 0;
    escribir_config(config_values, numero_capas, numero_entradas);
    calculo_perceptron(config_values, numero_capas, numero_entradas, entrada);

    return 0;
}

int calculo_perceptron(float config_values[N][M], int numero_capas, int numero_entradas, float entrada[P])
{
    printf("\n");
    int long_matriz, i, j, x=0, z=0, long_vector_salida, vector_umbral, skip;
    float vector_salida[20];

    for(i=0; i<numero_capas; i++)
    {
        long_matriz=config_values[i][j]*numero_entradas;//numero neuronas * numero de entradas
        vector_umbral=config_values[i][j];//numero neuronas
        skip=long_matriz+vector_umbral+1;
        long_vector_salida=long_matriz/P;

        printf("long_vector_salida = %d\n", long_vector_salida);
        for(j=0; j<skip; j++)
        {
            if(j>0&&j<=long_matriz)
            {
                vector_salida[x]+=(entrada[z]*config_values[i][j]);
                z++;
                printf("vector_salida[%d] = %f*%f = %f\n", x , entrada[z], config_values[i][j], vector_salida[x]);
                if(j==config_values[i][0]){x++; z=0;}
            }
        }
        j=0;x=0;vector_salida[0]=0; vector_salida[1]=0;
    }   
    // for(i=0; i<long_vector_salida; i++)
    // {
    //     printf("vector_salida[%d] = %f\n", i , vector_salida[i]);
    // }

}


int escribir_config(float config_values[N][M], int numero_capas, int numero_entradas)
{
    int i, v, x, y, z, j=0;
    int long_matriz, vector_umbral, skip;

    printf("Cargado del Precepton\n");
    printf("=====================\n");
    printf("Numero de capas: %d\n", numero_capas);
    printf("Numero de entradas: %d\n", numero_entradas);
    for(i=0; i<numero_capas; i++)
    {
        long_matriz=config_values[i][j]*numero_entradas;//numero neuronas * numero de entradas
        vector_umbral=config_values[i][j];//numero neuronas
        skip=long_matriz+vector_umbral+1;
        printf("\nCargando capa %d:\n", i);
        printf("  Numero de entradas: %d\n", numero_entradas);
        y=0; z=0; v=0;
        for(j=0; j<skip; j++)
        {
            if(j==0){x=config_values[i][j]; printf("  Numero de neuronas: %d\n", x);}
            if(j>0&&j<=long_matriz)
            {
              printf("w[%d][%d]= %f\n", z, y, config_values[i][j]);
              if(j==config_values[i][0]){ z++; y=0;}
              else{y++;}
            }
            if(j>long_matriz)
            {
              printf("Umbral[%d]= %f\n", v, config_values[i][j]);
              v++;
            }
        }
        j=0;
    }
};


int cargar_config(float config_values[N][M], int *numero_capas_pointer, int *numero_entradas_pointer)
{
    //declarar variables funcion
    FILE *configuracion;
    float value; //centinela
    int contador_valores=0;//mantiene una cuenta de todos los valores de entrada
    int i=-1, j=0, init_capa=2, skip=0;

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
            if(contador_valores==init_capa)
            {
                i++; j=0; config_values[i][j]=value;
                skip=(value**numero_entradas_pointer)+ value +1;
                init_capa = init_capa+skip;
                // printf("skip is %d\n", skip);
                // printf("init_capa is  %d\n", init_capa);
                // printf("Array[%d][%d]: %f at pos %d\n", i, j, config_values[i][j], contador_valores);
            }
            else
            {
              if(contador_valores==0) *numero_capas_pointer=value;
              if(contador_valores==1) *numero_entradas_pointer=value;
              if(contador_valores!=0&&contador_valores!=1)
              {
              j++; config_values[i][j]=value;
              //printf("Array[%d][%d]: %f at pos %d\n", i, j, config_values[i][j], contador_valores);
              }
            }
            contador_valores++;
            fscanf(configuracion, "%f", &value);
        }
        return 0;
    }
}
