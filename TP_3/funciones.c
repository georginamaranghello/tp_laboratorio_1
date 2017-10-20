#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"




int inicializarStruct(EMovie movie[],int tam)
{
    int i;
    int retorno=-1;

    for (i=0; i<tam; i++)
    {
        movie[i].estado=0;
        retorno=0;
    }
    return retorno;
}


int espacioLibre(EMovie movie[],int tam)
{
    int i;
    int retorno=-1;

    for (i=0; i<tam; i++)
    {
        if(movie[i].estado==0)
        {
            retorno=i;
            break;
        }
    }

    return retorno;

}


void agregarPelicula(EMovie movie[], int tam)
{

    FILE* movies;
    int pos;
    char tituloAux[50], generoAux[20], descripAux[900], linkAux[150];

    pos=espacioLibre(movie,tam);

    if(pos!=-1)

    {

        printf("Ingrese el titulo: ");
        fflush(stdin);
        gets(tituloAux);

        while(validarTitulo(tituloAux) < 0)
        {

            printf("ERROR: Ingrese un titulo valido: ");
            fflush(stdin);
            gets(tituloAux);
        }

        strcpy(movie[pos].titulo, tituloAux);

        printf("Ingrese el genero: ");
        fflush(stdin);
        gets(generoAux);

        while( (strlen(descripAux)) < 0 || (strlen(descripAux)) > 20)
        {
            printf("ERROR: EL genero no puede tener mas de 20 caracteres: ");
            fflush(stdin);
            gets(generoAux);
        }
        strcpy(movie[pos].genero, generoAux);

        printf("Ingrese la duracion de la pelicula en minutos: ");

        scanf("%d", &movie[pos].duracion);

        while( movie[pos].duracion < 0 || movie[pos].duracion > 300 )
        {
            printf("ERROR: Ingrese una duracion valida (entre 0 y 300 minutos): ");
            scanf("%d", &movie[pos].duracion);

        }

        printf("Ingrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets(descripAux);

        while( validarDescripcion(descripAux) < 0)
        {
            printf("ERROR: Ingrese una descripcion valida: ");
            fflush(stdin);
            gets(descripAux);
        }

        strcpy(movie[pos].descripcion, descripAux);

        printf("Ingrese el puntaje de la pelicula del 1 al 10: ");
        scanf("%d", &movie[pos].puntaje);

        while(movie[pos].puntaje < 1 || movie[pos].puntaje > 10)
        {
            printf("ERROR: Ingrese un puntaje valido (entre 1 y 10): ");
            scanf("%d", &movie[pos].puntaje);
        }

        printf("Ingrese el link de la imagen: ");
        fflush(stdin);
        gets(linkAux);

        while(validarLink(linkAux)< 0)
        {
            printf("ERROR: Ingrese un link de imagen valido: ");
            gets(linkAux);
            fflush(stdin);
        }
        strcpy(movie[pos].linkImagen, linkAux);

        movie[pos].estado=1;
    }

    else
    {

        printf("No hay mas espacio para seguir cargando peliculas\n");
    }

    printf("titulo: %s , genero: %s ,duracion: %d ,puntaje: %d, link imagen: %s\n ",movie[pos].titulo,movie[pos].genero,movie[pos].duracion,movie[pos].puntaje, movie[pos].linkImagen);


     if((movies = fopen("movies", "a+b"))==NULL)
        {
            printf("No existe el archivo\n");
        }
        else
        {
            fwrite(movie, sizeof(movie), 2, movies);
            fclose(movies);
        }
}


int validarTitulo(char titulo[])
{
    if (titulo[0] == '\n')
    {
        printf("ERROR: El titulo esta vacio.\n");
        return -1;
    }
    else if (strlen(titulo)>50)
    {
        printf("ERROR: El titulo no puede tener mas de 50 caracteres (49 letras + el \\0).\n");
        return -2;
    }
    else
    {
        return 1;
    }
}


int validarDescripcion(char descripcion[])
{

    if (descripcion[0] == '\n')
    {
        printf("ERROR: La descripcion no puede ser vacio.\n");
        return -1;
    }
    else if (strlen(descripcion)> 900)
    {
        printf("ERROR: La descripcion no puede tener mas de 900 caracteres.\n");
        return -2;
    }

    else
    {
        return 1;
    }
}


int validarLink(char link[])
{

    if (link[0] == '\n')
    {
        printf("ERROR: El link no puede estar vacio.\n");
        return -1;
    }
    else if (strlen(link)>150)
    {
        printf("ERROR: El link no puede tener mas de 150 caracteres.\n");
        return -2;
    }

    else
    {
        return 1;
    }
}

void mostrarMovies(EMovie movie[], int tam)
{
    int i;


    printf("\n*****************PELICULAS********************\n");


    for(i = 0; i <tam; i++)
    {
        if(movie[i].estado == 1)
        {
            printf("\nTITULO:%s\nDURACION:%s\nGENERO:%d\nDESCRIPCION:%s\nPUNTAJE:%d\nLINK DE IMAGEN:%s\n",movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion,movie[i].puntaje, movie[i].linkImagen);
        }
    }
    printf("\n\n");

}


int buscarPorTitulo(EMovie movie[], int tam)
{
    int i;
    int indice;
    char tituloAux[50];

    printf("Ingrese el titulo a buscar:");
    fflush(stdin);
    gets(tituloAux);

    for(i = 0; i < tam; i++)
    {
        if(strcmpi(movie[i].titulo, tituloAux)==0)

        {
            printf("Pelicula encontrada");
            printf("%s - %s - %d - %s - %d\n", movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion, movie[i].puntaje);
           indice=0;
            break;
        }
        else{

            printf("Pelicula no encontrada");
            indice=-1;
        }

    }

        return indice;
}


void borrarPelicula(EMovie movie[], int tam)
{
    int i;
    char resp;
    char tituloAux[50];

    mostrarMovies(movie, tam);

    printf("Ingrese el titulo a eliminar:");
    fflush(stdin);
    gets(tituloAux);

    for(i = 0; i < tam; i++)
    {
        if(strcmpi(movie[i].titulo, tituloAux)==0 && movie[i].estado==1)

        {
            printf("Pelicula encontrada\n");
            printf("%s - %s - %d - %s - %d\n", movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion, movie[i].puntaje);

            printf("Desea borrar esta pelicula? s/n\n");
            scanf("%c", &resp);

            if(resp=='s')

            {
                movie[i].estado=0;
                printf("Pelicula borrada\n");
            }
            else{

                printf("Accion cancelada\n");
            }
        }
        else
        {

            printf("Pelicula no encontrada");

        }

    }
}

void modificarPelicula(EMovie movie[], int tam)
{

    int i;
    char tituloAux[50], generoAux[20], descripAux[900], linkAux[150];

    mostrarMovies(movie, tam);


    printf("Ingrese el titulo a buscar:");
    fflush(stdin);
    gets(tituloAux);

    for(i = 0; i < tam; i++)
    {
        if(strcmpi(movie[i].titulo, tituloAux)==0 && movie[i].estado==1)

        {
            printf("Pelicula:\n");
            printf("%s - %s - %d - %s - %d\n", movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion, movie[i].puntaje);


            printf("Ingrese el nuevo titulo: ");
            fflush(stdin);
            gets(tituloAux);

            while(validarTitulo(tituloAux) < 0)
            {

                printf("ERROR: Ingrese un titulo valido: ");
                fflush(stdin);
                gets(tituloAux);
            }

            strcpy(movie[i].titulo, tituloAux);

            printf("Ingrese el nuevo genero: ");
            fflush(stdin);
            gets(generoAux);

              while( (strlen(descripAux)) < 0 || (strlen(descripAux)) > 20)
            {
                printf("ERROR: EL genero no puede tener mas de 20 caracteres: ");
                fflush(stdin);
                gets(generoAux);
            }
            strcpy(movie[i].genero, generoAux);

            printf("Ingrese la duracion de la pelicula en minutos: ");

            scanf("%d", &movie[i].duracion);

            while( movie[i].duracion < 0 || movie[i].duracion > 300 )
            {
                printf("ERROR: Ingrese una duracion valida (entre 0 y 300 minutos): ");
                scanf("%d", &movie[i].duracion);

            }

            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(descripAux);

            while( validarDescripcion(descripAux) < 0)
            {
                printf("ERROR: Ingrese una descripcion valida: ");
                fflush(stdin);
                gets(descripAux);
            }

            strcpy(movie[i].descripcion, descripAux);

            printf("Ingrese el puntaje de la pelicula del 1 al 10: ");
            scanf("%d", &movie[i].puntaje);

            while(movie[i].puntaje < 1 || movie[i].puntaje > 10)
            {
                printf("ERROR: Ingrese un puntaje valido (entre 1 y 10): ");
                scanf("%d", &movie[i].puntaje);

            }


            printf("Ingrese el link de la imagen: ");
            fflush(stdin);
            gets(linkAux);

            while(validarLink(linkAux)< 0)
            {
                printf("ERROR: Ingrese un link de imagen valido: ");
                gets(linkAux);
                fflush(stdin);

            }

            strcpy(movie[i].linkImagen, linkAux);


            printf("Pelicula:\n");
            printf("%s - %s - %d - %s - %d\n", movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion, movie[i].puntaje);
        }
        else
        {

            printf("Pelicula no encontrada");

        }

    }
}



void saveBin(EMovie movie[], int tam)
{
    FILE *f;

    f = fopen("movies.dat", "wb");

    if(f == NULL)
    {
        printf("ERROR, no se puede abrir archivo.");
        exit(1);
    }

    fwrite(movie, sizeof(movie), tam, f);

    fclose(f);
}


void readBin(EMovie movie[], int tam)
{
    FILE* f;

    f = fopen("movies.dat", "rb");

    if(f == NULL)
    {
        f = fopen("movies.dat", "wb");

        if(f == NULL)
        {
           printf("ERROR, no se puede abrir archivo.");
            exit(1);
        }

    }

    fread(movie, sizeof(movie), tam, f);

    fclose(f);
}


void generarPagina(EMovie movie[], int tam)
{
    FILE* pFile;
    int i;

    pFile = fopen("Peliculas.html", "a");

    if(pFile == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    for(i = 0; i < tam; i++)
    {
        if(movie[i].estado == 1)
        {
            fprintf(pFile, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''>", movie[i].linkImagen);
            fprintf(pFile, "</a><h3><a href='#'>%s</a></h3><ul>", movie[i].titulo);
            fprintf(pFile, "<li>Género:%s</li>", movie[i].genero);
            fprintf(pFile, "<li>Puntaje:%d</li>", movie[i].puntaje);
            fprintf(pFile, "<li>Duracion:%d</li></ul>", movie[i].duracion);
            fprintf(pFile, "<p>%s</p></article>", movie[i].descripcion);
        }

    }

    fclose(pFile);

}


