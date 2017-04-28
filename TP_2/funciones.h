#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    long dni;
    int estado;


}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int lenght);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], long dni);

/** \brief inicializa el array
 *
 * \param el array en el cual buscar
 * \param indica la longitud del array
 * \return --
 */


void inicializarPersonas (ePersona personas[], int lenght);



/** \brief carga los datos de la estructura
 *
 * \param se pasa el array
 * \param la longitud del array
 * \return --
 *
 */


void altaPersonas (ePersona personas[], int lenght);


/** \brief borra uno o varios elementos del array
 *
 * \param el array
 * \param la longitud del mismo
 * \return --
 *
 */


void borrarPersonas (ePersona personas[], int lenght);



/** \brief ordena alfabeticamente el array
 *
 * \param el array en el cual buscar
 * \param la longitud del marray
 * \return
 *
 */


void listarPersonas (ePersona personas[], int lenght);


/** \brief imprime en pantalla un grafico por edades
 *
 * \param array
 * \param la longitud del array
 * \return
 *
 */


void graficoEdades (ePersona personas[]);




#endif // FUNCIONES_H_INCLUDED
