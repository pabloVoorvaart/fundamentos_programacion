#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*  Codificar  un programa C,   que lea un carácter y
        si coincide con la inicial de tu nombre escribe ‘Coincide’
        y si no coincide escribe ‘No coincide’.
    */
    char* nombre = "Pablo";
    char letra;
    printf("Escribe tu primera letra: ");
    scanf("%c", &letra);
    if(letra == nombre[0])
    {
        printf("Coincide");
    }
    else
    {
        printf("No coincide");
    }
    return 0;
}

