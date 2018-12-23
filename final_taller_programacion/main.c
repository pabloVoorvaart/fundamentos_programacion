//librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define C 4 //numero maximo de capas(5) -1.
#define P 4 //numero maximo de neuronas(5) -1.
#define N 4 //numero maximo de entradas(5) -1.

//definition of structs
struct capa{
  int neuronas; //p es el numero de neuronas de cada capa. Max is 5.
  float matriz_pesos[N][P]; //matriz de pesos w=n-1*p-1. Max is 25 values, max pos is [4][4]
  float vector_umbral[N]; //vector umbral O=p-1. Max is 5, max pos is [4]
};
struct perceptron{
	int capas;
  int entradas; //n es el numero de entradas. Max is 5.
	struct capa datos[C]; // vector datos
};

//prototipos funciones
void cargar_config(struct perceptron *perceptron, FILE *config);
void procesar_entradas(struct perceptron perceptron, float entradas[N]);
float f(float x);

int main()
{
  struct perceptron perceptron;
  FILE *config;
  FILE *entrada;
  float entradas[N], centinela;
  int cont=0;

  //load config file
  config = fopen("configuracion.txt", "r");
  entrada = fopen("entradas.txt", "r");
  if(config==NULL||entrada==NULL)
    return 1;
  cargar_config(&perceptron, config);

  printf("\n\n\nEjecucion del perceptron\n========================\n");
  fscanf(entrada, "%f", &centinela);
  while(!feof(entrada))
  {
    entradas[cont]=centinela;
    if(cont==perceptron.entradas-1)
    {
      procesar_entradas(perceptron, entradas);
      cont=-1;
    }
    cont++;
    fscanf(entrada, "%f", &centinela);
  }
  return 0;
}

void procesar_entradas(struct perceptron perceptron, float entradas[N])
{
  float vector_salida[P]; //Una salida por cada neurona de la capa.(p-1). Max is 4.
  int i, j, k;

  printf("Entrada: (%f,", entradas[0]);
  for(i=1;i<perceptron.entradas-1;i++)
    printf(" %f,", entradas[i]);
  printf(" %f) ---->  ", entradas[perceptron.entradas-1]);

  for(k=0;k<perceptron.capas;k++)
  {
    for(i=0;i<P;i++)
      vector_salida[i]=0.0; //reset|init vector_salida

    for(i=0;i<perceptron.datos[k].neuronas;i++)
      for(j=0;j<perceptron.entradas;j++)
        vector_salida[i]+=entradas[j]*perceptron.datos[k].matriz_pesos[j][i];

    for(i=0;i<perceptron.datos[k].neuronas;i++)
      vector_salida[i]-=perceptron.datos[k].vector_umbral[i];

    for(i=0;i<perceptron.datos[k].neuronas;i++)
      vector_salida[i]=f(vector_salida[i]);

    for(i=0;i<P;i++)
      entradas[i]=vector_salida[i];
  }

  printf("Salida: (");
  for(i=0;i<perceptron.datos[perceptron.capas-1].neuronas;i++)
  {
    printf("%f", vector_salida[i]);
  }
  printf(")\n");
}

float f(float x)
{
  float power, i;
  i = (-20)*x;
  power = exp(i);
  return (1/(1+power));
}

void cargar_config(struct perceptron *perceptron, FILE *config)
{
  float value; int contador_valores=0, comienzo_capa=2, current=2, i=-1;
  int a,b,c;

  printf("\nCarga del Preceton\n==================\n");

  fscanf(config, "%f", &value);
  while(!feof(config))
  {
    //La posicion 0 del fichero siempre va a ser el numero de capas
    if(contador_valores==0)
    {
      perceptron->capas=value;
      printf("Numero de capas: %d\n", perceptron->capas);
    }
    //La posicion 1 del fichero siempre va a ser el numero de entradas.
    if(contador_valores==1)
    {
      perceptron->entradas=value;
      printf("Numero de entradas: %d\n", perceptron->entradas);
    }
    //la primera capa empieza en la posicion 2.
    if(contador_valores==comienzo_capa)
    {
        i++;
        perceptron->datos[i].neuronas = value;
        printf("\nCargando capa %d:\n", i+1);
        printf("  Numero de neuronas: %d\n", perceptron->datos[i].neuronas);
        printf("  Numero de entradas: %d\n", perceptron->entradas);

        current = comienzo_capa;
        comienzo_capa=(value*perceptron->capas)+ perceptron->entradas + contador_valores + 1;
        a=0; b=0; c=0;
    }
    if(contador_valores>current&&contador_valores<comienzo_capa)
        //logica para acceder matriz de pesos
        if(contador_valores-current<=perceptron->datos[i].neuronas*perceptron->entradas)
          if(contador_valores-current==perceptron->datos[i].neuronas)
          {
            perceptron->datos[i].matriz_pesos[a][b]=value;
            printf("w[%d][%d]=%f\n", a, b , perceptron->datos[i].matriz_pesos[a][b]);
            a++; b=0;
          }
          else
          {
            perceptron->datos[i].matriz_pesos[a][b]=value;
            printf("w[%d][%d]=%f\n", a, b , perceptron->datos[i].matriz_pesos[a][b]);
            b++;
          }
        //accedo a vector umbral
        else
        {
          perceptron->datos[i].vector_umbral[c]=value;
          printf("Umbral[%d] = %f\n", c, perceptron->datos[i].vector_umbral[c]);
          c++;
        }
    contador_valores++;
    fscanf(config, "%f", &value);
  }
}

