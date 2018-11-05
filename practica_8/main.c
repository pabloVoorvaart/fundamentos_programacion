#include <stdio.h>
#include <stdlib.h>
const int N = 8;
void leer(float v[]);
void escribir(float v[]);
void sumar(float v1[], float v2[], float suma[]);
float multiplicar(float v1[], float v2[]);
void restar(float v1[], float v2[], float resto[]);


void main()
{
    float v[N], w[N], r[N];
    int option;
    int quit = 0;
    while(quit != 1)
    {
        printf("Choose 1 for sum of arrays, 2 for multiplication, 3 for substraction or 0 to exit:\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("Define array 1.\n");
            leer(v);
            printf("Define array 2.\n");
            leer(w);
            sumar(v,w,r);
            printf("El resultado es: ");
            escribir(r);
            break;
        case 2:
            printf("Define array 1.\n");
            leer(v);
            printf("Define array 2.\n");
            leer(w);
            printf("El resultado es: %f\n", multiplicar(v,w));
            break;
        case 3:
            printf("Define array 1.\n");
            leer(v);
            printf("Define array 2.\n");
            leer(w);
            restar(v,w,r);
            printf("El resultado es: ");
            escribir(r);
            break;
        case 0:
            printf("\n-----END------\n");
            quit=1;
        default:
            printf("\nopcion incorrecta\n");
        }
    }
}

void sumar(float v1[], float v2[], float suma[])
{

    int i;
    for (i=0; i<N; i++)
    {
        suma[i] = v1[i] + v2[i];
    }
}

float multiplicar(float v1[], float v2[])
{

    int i;
    float multiplo;
    for (i=0; i<N; i++)
    {
        multiplo += v1[i] * v2[i];
    }
    return multiplo;
}


void restar(float v1[], float v2[], float resto[])
{

    int i;
    for (i=0; i<N; i++)
    {
        resto[i] = v1[i] - v2[i];
    }
}


void leer(float v[])
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("v[%d]: ",i);
        scanf("%f",&v[i]);
        if (i == N-1)
        {
            printf("\n\n");
        }

    }
}

void escribir(float v[])
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("%f", v[i]);
        if (i != N-1)
        {
            printf(",");
        }
        else
        {
            printf("\n\n");
        }
    }
}
