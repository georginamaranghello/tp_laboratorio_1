#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 20


int main()
{
    char seguir='s';
    int opcion=0;
    ePersona personas[C];
    inicializarPersonas(personas, C);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        while (opcion < 1 || opcion > 5)
        {
            printf("Entrada no valida. Por favor reingrese una nueva opcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                   altaPersonas(personas, C);
                break;
            case 2:
                    borrarPersonas(personas, C);
                break;
            case 3:
                    listarPersonas (personas, C);
                break;
            case 4:
                    graficoEdades (personas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
