#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20
#define P 2
struct Tpunto         // punto en un plano, x abscisas, y ordenadas
{
    float x;
    float y;
};

struct Tcirculo        //Circulo: longitud del radio y punto central
{
    float radio;
    struct Tpunto centro;
};

struct TlistaPuntos         //Lista de puntos del plano
{
    int tam;                 //cantidad de valores en el vector puntos
    struct  Tpunto puntos[N];
};

struct TlistaCirculos       //Lista de circulos
{
    int tam;                 //cantidad de valores en el vector circulos
    struct  Tcirculo circulos[N];
};

int leerPuntos (struct TlistaPuntos *lista);
int puntoEnCirculo(float dist_eculidea, float radio);
void leerCirculo(struct Tcirculo *circulo);
void escribirPuntos(struct TlistaPuntos *lista);
float calcularDistancia(float x[1], float y[1]);

int main()
{
    int cont, t;
    float x[P], y[P];
    struct TlistaPuntos lista;
    struct Tcirculo circulo;

    leerPuntos(&lista);
    leerCirculo(&circulo);

    t = lista.tam;
    for(cont=0; cont<t; cont++)
    {
        x[0]= lista.puntos[cont].x;
        x[1]= lista.puntos[cont].y;
        y[0]= circulo.centro.x;
        y[1]= circulo.centro.y;
        if(puntoEnCirculo(calcularDistancia(x, y), circulo.radio))
        {
           printf("El punto %f, %f esta dentro del circulo.\n\n", x[0], x[1]);
        }
        else
        {
          printf("El punto %f, %f no esta dentro del circulo.\n\n", x[0], x[1]);

        }
    }
    return 0;
}

void leerCirculo(struct Tcirculo *circulo)
{
    printf("Indique un radio para el circulo: ");
    scanf("%f", &circulo->radio);
    printf("\n");

    printf("Indique un punto central para el circulo\n");
    printf(" Punto x: ");
    scanf("%f", &circulo->centro.x);
    printf(" Punto y: ");
    scanf("%f", &circulo->centro.y);
}

int leerPuntos (struct TlistaPuntos *lista)
{
    FILE *entrada;
    float value;
    int cont=1, contx=0, conty=0;

    entrada=fopen("entrada.txt", "r");
    if(entrada==NULL)
    {
        printf("File not found\n");
        return 1;
    }
    else
    {
        printf("File is found, loading\n");
        fscanf(entrada, "%f", &value);
        while(!feof(entrada))
        {
            if(cont%2!=0)
            {
                //printf("x at %d == %f\n", cont, value);
                lista->puntos[contx].x=value;
                contx++;
            }
            if(cont%2==0)
            {
                //printf("y at %d == %f\n", cont, value);
                lista->puntos[conty].y=value;
                conty++;
            }
         fscanf(entrada, "%f", &value);
         cont++;
        }
        lista->tam=conty;
    }
    escribirPuntos(lista);
    return 0;
}

void escribirPuntos (struct TlistaPuntos *lista)
{
    int cont;
    for(cont=0; cont<lista->tam; cont++)
    {
        printf("pos[%d] %f | %f\n", cont, lista->puntos[cont].x, lista->puntos[cont].y);
    }
}

float calcularDistancia(float x[1], float y[1])
{
    float x2x1, y2y1, result;
    x2x1=x[1]-x[0];
    y2y1=y[1]-y[0];
    printf("====================\n");
    printf("x2x1: %f-%f=%f\n", x[1], x[0], x2x1);
    printf("x2x1*x2x1 = %f\n", x2x1*x2x1);
    printf("y2y1: %f-%f=%f\n", y[1], y[0], y2y1);
    printf("y2y1*y2y1 = %f\n", y2y1*y2y1);
    printf("x2x1^2+y2y1^2 = %f\n", (x2x1*x2x1)+(y2y1*y2y1));
    result=sqrt(((x2x1*x2x1)+(y2y1*y2y1)));
    printf("El resultado es %f\n", result);
    printf("====================\n\n");
    return result;
}

int puntoEnCirculo(float dist_eculidea, float radio)
{
    // printf("\n%f\n", dist_eculidea);
    // printf("\n%f\n", radio);
    if(dist_eculidea>radio)
        return 0;
    if(dist_eculidea<radio)
        return 1;
}
