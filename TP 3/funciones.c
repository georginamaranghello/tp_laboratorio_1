#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



int agregarPelicula(eMovie* peli)
{

    FILE *bin;
    peli->flag=0;



        printf("Ingrese el titulo de pelicula:\n");
        fflush(stdin);
        gets(peli->titulo);
        while(strlen(peli->titulo)>50)
        {

            printf("La maxima cantidad de caracteres es 50.\n Reingrese el titulo de la pelicula: ");
            fflush(stdin);
            gets(peli->titulo);
        }
        printf("Ingrese la duracion de pelicula (en minutos) :\n");
        scanf("%d", &peli->duracion);
        while(peli->duracion<1||peli->duracion>300)
        {
            printf("Duracion max 300 min.\n  Vuelva a ingresar la cantidad de minutos: ");
            scanf("%d",&peli->duracion);
        }
        printf("Ingrese el genero:");
        fflush(stdin);
        gets(peli->genero);
        while(strlen(peli->genero)>20)
        {
            printf("La maxima cantidad de caracteres es 20.\n Reingrese el genero de la pelicula: ");
            fflush(stdin);
            gets(peli->genero);
        }
        printf("Ingrese la descripcion de la pelicula:\n");
        fflush(stdin);
        gets(peli->descripcion);
        while(strlen(peli->descripcion)>500);
        {
        printf("Descripcion muy larga. Reingrese la descripcion de la pelicula en menos de 500 caracteres:\n");
        fflush(stdin);
        gets(peli->descripcion);
        }
        printf("Ingrese el puntaje de pelicula (1-100) :\n");
        scanf("%d",&peli->puntaje);
        while(peli->puntaje<1||peli->puntaje>100)
        {

            printf("Reingrese el puntaje entre 1-100 : ");
            scanf("%d",&peli->puntaje);
        }
        printf("Ingrese link de la imagen:\n");
        fflush(stdin);
        gets(peli->linkImagen);


        peli->flag=1;


        bin=fopen("datos.bin", "ab");
          if (bin!=NULL)
        {
            fwrite(&peli,sizeof(eMovie),1,bin);
            printf("Se gurdaron los datos correctamente\n");
        }
        else
        {
            printf("Error al cargar el archivo\n");
            exit(1);
        }

        fclose(bin);

        return 0;

}


int modificarPelicula(eMovie *peli)
{

    int i;
    char resp[50];
    int estado=0;

    printf("Ingrese el titulo de la pelicula que desea modificar:");
    fflush(stdin);
    gets(resp);


     for(i=0;i<20;i++)
    {
        if(strcmp((peli+i)->titulo,resp)==0)
        {

         printf("Ingrese genero");
         fflush(stdin);
         gets((peli+i)->genero);

         printf("Ingrese la duracion");
         scanf("%d",&(peli+i)->duracion);

         printf("Ingrese La descripcion");
         fflush(stdin);
         gets((peli+i)->descripcion);

         printf("Ingrese El puntaje");
         scanf("%d",&(peli+i)->puntaje);

         printf("Ingrese el link de la imagen");
         fflush(stdin);
         gets((peli+i)->linkImagen);

          printf("Pelicula modificada exitosamente");
          estado=1;
        }
    }
    if(estado==0)
    {
         printf("No coincide con ninguna pelicula.");
    }

return estado;

}


int borrarPelicula(eMovie *peli)
{

    FILE *bin;
    char resp[59];
    int found;

    printf("Ingrese el titulo de la pelicula que desea borrar:");

    fflush(stdin);
    gets(resp);
    bin=fopen("datos.bin","rb");

    if(bin!=NULL)
    {
        while((fread(peli,sizeof(eMovie),1,bin))!=0)
        {
            if ((peli->flag==1) && (strcmp(peli->titulo,resp))==0)
            {
                fseek(bin,(-1)*sizeof(eMovie),SEEK_CUR);
                peli->flag=0;
                fwrite(peli,sizeof(eMovie),1,bin);
                found=1;
                printf("Se elimino la pelicula");
                break;
            }
        }
    }

    if(found==0)
    {
        printf("No se encontro la pelicula.");

    }


    else
    {
        printf("No se pudo abrir el archivo.");

    }

    fclose(bin);
    return found;
}


void generarPagina(eMovie *peli)
{

    FILE* html;
    FILE *bin;
    bin=fopen("datos.bin","rb");

    if(bin!=NULL)

    {

       html=fopen("movie.bin","wb");

        if(html!=NULL)

        {
            fprintf(html,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");


             while((fread(peli,sizeof(eMovie),1,bin))!=0)
            {

               if(peli->flag==1)
               {

                    fprintf(html,
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n");
                    fprintf(html,
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n",peli->linkImagen);
                    fprintf(html,
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n",peli->titulo);
                    fprintf(html,
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d minutos</li>\n"
                    "</ul>\n",peli->genero,peli->puntaje,peli->duracion);
                    fprintf(html,
                    "<p>%s</p>\n"
                    " </article>\n",peli->descripcion);
               }

            }

             fprintf(html,
            "</div>\n"
            "</div>\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");
        }

        else
        {
            printf("El archivo no fue cargado");

        }
    }

    printf("Se genero la pagina web");

    fclose(bin);

    fclose(html);



}


















