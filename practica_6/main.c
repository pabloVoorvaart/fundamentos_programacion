#include <stdio.h>
#include <stdlib.h>

//Funciones
float factorial(int);
float potencia(int base, int exponente);
int fibonacci(int);
int comprobar(char nombre[]);
int menu();

int main()
{
    printf("Bienvenido, por favor selecione una opcion:");
    while(menu() == 1) {}
    return 0;
}


int menu()
{
    int opcion_menu;
    int base_opcion_1;
    int base_opcion_2;
    int potencia_opcion_2;


    printf("\n 1) Realizar factorial de un numero.\n 2) Realizar potencia de un numero. \n 3) Realizar serie de fibonacci.\n 0) Salir.\n");
    scanf("%d", &opcion_menu);
    if (opcion_menu > 3 || opcion_menu < 0)
    {
        printf("Esa opcion no es valida, por favor elija una entre 1-3\n");
        return 1;
    }

    if (opcion_menu == 1)
    {
        printf("Por favor, intrduzca el numero con el que desarollar el factorial.\n");
        base_opcion_1 = comprobar("Factorial");
        printf("El resultado es: %f", factorial(base_opcion_1));

    }


    if (opcion_menu == 2)
    {
        printf("Por favor, introduzca la base y la potencia a ejectuar.\n");
        base_opcion_2 = comprobar("Base");
        potencia_opcion_2 = comprobar("Potencia");
        printf("El resultado es: %f\n", potencia(base_opcion_2, potencia_opcion_2));
        return 1;
    }

    if (opcion_menu == 0)
    {
        printf("Exiting......");
        return 0;
    }
    return 0;
}


int comprobar(char nombre[])
{
    int numero;
    int check = 0;
    printf("%s: ", nombre);
    scanf("%d", &numero);
    while (check == 0)
    {
        if (numero < 0 || numero > 20)
        {
            printf("Numero invalido, por favor introduzca un muero entre 1, 20\n");
            printf("%s: "), nombre;
            scanf("%d", numero);
            check=0;
        }
        else
        {
            check=1;
        }
    }
    return numero;
}

float potencia(int base, int exponente)
{
    int contador=1;
    int base_p=base;
    while(contador != exponente)
    {
        base = base*base_p;
        contador ++;
    }
    return base;
}

float factorial(int base)
{
    int contador=0;
    int current_value = base;
    int current_base = base;

    while(contador!=base)
    {
        if (current_base== 1)
        {
            contador=base;
        }
        else
        {
            current_value = current_value*(current_base-1);
            current_base = current_base -1;
            contador++;
        }
    }
    return current_value;
}
