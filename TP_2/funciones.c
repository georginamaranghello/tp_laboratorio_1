#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(ePersona personas[], int lenght)
{
    int i;
    int indice = -1;
     for (i=0; i<20; i++)
     {

         if (personas[i].estado = 0)

         {
             indice = i;
             break;
         }

     }

     return indice;
}


void inicializarPersonas (ePersona personas[], int lenght)
{
    int i;
     for (i=0; i<20; i++)
     {
         personas[i].estado = 0;
     }
}
int buscarPorDni(ePersona personas[], long dni)

{

    int indice=0,i;
    long auxDni;
    printf("Ingrese el DNI a encontrar: ");
    scanf("%ld",&auxDni);


    for(i=0;i<20;i++)
    {
        if (auxDni==personas[i].dni)
        {
            indice=i;
            break;
        }

    }
    return indice;


}




void altaPersonas (ePersona personas[], int lenght)
{
                    int flag=0;
                    int i;
                    for (i=0; i<20; i++)

                    {
                        if (personas[i].estado == 0)

                        {
                            printf("\nIngrese el nombre: ");
                            fflush(stdin);
                            gets(personas[i].nombre);
                            printf("Ingrese la edad: ");
                            scanf("%d", &personas[i].edad);
                            printf("Ingrese el DNI: ");
                            scanf("%ld", &personas[i].dni);
                            personas[i].estado=1;

                            flag =1;
                            break;
                        }

                    }
                    if (flag==0)
                    {
                        printf("\nNo hay mas capacidad para guardar entradas");
                    }

}



void borrarPersonas (ePersona personas[], int lenght)
{
            int flag=0, auxInt, i;
            char respuesta;
            printf("Ingrese el dni de la persona que desea eliminar: ");
            scanf("%d", &auxInt);


            for(i=0; i<20; i++)
            {
                if(personas[i].estado==1 && auxInt == personas[i].dni)
                {

                    printf("El registro que desea borrar es : \n| %d  | %s | %ld |",personas[i].edad,personas[i].nombre,personas[i].dni);

                    printf("Esta seguro de eliminar? s/n");
                    respuesta = getche();

                    if(respuesta=='s')
                    {
                        personas[i].estado=0;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario");
                    }
                   flag=1;
                break;
                }
            }
            if(flag==0)
            {
                printf("El dni es inexistente.");
            }

}
void listarPersonas (ePersona personas[], int lenght)
{

    int i, j;
    ePersona auxPersona;

    for(i=0; i<19; i++)
    {
        for(j=i+1; j<20; j++)
        {
            if((strcmp(personas[i].nombre,personas[j].nombre))>0)
            {
                auxPersona = personas[i];
               personas[i] = personas[j];
                personas[j] = auxPersona;
            }
        }
    }

 for(i=0;i<20; i++)
    {
        if(personas[i].estado==1)
            printf("Nombre: %s  DNI: %ld  edad:  %d\n",personas[i].nombre, personas[i].dni,personas[i].edad);
    }
}

void graficoEdades (ePersona personas[])
{

int menor=0, intermedio=0, mayor=0, i, maximo=0, flag=0;

for (i=0; i<20; i++)
{
    if (personas[i].estado==1)

    {
        if (personas[i].edad < 19)

        {
            menor++;
        }

        if (personas[i].edad > 18 && personas[i].edad < 36)
        {
            intermedio++;
        }

       if (personas[i].edad>35)
        {
            mayor++;

        }

    }
}


if (menor> intermedio && menor > mayor)

{
    maximo = menor;
}

else if (intermedio > menor && intermedio > mayor)
{
    maximo = intermedio;
}
else {

    maximo = mayor;
}

for (i = maximo; i>0; i--)
{
    if(i<= menor)
        {
            printf("*");
        }
        if(i<= intermedio)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayor)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }

        printf("\n");
}
printf("--+-----------------");
printf("\n  |<18\t19-35\t>35 \n");

}

