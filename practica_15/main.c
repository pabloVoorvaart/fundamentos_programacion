#include <stdio.h>
#include <stdlib.h>

#define N 80

struct persona{
    int longNombre;
    int longTelefono;
	char nombre[20];		// Nombre de pila, no hay nombres repetidos
	char telefono[10];	// nº de telefono
};
struct listin{
	int longitud;            //cantidad de valores que hay en el  vector datos
	struct persona datos[N]; // vector datos
};

 int buscarContacto(struct listin vector_personas);
 void anadirContacto(struct listin *vector_personas, int length);
// void eliminarContacto();
int leerAgenda(struct listin *vector_personas);
void escribirAgenda(struct listin vector_personas);

int main()
{
    struct listin vector_personas;
    int opcion;
    printf("La genda 1.0\n");
    leerAgenda(&vector_personas);

    while(opcion=!0)
    {
        printf("\n");
        printf("\t 1. Elegir agenda.\n");
        printf("\t\t2.Buscar contacto.\n");
        printf("\t\t3.Añadir contacto.\n");
        printf("\t\t4.Eliminar contacto.\n");
        printf("\t 5. Unir agenda.\n");
        printf("\t 0. Finalizar.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        if(opcion==1)
        {
            printf("La agenda actual es entrada1.txt\n");
            escribirAgenda(vector_personas);
        }
        if(opcion==2)
        {
            if(buscarContacto(vector_personas))
                printf("El nombre introducido existe.\n");
            else
                printf("El nombre introducido no existe.\n");
        }
        if(opcion==3)
        {
            anadirContacto(&vector_personas, vector_personas.longitud);
        }
    }


    return 0;
}

int leerAgenda(struct listin *vector_personas)
{
    FILE *entrada;
    char value;
    int option=0, i=0, c=0;
    entrada=fopen("agenda1.txt", "r");
    if(entrada==NULL)
    {
        printf("File not found\n");
        return 1;
    }
    else
    {
        printf("File is found, loading\n");
        fscanf(entrada, "%c", &value);
        while(!feof(entrada))
        {
            if(option==0&&value!=' ')
            {
                vector_personas->datos[i].nombre[c]=value;
                c++;
                vector_personas->datos[i].longNombre=c;
            }
            if(option==1&&value!=' ')
            {
                vector_personas->datos[i].telefono[c]=value;
                c++;
                vector_personas->datos[i].longTelefono=c;
            }
            if(value=='\n')
            {
                i++;
                option=0;
                c=0;
            }
            if(value==' ')
            {
                option++;
                c=0;
            }
            fscanf(entrada, "%c", &value);

        }
        vector_personas->longitud=i;
        return 0;
    }

}

// void leerAgenda(struct listin *vector_personas)
// {
//         FILE *entrada;
//         char value;
//         int option=0, i=0, c=0;
//         entrada=fopen("agenda1.txt", "r");
//         if(entrada==NULL)
//         {
//             printf("File not found\n");
//         }
//         else
//         {
//             printf("File is found, loading\n");
//             fscanf(entrada, "%c", &value);
//             int i = 0;
//             char nombre;
//             char tlf;
//             while(!feof(entrada))
//             {
//                 fscanf(entrada, "%s %s", &vector_personas -> datos[i].nombre[i], &vector_personas -> datos[i].telefono[i]);
//                 i++;
//             }
//         }
// }

void escribirAgenda(struct listin vector_personas)
{
    int i, c;
    printf("Numero de contactos en la agenda: %d\n", vector_personas.longitud);
    for(i=0;i<vector_personas.longitud;i++)
    {
        for(c=0;c<vector_personas.datos[i].longNombre;c++)
            printf("%c",vector_personas.datos[i].nombre[c]);
        printf(" ");
        for(c=0;c<vector_personas.datos[i].longTelefono;c++)
            printf("%c",vector_personas.datos[i].telefono[c]);
        //printf("\n");
    }
}

int buscarContacto(struct listin vector_personas)
{
    char nombreBusqueda[20];
    int cont=0, i, c;

    printf("Introduzca un nombre y presione enter: ");
    scanf("%s", &nombreBusqueda);
    for(i=0;i<vector_personas.longitud;i++)
    {
        for(c=0;c<vector_personas.datos[i].longNombre;c++)
        {
            if(vector_personas.datos[i].nombre[c]==nombreBusqueda[c])
            {
                cont++;
                if(cont==vector_personas.datos[i].longNombre)
                    return 1;
            }
            else{cont=0;}
        }
    }
    return 0;
}

void anadirContacto(struct listin *vector_personas, int length)
{
    char value;
    int c=0;
    printf("Introduzca un nombre y presione enter: ");
    scanf("%s", &vector_personas -> datos[length+1].nombre);
    vector_personas -> longitud=length+1;
}
