#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[900];
    int puntaje;
    int estado;
    char linkImagen[150];
}EMovie;

/** \brief Inicializa el campo estado de la estructura para saber si esta vacio o no
 * \param array a inicializar con valor 0 en campo estado
 * \param int el largo de la array de estructuras
 * \return Si se pudo realizar devuelve 0, sino -1
 */

int inicializarStruct(EMovie [],int tam);

/**
*\brief Busca un lugar vacio en el array de estructuras
*\param Array de estructura donde buscar
*\param int Recibe el largo de la array de estructuras
*\return indice de lugar vacio si encuentra un lugar vacio y -1 si no lo encuentra
*/


int espacioLibre(EMovie [],int);


/**
 * \brief Verifica si un titulo dado es valido
 * \param char titulo a validar se pasa como parametro.
 * \return un 1 si el string es valido, un numero menor a 0 si no lo es.
 */



int validarTitulo(char titulo[]);

/**
 * \brief Comprueva que la descripcion sea valida
 * \param variable char donde se va a copiar la descripcion si es valido
 *
 */

int validarDescripcion(char descripcion[]);

/**
 * \brief Comprueva que el link sea valido
 * \param variable  char donde se va a copiar el link si es valido
 *
 */

int validarLink(char Link[]);

/**
 * \brief Muestra los datos cargados en el array movie
 * \param array de peliculas
 * \param int el largo de la array de estructuras
 */

void mostrarMovies(EMovie[], int);


/**
 * \brief Guarda los datos cargados en el array en un archivo
 * \param movie array de la estructura de peliculas
 * \param int el largo de la array de estructuras
 */
void saveBin(EMovie [], int );

/**
 * \brief Lee los datos del archivo y los copia en el array de peliculas
 * \param movie array de la estructura de peliculas
 * \param int el largo de la array de estructuras
 */

void readBin(EMovie [], int );


 /** \brief busca pelicula por titulo
  * \param movie array de la estructura de peliculas
  * \param lenght cantidad de peliculas máximas
  * \return la posicion de la pelicula encontrada como indice o -1 si no encuentra la pelicula
  *
  */


int buscarPorTitulo(EMovie [],int );


/**
 * \brief Agrega una pelicula al archivo binario
 * \param movie la estructura a ser agregada al archivo
 * \param param int el largo de la array de estructuras
 */


void agregarPelicula(EMovie [], int);


/**
 * \brief Modificar campo de pelicula
 * \param movie array de la estructura de peliculas
 * \param int el largo de la array de estructuras
 */

void modificarPelicula(EMovie [], int);

/**
 *  \brief Borra una pelicula del archivo binario
 *  \param movie la estructura a ser eliminada al archivo
 *  \return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula(EMovie [], int);

/**
 *  \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param lista la lista de peliculas a ser agregadas en el archivo.
 *  \param int el largo de la array de estructuras.
 */
void generarPagina(EMovie [], int);

#endif // FUNCIONES_H_INCLUDED
