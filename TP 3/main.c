#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"





int main()
{
    char seguir='s';
    int opcion=0;

    eMovie *peli;

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
                agregarPelicula(peli);
                break;
            case 2:
                modificarPelicula(peli);
                break;
            case 3:
                borrarPelicula(peli);
               break;
            case 4:
                generarPagina(peli);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error, por favor ingrese una opcion correcta:");
                break;
        }
    }

    return 0;
}
