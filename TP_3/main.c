#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define T 10



int main()
{


    EMovie movie[T];
    inicializarStruct(movie,T);
    readBin(movie, T);

    char seguir='s';
    fflush(stdin);
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie, T);
                break;
            case 2:
                modificarPelicula(movie, T);
                break;
            case 3:
                 borrarPelicula(movie, T);
               break;
            case 4:
                generarPagina(movie, T);
                break;
            case 5:
                saveBin(movie, T);
                seguir = 'n';
                break;
                default:
                printf("Error, por favor ingrese una opcion correcta:");
        }
    }

    return 0;
}
