#include <stdio.h>
#include <stdlib.h>

int main()
{
/*  Codificar  un programa C,   que lea un carácter y
    si coincide con la inicial de tu nombre escribe ‘Coincide’
    y si no coincide escribe ‘No coincide’.
*/
    char* nombre = "Pablo";
    char str1[1];
    printf("¿Eres gay? Si lo eres escribe tu primera letra:");
    scanf("%s", str1);


    printf("%d\n", nombre[0]);
    return 0;
}
