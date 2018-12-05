#include<stdio.h>
#define N 5
#define M 7

void mostrar_sopa(char sopa[N][M]);
int buscar_palabra_horizontal(char sopa[N][M], char pal[M+1], int fil, int col);
int cad_iguales (char pal1[], char pal2[]);
int longitud_pal (char pal[]);

int main()
{
    int fila, columna;
    char pal[M];

    char sopa[N][M] =
    {
        'A', 'A', 'P', 'E', 'P', 'A', 'P',
        'B', 'N', 'O', 'T', 'R', 'P', 'Y',
        'P', 'E', 'P', 'E', 'P', 'E', 'W',
        'A', 'P', 'E', 'P', 'I', 'T', 'A',
        'E', 'T', 'O', 'P', 'E', 'P', 'Y',
    };


    mostrar_sopa(sopa);

    printf("\nIntroduce (en mayusculas) una palabra de %d letras como maximo: ", M);
    gets(pal);

    for(fila=0; fila<N; fila++)
    {
        for(columna=0; columna<M; columna++){
            if(buscar_palabra_horizontal(sopa, pal, fila, columna) == 1){
                printf("\nFila [%d] Columna [%d] derecha\n", fila+1, columna+1);
            }
            else if(buscar_palabra_horizontal(sopa, pal, fila, columna) == 2){
                printf("\nFila [%d] Columna [%d] izquierda\n", fila+1, columna+longitud_pal(pal));
            }
            }
        }
    return 0;
}

int longitud_pal (char pal[M])
{
    int i;

    for(i=0; pal[i] != '\0'; i++);

    return i;
}

// devuelve: 1 si son iguales y 0 si no lo son
int cad_iguales (char pal1[M], char pal2[M])
{
    int i, encontrada=1;

    for(i=0; pal1[i]!='\0' && pal2[i]!='\0' && encontrada; i++)
    {
        if(pal1[i]!=pal2[i])
            encontrada=0;
    }

    return encontrada;
}

//Función que permite al usuario mostrar la sopa de letras centrada
void mostrar_sopa(char sopa[N][M])
{
    int i, j;
    printf("\t\t\t\tSOPA DE LETRAS\n");
    for(i=0; i<N; i++)
    {
        printf("\t\t\t");

        for(j=0; j<M; j++)
            printf("%4c", sopa[i][j]);
        printf("\n");
    }
}

//Busca la palabra horizontalmente a partir de una posición de la matriz que recibe como parametro
//Devuelve 0 si no la ha encontrado, 1 si la encuentra de izquierda a derecha y 2 si la encuentra de derecha a izquierda
int buscar_palabra_horizontal(char sopa[N][M], char pal[M+1], int fil, int col)
{
    int i, resul=1, resul2=2;

    char pal2[M+1]="", pal3[M+1]="";

    if (M-col<longitud_pal(pal))
       return 0;

    for(i=0; pal[i]!='\0'; i++)
        pal2[i]=sopa[fil][col+i];

    for(i=0; pal[i]!='\0'; i++)
        pal3[i]=pal2[longitud_pal(pal2)-i-1];


    if (cad_iguales(pal, pal2))
        resul=1;
    else if (cad_iguales(pal, pal3))
        resul=2;
    else resul = 0;

    return resul;
}
